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
#include "InterruptRoutines.h"
int state =6;

CY_ISR(press_button_ISR) ;




int main(void)
{   
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    PWM_Start();
    isr_debounce_StartEx(press_button_ISR);
    
   
    
    
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
       /* if(Button_Read() == 0) {
            state ++;
            if (state == 8)
                state = 1;
            while (Button_Read()==0);
            CyDelayUs(500);
         }*/
        
        switch(state){
            case 1:
            PWM_WritePeriod(1999);
            PWM_SetCompareMode1(PWM__B_PWM__GREATER_THAN_OR_EQUAL_TO);
            PWM_SetCompareMode2(PWM__B_PWM__GREATER_THAN_OR_EQUAL_TO);
            PWM_WriteCompare1(0);
            PWM_WriteCompare2(0);
            break;
            
            case 2:
            PWM_WritePeriod(1999);
            PWM_SetCompareMode1(PWM__B_PWM__GREATER_THAN);
            PWM_SetCompareMode2(PWM__B_PWM__GREATER_THAN);
            PWM_WriteCompare1(1000);
            PWM_WriteCompare2(1999);
            break;
            
            case 3: 
            PWM_WritePeriod(1999);
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
            break;
            
            case 6:
            PWM_WritePeriod(1999);
            PWM_SetCompareMode1(PWM__B_PWM__GREATER_THAN);
            PWM_SetCompareMode2(PWM__B_PWM__GREATER_THAN);
            PWM_WriteCompare1(1500);
            PWM_WriteCompare2(1000);
            CyDelayUs(500);
            break;
            
            case 7:
            PWM_WritePeriod(1000);
            if(PWM_ReadStatusRegister() == PWM_STATUS_TC){
                if (PWM_ReadCompare1() == PWM__B_PWM__LESS_THAN){
                    PWM_SetCompareMode1(PWM__B_PWM__GREATER_THAN);
                    PWM_WriteCompare1(1000);
                    PWM_SetCompareMode2(PWM__B_PWM__LESS_THAN);
                    PWM_WriteCompare2(500);
                }
                if(PWM_ReadCompare1() == PWM__B_PWM__GREATER_THAN){
                    PWM_SetCompareMode1(PWM__B_PWM__LESS_THAN);
                    PWM_WriteCompare1(1000);
                    PWM_SetCompareMode2(PWM__B_PWM__LESS_THAN);
                    PWM_WriteCompare2(500);
                
               }
            
            
           
            CyDelayUs(10);
            }
            break;
        }
    
        
        
    }
}

/* [] END OF FILE */
