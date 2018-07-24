/* 
 * File:   timer.c
 * Author: Ludovic
 *
 * Created on 17 juillet 2018, 21:08
 */

#include <pic12lf1571.h>
#include "timer.h"

/*** Timer funcions ***/

/* CONFIGURE TIMER2 MODULE
 * param:   None.
 * @return: None.
 */
void TIMER2_Init(void) {
    // Ensure timer is off.
    T2CON &= 0xFB; // TMR2ON='0'.
     // Prescaler=16, postscaler=16.
    T2CON &= 0x84; // Reset bits 0-1 and 3-6.
    T2CON |= 0x02; // T2OUTPS='0000' and T2CKPS='10'.
    // Set compare value to reach 1s overflow period.
    PR2 = 48; // 48 fronts @ (31kHz/(4*1*16)) (LFINTOSC) = 10Hz.
}

/* START TIMER2 TO COUNT MILLISECONDS.
 * @param:  None.
 * @return: None.
 */
void TIMER2_Start(void) {
    // Enable interrupt.
    PIE1 |= 0x02; // TMR2IE='1'.
    // Start timer.
    T2CON |= 0x04; // TMR2ON='1'.
}

/* STOP TIMER2.
 * @param:  None.
 * @return: None.
 */
void TIMER2_Stop(void) {
    // Stop timer.
    T2CON &= 0xFB; // TMR2ON='0'.
    // Disable interrupt.
    PIE1 &= 0xFD; // TMR2IE='0'.
}