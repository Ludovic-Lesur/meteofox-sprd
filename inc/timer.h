/* 
 * File:   timer.h
 * Author: Ludo
 *
 * Created on 17 jul. 2018, 20:43
 */

#ifndef __TIMER_H__
#define __TIMER_H__

/*** TIMER functions ***/

/*!******************************************************************
 * \fn void TIMER2_init(void)
 * \brief Configure TIMER2 peripheral for uptime operation.
 * \param[in]  	none
 * \param[out] 	none
 * \retval		none
 *******************************************************************/
void TIMER2_init(void);

/*!******************************************************************
 * \fn void TIMER2_start(void)
 * \brief Start TIMER2.
 * \param[in]  	none
 * \param[out] 	none
 * \retval		none
 *******************************************************************/
void TIMER2_start(void);

/*!******************************************************************
 * \fn void TIMER2_stop(void)
 * \brief Stop TIMER2.
 * \param[in]  	none
 * \param[out] 	none
 * \retval		none
 *******************************************************************/
void TIMER2_stop(void);

#endif	/* __TIMER_H__ */

