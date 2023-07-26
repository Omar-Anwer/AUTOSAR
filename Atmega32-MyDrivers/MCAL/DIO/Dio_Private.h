/*
 * Dio_Private.h
 *
 *  Created on: Jun 27, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */
#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_

/*--------------------------------------------------------------------------------------------*/
/*   DEFINES   */
/*--------------------------------------------------------------------------------------------*/

/*   PORT A   */
#define GPIO_PINA_REG     (*(volatile u8*) 0x39)
#define GPIO_DDRA_REG     (*(volatile u8*) 0x3A)
#define GPIO_PORTA_REG    (*(volatile u8*) 0x3B)

/*   PORT B   */
#define GPIO_PINB_REG     (*(volatile u8*) 0x36)
#define GPIO_DDRB_REG     (*(volatile u8*) 0x37)
#define GPIO_PORTB_REG    (*(volatile u8*) 0x38)

/*   PORT C   */
#define GPIO_PINC_REG     (*(volatile u8*) 0x33)
#define GPIO_DDRC_REG     (*(volatile u8*) 0x34)
#define GPIO_PORTC_REG    (*(volatile u8*) 0x35)

/*   PORT D   */
#define GPIO_PIND_REG     (*(volatile u8*) 0x30)
#define GPIO_DDRD_REG     (*(volatile u8*) 0x31)
#define GPIO_PORTD_REG    (*(volatile u8*) 0x32)


#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
