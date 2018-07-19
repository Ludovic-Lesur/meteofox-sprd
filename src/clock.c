/* 
 * File:   clock.c
 * Author: Ludovic
 *
 * Created on 18 juin 2018, 13:01
 */

#include "clock.h"
#include <pic12lf1571.h>

/*** Clock functions ***/

/* CONFIGURE SYSTEM CLOCK USING LFINTOSC.
 * @param:  None.
 * @return: None.
 */
void Clock_Init(void) {
    // Use LFINTOSC as system clock.
    OSCCON = 0x02; // SPLLEN='0', IRCF='0000' and SCS='10'.
    // Wait for LFINTOSC to be ready.
    while ((OSCSTAT & 0x02) == 0); // LFIOFR='1'.
}