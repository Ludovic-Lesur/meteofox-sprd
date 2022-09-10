/* 
 * File:   pwm.h
 * Author: Ludo
 *
 * Created on 19 jul 2018, 20:07
 */

#include <pic12lf1571.h>
#include "pwm.h"

/*** PWM functions ***/

/* CONFIGURE PWM1 PERIPHERAL
 * @param:  None.
 * @return: None.
 */
void PWM1_init(void) {
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
    PWM1PRH = 0;
    PWM1PRL = 30; // See equation 22-1.
    // Set default duty cycle to 50%.
    PWM1DCH = 0;
    PWM1DCL = 15; // See equation 22-2.
    // Enable output.
    PWM1CON |= 0x40; // OE='1'.
}

/* START PWM MODULE (OUTPUT ON RA5 PIN).
 * @param:  None.
 * @return: None.
 */
void PWM1_start(void) {
    // Enable peripheral.
    PWM1CON |= 0x80; // EN='1'.
}

/* STOP PWM MODULE.
 * @param:  None.
 * @return: None.
 */
void PWM1_stop(void) {
     // Enable peripheral.
    PWM1CON &= 0x7F; // EN='0'.
}

/* SET PWM FREQUENCY.
 * @param frequency:    PWM frequency in Hz.
 * @return:             None.
 */
void PWM1_set_frequency(unsigned int frequency) {
    // Set PWM frequency.
    unsigned short pr_value = (31000/frequency)-1;
    PWM1PRL = (pr_value & 0x00FF); // See equation 22-1.
    PWM1PRH = (pr_value & 0xFF00) >> 8;
    // Set duty cycle to 50%.
    unsigned short dc_value = pr_value/2;
    PWM1DCL = (dc_value & 0x00FF); // See equation 22-2.
    PWM1DCH = (dc_value & 0xFF00) >> 8;
    // Enable immediate reload.
    PWM1LDCON |= 0x80; // LDA='1'.
}


