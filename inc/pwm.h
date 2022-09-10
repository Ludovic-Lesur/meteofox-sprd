/* 
 * File:   pwm.h
 * Author: Ludo
 *
 * Created on 19 jul 2018, 20:06
 */

#ifndef __PWM_H__
#define __PWM_H__

/*** PWM functions ***/

void PWM1_init(void);
void PWM1_start(void);
void PWM1_stop(void);
void PWM1_set_frequency(unsigned int frequency);

#endif	/* __PWM_H__ */

