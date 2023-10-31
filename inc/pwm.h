/* 
 * File:   pwm.h
 * Author: Ludo
 *
 * Created on 19 jul. 2018, 20:06
 */

#ifndef __PWM_H__
#define __PWM_H__

/*** PWM functions ***/

/*!******************************************************************
 * \fn void PWM1_init(void)
 * \brief Configure PWM1 peripheral.
 * \param[in]  	none
 * \param[out] 	none
 * \retval		none
 *******************************************************************/
void PWM1_init(void);

/*!******************************************************************
 * \fn void PWM1_start(void)
 * \brief Start PWM1 peripheral.
 * \param[in]  	none
 * \param[out] 	none
 * \retval		none
 *******************************************************************/
void PWM1_start(void);

/*!******************************************************************
 * \fn void PWM1_stop(void)
 * \brief Stop PWM1 peripheral.
 * \param[in]  	none
 * \param[out] 	none
 * \retval		none
 *******************************************************************/
void PWM1_stop(void);

/*!******************************************************************
 * \fn void PWM1_set_frequency(unsigned int frequency)
 * \brief Set PWM1 output frequency.
 * \param[in]  	frequency: PWM signal frequency in Hz.
 * \param[out] 	none
 * \retval		none
 *******************************************************************/
void PWM1_set_frequency(unsigned int frequency);

#endif	/* __PWM_H__ */

