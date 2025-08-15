/* 
 * File:   interrupt.h
 * Author: Ludo
 *
 * Created on 18 jul. 2018, 02:44
 */

#include "interrupt.h"

#include <xc.h>

/*** INTERRUPT functions ***/

/*******************************************************************/
void INTERRUPT_init(void) {
    INTCON |= 0xC0; // GIE='1' and PEIE='1'.
}
