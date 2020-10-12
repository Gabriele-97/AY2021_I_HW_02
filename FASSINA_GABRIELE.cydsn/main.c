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
#include "Driver.h"

int state = 1; //defines the pattern
int DC7 = PWM__B_PWM__LESS_THAN; //initialization of the last pattern
int flag =1; //needed to set the values of the last pattern

CY_ISR(press_button_ISR) ; 





int main(void)
{   
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    PWM_Start(); //activate  PWM
    
    isr_debounce_StartEx(press_button_ISR); //activate ISR when the button is pressed
    
    for(;;)
    {
       /*the state is initialized to 1 and it is incremented as the user presses the button
       the generation of the pattern is obrained by properly setting the PWM parameters through the driver function
        when the LED has some off times, a delay is introduced to assure that it turns off 
       delays have been introduced also in patterns involving red colour because I've noticed that without it the red blinks. 
       */
        switch(state){
            case 1:
            RGBLed_WriteColor(1999, PWM__B_PWM__GREATER_THAN_OR_EQUAL_TO, PWM__B_PWM__GREATER_THAN_OR_EQUAL_TO,1999,1999);
            break;
            
            case 2:
            RGBLed_WriteColor(1999, PWM__B_PWM__LESS_THAN_OR_EQUAL, PWM__B_PWM__GREATER_THAN,0,999);
            CyDelayUs(90);
            break;
            
            case 3: 
            RGBLed_WriteColor(1999, PWM__B_PWM__LESS_THAN, PWM__B_PWM__GREATER_THAN_OR_EQUAL_TO,1000,1999);
            break; 
            
            case 4: 
            RGBLed_WriteColor(999, PWM__B_PWM__GREATER_THAN, PWM__B_PWM__LESS_THAN,500,500);
            CyDelayUs(100);
            break;
            
            case 5:
            RGBLed_WriteColor(500, PWM__B_PWM__LESS_THAN, PWM__B_PWM__GREATER_THAN,250,250);
            CyDelayUs(100);
            break;
            
            case 6:
            RGBLed_WriteColor(1999, PWM__B_PWM__LESS_THAN, PWM__B_PWM__LESS_THAN,500,1000);
            CyDelayUs(500);
            break;
            
            case 7:
            RGBLed_WriteColor(999, DC7, PWM__B_PWM__LESS_THAN,999,500);
            while (PWM_ReadCounter() > 0); //I wait for a period
            flag = -flag; //I switch the compare mode 
            break;
        }
    
      
    }
}

/* [] END OF FILE */
