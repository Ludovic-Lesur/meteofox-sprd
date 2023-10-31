/* 
 * File:   gpio.h
 * Author: Ludo
 *
 * Created on 18 jun. 2018, 13:08
 */

#ifndef __GPIO_H__
#define __GPIO_H__

/*** GPIO functions ***/

/*!******************************************************************
 * \fn void GPIO_init(void)
 * \brief Configure board GPIOs.
 * \param[in]  	none
 * \param[out] 	none
 * \retval		none
 *******************************************************************/
void GPIO_init(void);

/*!******************************************************************
 * \fn unsigned char GPIO_rain_detected(void)
 * \brief Read rain sensor.
 * \param[in]  	none
 * \param[out] 	none
 * \retval		1 if rain has been detected, 0 otherwise.
 *******************************************************************/
unsigned char GPIO_rain_detected(void);

/*!******************************************************************
 * \fn unsigned char GPIO_button_pressed(void)
 * \brief Read user button.
 * \param[in]  	none
 * \param[out] 	none
 * \retval		1 if button is pressed, 0 otherwise.
 *******************************************************************/
unsigned char GPIO_button_pressed(void);

#endif	/* __GPIO_H__ */

