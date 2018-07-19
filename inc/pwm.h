/* 
 * File:   pwm.h
 * Author: Ludovic
 *
 * Created on 19 juillet 2018, 20:06
 */

#ifndef PWM_H
#define	PWM_H

/*** PWM functions ***/

void PWM1_Init(void);
void PWM1_Start(void);
void PWM1_Stop(void);
void PWM1_SetFrequency(unsigned int frequency);

#endif	/* PWM_H */

