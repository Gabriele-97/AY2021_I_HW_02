/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "project.h"
#include "Driver.h"

/* this function is aimed to set the PWM parameters needed to obtain the patterns specified*/


void RGBLed_WriteColor(uint16_t period, char modeR, char modeG, int compareR, int compareG ){
            if (flag>0){
                DC7 = PWM__B_PWM__GREATER_THAN ;
            }
            if (flag<0){ 
                DC7 = PWM__B_PWM__LESS_THAN;
            } //this is needed for pattern 7. After each period the compare mode of red line is switched
            PWM_WritePeriod(period); //set the period
            PWM_SetCompareMode1(modeR); //set the mode of red line
            PWM_WriteCompare1(compareR);// set the compare value of red line
            PWM_SetCompareMode2(modeG);// set mode of green line
            PWM_WriteCompare2(compareG); //set compare value of green line
           
            CyDelayUs(10); //general delay before the beginning of a new cycle (not noticible by bare eye)
}
/* [] END OF FILE */
