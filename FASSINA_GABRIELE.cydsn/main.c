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
#include "RGBLedDriver.h"
#include "colors.h"

extern char state;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    PWM_Start();
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        switch(state){
            case 1:
            PWM_WritePeriod(1999);
            PWM_SetCompareMode1(PWM__B_PWM__LESS_THAN);
            PWM_SetCompareMode2(PWM__B_PWM__LESS_THAN);
            PWM_WriteCompare1(1999);
            PWM_WriteCompare2(1999);
            break;
            
            case 2: 
            PWM_SetCompareMode1(PWM__B_PWM__LESS_THAN);
            PWM_SetCompareMode2(PWM__B_PWM__GREATER_THAN);
            PWM_WriteCompare1(1999);
            PWM_WriteCompare2(1000);
            break;
            
            case 3: 
            PWM_SetCompareMode1(PWM__B_PWM__LESS_THAN);
            PWM_SetCompareMode2(PWM__B_PWM__LESS_THAN);
            PWM_WriteCompare1(1000);
            PWM_WriteCompare2(1999);
            break;
            
            case 4: 
            PWM_WritePeriod(999);
            PWM_SetCompareMode1(PWM__B_PWM__GREATER_THAN);
            PWM_SetCompareMode2(PWM__B_PWM__LESS_THAN);
            PWM_WriteCompare1(500);
            PWM_WriteCompare2(500);
            break;
            
            case 5:
            PWM_WritePeriod(499);
            PWM_SetCompareMode1(PWM__B_PWM__LESS_THAN);
            PWM_SetCompareMode2(PWM__B_PWM__GREATER_THAN);
            PWM_WriteCompare1(250);
            PWM_WriteCompare2(250);
            
            case 6:
            PWM_WritePeriod(1999);
            PWM_SetCompareMode1(PWM__B_PWM__GREATER_THAN);
            PWM_SetCompareMode2(PWM__B_PWM__GREATER_THAN);
            PWM_WriteCompare1(500);
            PWM_WriteCompare2(1000);
            
            case 7:
            PWM_WritePeriod(1000);
            if((PWM_ReadStatusRegister()<<PWM_STATUS_TC) == 1){
            if (PWM_ReadCompare1()==PWM__B_PWM__GREATER_THAN){
                PWM_SetCompareMode1(PWM__B_PWM__LESS_THAN);
            }
            else 
                PWM_SetCompareMode1(PWM__B_PWM__GREATER_THAN);
            }
            PWM_SetCompareMode2(PWM__B_PWM__GREATER_THAN);
            PWM_WriteCompare1(1000);
            PWM_WriteCompare2(500);
            break;
        }
        
        
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
