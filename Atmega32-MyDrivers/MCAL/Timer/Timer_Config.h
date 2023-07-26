/*
S * Timer_Config.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef MCAL_TIMER_TIMER_CONFIG_H_
#define MCAL_TIMER_TIMER_CONFIG_H_

/*--------------------------------------------------------------------------------------------*/
/*   SELECT F_OSC IN MHZ   */
/*--------------------------------------------------------------------------------------------*/
#define F_OSC                      16

/*--------------------------------------------------------------------------------------------
*   TIMER0_MODE OPTIONS :   1 - TIMER0_MODE_NORAML
* 						              2 - TIMER0_MODE_CTC
* 						              3 - TIMER0_MODE_PWM_PHASE_CORRECT
* 						              4 - TIMER0_MODE_PWM_FAST
*--------------------------------------------------------------------------------------------*/
#define TIMER0_MODE TIMER0_MODE_PWM_FAST

#if ((TIMER_MODE == TIMER0_MODE_FAST_PWM) || (TIMER_MODE == TIMER0_MODE_PWM_PHASE_CORRECT))
#define TIMER0_PWM_OC0_MODE TIMER0_PWM_OC0_NON_INVERTED
#endif

#define TIMER0_PRESCALER   TIMER0_CS_PRESCALER_64

#endif /* MCAL_TIMER_TIMER_CONFIG_H_ */
