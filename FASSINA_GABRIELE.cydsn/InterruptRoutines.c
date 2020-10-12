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
#include "InterruptRoutines.h"


CY_ISR(press_button_ISR) {
        
        //this is activated when the button is pressed
        //debouncing is done via deidcated component
        state ++;
        if (state == 8){
            state = 1;
        //if the state gets to the last available pattern, it returns to the first one
            
        }
        
        
}



/* [] END OF FILE */
