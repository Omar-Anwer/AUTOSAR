/*
 * Dio_Regs.h
 *
 *  Created on: Jul 15, 2023
 *      Author: O. A.
 * 
 * Description: Header file for Dio Module Registers.
 * 
 */
#ifndef DIO_REGS_H_
#define DIO_REGS_H_

#include "Std_Types.h"

/* Definition for PORTA Registers */
#define DIO_PORTA_REG (*(volatile uint8* const) 0x3B)
#define DIO_DDRA_REG  (*(volatile uint8* const) 0x3A)
#define DIO_PINA_REG  (*(volatile uint8* const) 0x39)

/* Definition for PORTB Registers */
#define DIO_PORTB_REG (*(volatile uint8* const) 0x38)
#define DIO_DDRB_REG  (*(volatile uint8* const) 0x37)
#define DIO_PINB_REG  (*(volatile uint8* const) 0x36)

/* Definition for PORTC Registers */
#define DIO_PORTC_REG (*(volatile uint8* const) 0x35)
#define DIO_DDRC_REG  (*(volatile uint8* const) 0x34)
#define DIO_PINC_REG  (*(volatile uint8* const) 0x33)

/* Definition for PORTD Registers */
#define DIO_PORTD_REG (*(volatile uint8* const) 0x32)
#define DIO_DDRD_REG  (*(volatile uint8* const) 0x31)
#define DIO_PIND_REG  (*(volatile uint8* const) 0x30)


#endif /* DIO_REGS_H_ */
