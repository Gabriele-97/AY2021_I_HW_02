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
// This function sets the PWM parameters needed to generate each pattern
#ifndef _DRIVER_H_
    #define _DRIVER_H_
    #include "project.h"
    extern int flag;
    extern int DC7;
    
    void RGBLed_WriteColor(uint16_t period, char modeR, char modeG, int compareR, int compareG );
    
    
#endif
/* [] END OF FILE */
