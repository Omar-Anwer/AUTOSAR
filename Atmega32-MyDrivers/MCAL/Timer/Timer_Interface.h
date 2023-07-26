/*
 * Timer_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "Common_Macros.h"
#include "DIO_Interface.h"
#include <avr/interrupt.h>

/*--------------------------------------------------------------------------------------------*/
/*   DEFINES   */
/*--------------------------------------------------------------------------------------------*/
#define  TIMER0_CHANNEL                     (0U)
#define  TIMER1_CHANNEL                     (1U)
#define  TIMER2_CHANNEL                     (2U)

/*  TIMER0 Operation Modes */
#define TIMER0_MODE_NORMAL                  (0U)
#define TIMER0_MODE_CTC                     (8U)
#define TIMER0_MODE_PWM_PHASE_CORRECT       (64U)
#define TIMER0_MODE_PWM_FAST                (72U)

/*  TIMER0 Clock Select Prescaler */
#define TIMER0_CS_DISABLED                  (0U)  /* Timer0 Stopped */
#define TIMER0_CS_NO_PRESCALER              (1U)
#define TIMER0_CS_PRESCALER_8               (2U)
#define TIMER0_CS_PRESCALER_64              (3U)
#define TIMER0_CS_PRESCALER_256             (4U)
#define TIMER0_CS_PRESCALER_1024            (5U)
#define TIMER0_CS_External_FAILING_EDGE     (6U)
#define TIMER0_CS_External_RISING_EDGE      (7U)

/*  TIMER0 CTC Modes */
#define TIMER0_CTC_OC0_DISCONNECTED         (0U)
#define TIMER0_CTC_OC0_TOGGLE               (16U)
#define TIMER0_CTC_OC0_LOW                  (32U)
#define TIMER0_CTC_OC0_HIGH                 (48U)

/*  TIMER0 Fast PWM and  Phase Correct PWM Modes  */
#define TIMER0_PWM_OC0_DISCONNECTED         (0U)
#define TIMER0_PWM_OC0_NON_INVERTED         (32U)
#define TIMER0_PWM_OC0_INVERTED             (48U)


/*--------------------------------------------------------------------------------------------*/
/*   PROTOTYPES   */
/*--------------------------------------------------------------------------------------------*/
void M_Timer_Void_TimerInit(const u8 Copy_U8_TimerChannel);
static u16 M_Timer_Void_TimerSetPrescaler(const u8 Copy_U8_TimerChannel, const u16 Copy_u16Prescaler);
void M_Timer_Void_TimerSetTime(const u8 Copy_U8_TimerChannel, const u32 Copy_U32_DesiredTime_ms);
void M_Timer_Void_TimerStart(const u8 Copy_U8_TimerChannel);
void M_Timer_Void_TimerStop(const u8 Copy_U8_TimerChannel);

void M_Timer_Void_PWMInit(const u8);
void M_Timer_Void_PWMSetDutyCycle(const u8, const f32);
void M_Timer_Void_PWMStart(const u8);
void M_Timer_Void_PWMStop(const u8);

void M_Timer_Void_TimerEnableInterrupt(const u8 Copy_U8_TimerChannel);
void M_Timer_Void_TimerDisableInterrupt(const u8 Copy_U8_TimerChannel);

void M_Timer_Void_SetCallBack(const u8 Copy_U8_TimerChannel, void(*Copy_CallBackPtr)(void));

#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
