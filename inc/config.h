/* 
 * File:   config.h
 * Author: Ludovic
 *
 * Created on 18 juin 2018, 12:26
 */

#ifndef CONFIG_H
#define	CONFIG_H

#include <pic12lf1571.h>

#pragma config FOSC = INTOSC // Use internal oscillator.
#pragma config WDTE = OFF // Watchdog timer disabled.
#pragma config PWRTE = OFF // Power-up timer disabled.
#pragma config MCLRE = ON // MCLR/VPP pin function is MCLR.
#pragma config CP = OFF // Code protection disabled.
#pragma config BOREN = OFF // Brown-out reset disabled.
#pragma config CLKOUTEN = OFF // Clock output disabled.
#pragma config WRT = OFF // Flash memory self protection off.
#pragma config PLLEN = OFF // PLL disabled.
#pragma config STVREN = OFF // Stack overflow/underflow reset disabled.
#pragma config BORV = LO // Low brown-out voltage.
#pragma config LPBOREN = OFF // Low-power brown-out reset disabled.
#pragma config LVP = OFF // Low voltage programming disabled.

#endif	/* CONFIG_H */

