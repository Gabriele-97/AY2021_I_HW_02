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
        
        
        state ++;
        if (state == 8){
            state = 1;
            
        }
        
        
}



/* [] END OF FILE */
