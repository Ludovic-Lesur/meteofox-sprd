/* 
 * File:   pwm.h
 * Author: Ludovic
 *
 * Created on 19 juillet 2018, 20:07
 */

#include <pic12lf1571.h>
#include "pwm.h"

/*** PWM functions ***/

/* CONFIGURE PWM1 PERIPHERAL
 * @param:  None.
 * @return: None.
 */
void PWM1_Init(void) {
    // Ensure module is off.
    PWM1CON &= 0x03;
    // No interrupt.
    PWM1INTE &= 0xF0; // xxIE='0'.
    // No prescaler and input clock = Fosc (LFINTOSC @ 31kHz).
    PWM1CLKCON &= 0x8C; // PS='000' and CS='00'.
    // Independant run mode.
    PWM1OFCON &= 0x9F; // OFM='00'.
    // No phase shift.
    PWM1PH = 0;
    // Set default PWM frequency to 1kHz.
    PWM1PR = 30; // See equation 22-1.
    // Set default duty cycle to 50%.
    PWM1DC = 15; // See equation 22-2.
    // Enable output.
    PWM1CON |= 0x40; // OE='1'.
}

/* START PWM MODULE (OUTPUT ON RA5 PIN).
 * @param:  None.
 * @return: None.
 */
void PWM1_Start(void) {
    // Enable peripheral.
    PWM1CON |= 0x80; // EN='1'.
}

/* STOP PWM MODULE.
 * @param:  None.
 * @return: None.
 */
void PWM1_Stop(void) {
     // Enable peripheral.
    PWM1CON &= 0x7F; // EN='0'.
}

/* SET PWM FREQUENCY.
 * @param frequency:    PWM frequency in Hz.
 * @return:             None.
 */
void PWM1_SetFrequency(unsigned int frequency) {
    // Disable peripheral.
    PWM1_Stop();
    // Set PWM frequency.
    unsigned int pr_value = (31000/frequency)-1;
    PWM1PR = pr_value; // See equation 22-1.
    // Set duty cycle to 50%.
    PWM1DC = pr_value/2; // See equation 22-2.
    // Enable peripheral.
    PWM1_Start();
}


