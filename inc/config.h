/* 
 * File:   config.h
 * Author: Ludo
 *
 * Created on 18 jun. 2018, 12:26
 */

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <xc.h>

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

#endif	/* __CONFIG_H__ */

