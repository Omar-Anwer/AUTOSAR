/*
 * Timer_Private.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_

/*--------------------------------------------------------------------------------------------*/
/*   DEFINES   */
/*--------------------------------------------------------------------------------------------*/

/*****************************************************************
*   TIMER0 REGISTERS
*****************************************************************/
#define TIMER0_TCCR0_REG      (*(volatile u8* const) 0x53)
#define TIMER0_TIMSK_REG      (*(volatile u8* const) 0x59)
#define TIMER0_TCNT0_REG      (*(volatile u8* const) 0x52)
#define TIMER0_OCR0_REG       (*(volatile u8* const) 0x5C)


/*  TCCR0 BITS   */
#define TCCR0_WGM00_BIT                  6
#define TCCR0_COM01_BIT                  5
#define TCCR0_COM00_BIT                  4
#define TCCR0_WGM01_BIT                  3
#define TCCR0_CS02_BIT                   2
#define TCCR0_CS01_BIT                   1
#define TCCR0_CS00_BIT                   0

/*   TIMSK BITS   */
#define TIMSK_OCIE0_BIT                  1
#define TIMSK_TOIE0_BIT                  0

/*****************************************************************
*   TIMER1 REGISTERS
*****************************************************************/
#define TIMER1_TCCR1A_REG     (*(volatile u8*  const)  0x4F)
#define TIMER1_TCCR1B_REG     (*(volatile u8*  const)  0x4E)
#define TIMER1_OCR1A_REG      (*(volatile u16* const)  0x4A)
#define TIMER1_ICR1_REG       (*(volatile u16* const)  0x46)

/*   TCCR1A BITS   */
#define TCCR1A_COM1A1_BIT                 7
#define TCCR1A_COM1A0_BIT                 6
#define TCCR1A_WGM11_BIT                  1
#define TCCR1A_WGM10_BIT                  0

/*   TCCR1B BITS   */
#define TCCR1B_WGM13_BIT                  4
#define TCCR1B_WGM12_BIT                  3
#define TCCR1B_CS12_BIT                   2
#define TCCR1B_CS11_BIT                   1
#define TCCR1B_CS10_BIT                   0

/*****************************************************************
*   TIMER2 REGISTERS
*****************************************************************/

#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
