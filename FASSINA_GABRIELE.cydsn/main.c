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

int state =1;

CY_ISR(press_button_ISR) ;




int main(void)
{   
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    PWM_R_Start();
    PWM_G_Start();
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
            PWM_R_WritePeriod(499);
            PWM_G_WritePeriod(499);
            PWM_R_SetCompareMode(PWM_R__B_PWM__LESS_THAN_OR_EQUAL);
            PWM_R_WriteCompare(499);
            PWM_G_SetCompareMode(PWM_G__B_PWM__LESS_THAN_OR_EQUAL);
            PWM_G_WriteCompare(499);
            break;
            
            case 2:
            PWM_R_WritePeriod(1999);
            PWM_G_WritePeriod(1999);
            PWM_R_SetCompareMode(PWM_R__B_PWM__LESS_THAN);
            PWM_R_WriteCompare(1999);
            PWM_G_SetCompareMode(PWM_G__B_PWM__LESS_THAN);
            PWM_G_WriteCompare(1000);
            break;
            
            case 3: 
            PWM_R_WritePeriod(1999);
            PWM_G_WritePeriod(1999);
            PWM_R_SetCompareMode(PWM_R__B_PWM__LESS_THAN);
            PWM_R_WriteCompare(1000);
            PWM_G_SetCompareMode(PWM_G__B_PWM__GREATER_THAN);
            PWM_G_WriteCompare(1999);
            break;
            
            case 4: 
            PWM_R_WritePeriod(999);
            PWM_G_WritePeriod(999);
            PWM_R_SetCompareMode(PWM_R__B_PWM__LESS_THAN);
            PWM_R_WriteCompare(500);
            PWM_G_SetCompareMode(PWM_G__B_PWM__GREATER_THAN);
            PWM_G_WriteCompare(500);
            break;
            
            case 5:
            PWM_R_WritePeriod(500);
            PWM_G_WritePeriod(500);
            PWM_R_SetCompareMode(PWM_G__B_PWM__GREATER_THAN);
            PWM_R_WriteCompare(250);
            PWM_G_SetCompareMode(PWM_R__B_PWM__LESS_THAN);
            PWM_G_WriteCompare(250);
            break;
            
            case 6:
            PWM_R_WritePeriod(1999);
            PWM_G_WritePeriod(1999);
            PWM_R_SetCompareMode(PWM_R__B_PWM__GREATER_THAN);
            PWM_R_WriteCompare(500);
            PWM_G_SetCompareMode(PWM_R__B_PWM__GREATER_THAN);
            PWM_G_WriteCompare(1000);
            CyDelayUs(500);
            break;
            
            case 7:
            PWM_R_WritePeriod(1999);
            PWM_G_WritePeriod(999);
            PWM_R_SetCompareMode(PWM_R__B_PWM__GREATER_THAN);
            PWM_R_WriteCompare(999);
            PWM_G_SetCompareMode(PWM_G__B_PWM__LESS_THAN);
            PWM_G_WriteCompare(500);
            CyDelayUs(500);
            break;
        }
    
        
        
    }
}

/* [] END OF FILE */
