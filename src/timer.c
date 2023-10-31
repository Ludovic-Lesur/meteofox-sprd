/* 
 * File:   timer.c
 * Author: Ludo
 *
 * Created on 17 jul. 2018, 21:08
 */

#include "timer.h"

#include <pic12lf1571.h>

/*** TIMER functions ***/

/*******************************************************************/
void TIMER2_init(void) {
    // Ensure timer is off.
    T2CON &= 0xFB; // TMR2ON='0'.
     // Prescaler=16, postscaler=16.
    T2CON &= 0x84; // Reset bits 0-1 and 3-6.
    T2CON |= 0x02; // T2OUTPS='0000' and T2CKPS='10'.
    // Set compare value to reach 1s overflow period.
    PR2 = 48; // 48 fronts @ (31kHz/(4*1*16)) (LFINTOSC) = 10Hz.
}

/*******************************************************************/
void TIMER2_start(void) {
    // Enable interrupt.
    PIE1 |= 0x02; // TMR2IE='1'.
    // Start timer.
    T2CON |= 0x04; // TMR2ON='1'.
}

/*******************************************************************/
void TIMER2_stop(void) {
    // Stop timer.
    T2CON &= 0xFB; // TMR2ON='0'.
    // Disable interrupt.
    PIE1 &= 0xFD; // TMR2IE='0'.
}