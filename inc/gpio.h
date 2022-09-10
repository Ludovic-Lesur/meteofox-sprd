/* 
 * File:   gpio.h
 * Author: Ludo
 *
 * Created on 18 jun 2018, 13:08
 */

#ifndef __GPIO_H__
#define __GPIO_H__

/*** GPIO functions ***/

void GPIO_init(void);
unsigned char GPIO_rain_detected(void);
unsigned char GPIO_button_pressed(void);

#endif	/* __GPIO_H__ */

