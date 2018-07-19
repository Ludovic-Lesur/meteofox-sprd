/* 
 * File:   gpio.h
 * Author: Ludovic
 *
 * Created on 18 juin 2018, 13:08
 */

#ifndef GPIO_H
#define	GPIO_H

/*** GPIO functions ***/

void GPIO_Init(void);
unsigned char GPIO_RainDetected(void);
unsigned char GPIO_ButtonPressed(void);

#endif	/* GPIO_H */

