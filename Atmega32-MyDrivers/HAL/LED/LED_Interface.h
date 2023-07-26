/*
 * LED_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include <util/delay.h>
#include "LIB/Std_Types.h"
#include "DIO/Dio_Interface.h"
#include "LED/LED_Config.h"

/*--------------------------------------------------------------------------------------------*/
/*   DEFINES   */
/*--------------------------------------------------------------------------------------------*/
#define LED_YELLOW    0
#define LED_BLUE      1
#define LED_GREEN     2
#define LED_RED       3

#define LED_OFF       DIO_LOW
#define LED_ON        DIO_HIGH
/*--------------------------------------------------------------------------------------------*/
/*   PROTOTYPES   */
/*--------------------------------------------------------------------------------------------*/
void H_LED_Void_LedInit(u8);
void H_LED_Void_LedOn(u8);
void H_LED_Void_LedOff(u8);
void H_LED_Void_LedBlink(u8);
void H_LED_Void_LedToggle(u8);

#endif /* HAL_LED_LED_INTERFACE_H_ */
