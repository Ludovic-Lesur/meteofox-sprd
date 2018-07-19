/* 
 * File:   interrupt.h
 * Author: Ludovic
 *
 * Created on 18 juillet 2018, 02:44
 */

#include "interrupt.h"
#include <pic12lf1571.h>

/*** Interrupt functions ***/

/* ENABLE GLOBAL AND PERIPHERAL INTERRUPTS.
 * @param:  None.
 * @return: None.
 */
void Interrupt_Init(void) {
    INTCON |= 0xC0; // GIE='1' and PEIE='1'.
}
