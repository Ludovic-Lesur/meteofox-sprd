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
     // Prescaler=1, postscaler=1.
    T2CON &= 0x84; // T2OUTPS='0000' and T2CKPS='0'.
    // Set compare value to reach 10ms overflow period.
    PR2 = 78; // 78 fronts @ (31kHz/4) (LFINTOSC) = 100Hz.
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