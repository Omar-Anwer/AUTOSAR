/*
 * Dio_Interface.h
 *
 *  Created on: Jun 27, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */
#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include "LIB/Utils.h"
#include "LIB/Std_Types.h"

/*--------------------------------------------------------------------------------------------*/
/*   DEFINES   */
/*--------------------------------------------------------------------------------------------*/

/* variables will be needed in loops and error checking */
#define DIO_NUMBER_OF_PORTS         4
#define DIO_NUMBER_OF_PORT_PINS     8
#define DIO_NUMBER_OF_ALL_PINS      32

#define DIO_INPUT               (0U)
#define DIO_OUTPUT              (1U)

#define DIO_LOW                 (0U)
#define DIO_HIGH                (1U)

#define DIO_PORT_INPUT          (0U)
#define DIO_PORT_OUTPUT         (0xFF)

#define DIO_PORT_LOW            (0U)
#define DIO_PORT_HIGH           (0xFF)

/*   DIO PORTS   */
#define DIOA                      0
#define DIOB                      1
#define DIOC                      2
#define DIOD                      3

/*   PORT A   */
#define DIO_PA0_PIN                 0
#define DIO_PA1_PIN                 1
#define DIO_PA2_PIN                 2
#define DIO_PA3_PIN                 3
#define DIO_PA4_PIN                 4
#define DIO_PA5_PIN                 5
#define DIO_PA6_PIN                 6
#define DIO_PA7_PIN                 7

/*   PORT B   */
#define DIO_PB0_PIN                 8
#define DIO_PB1_PIN                 9
#define DIO_PB2_PIN                 10
#define DIO_PB3_PIN                 11
#define DIO_PB4_PIN                 12
#define DIO_PB5_PIN                 13
#define DIO_PB6_PIN                 14
#define DIO_PB7_PIN                 15

/*   PORT C   */
#define DIO_PC0_PIN                 16
#define DIO_PC1_PIN                 17
#define DIO_PC2_PIN                 18
#define DIO_PC3_PIN                 19
#define DIO_PC4_PIN                 20
#define DIO_PC5_PIN                 21
#define DIO_PC6_PIN                 22
#define DIO_PC7_PIN                 23

/*   PORT D   */
#define DIO_PD0_PIN                 24
#define DIO_PD1_PIN                 25
#define DIO_PD2_PIN                 26
#define DIO_PD3_PIN                 27
#define DIO_PD4_PIN                 28
#define DIO_PD5_PIN                 29
#define DIO_PD6_PIN                 30
#define DIO_PD7_PIN                 31

#define DIO_PULLUP_ENABLED          (1U)
#define DIO_PULLUP_DISABLED         (0U)

typedef enum
{
  E_OK = 0,
  E_NOK,
  E_OUT_OF_RANGE,
  E_NULL_POINTER
}DIO_ErrorStatus_t;

/*--------------------------------------------------------------------------------------------*/
/*   PROTOTYPES   */
/*--------------------------------------------------------------------------------------------*/
extern DIO_ErrorStatus_t M_DIO_Void_SetPinDirection(u8,u8);
extern DIO_ErrorStatus_t M_DIO_Void_SetPinValue(u8,u8);
extern u8                M_DIO_U8_GetPinValue(u8);
extern DIO_ErrorStatus_t M_DIO_Void_TogglePinValue(u8);
extern DIO_ErrorStatus_t M_DIO_Void_SetPinPullUpRes(u8,u8);

extern DIO_ErrorStatus_t M_DIO_Void_SetPortDirection(u8,u8);
extern DIO_ErrorStatus_t M_DIO_Void_SetPortValue(u8,u8);
extern u8                M_DIO_U8_GetPortValue(u8);
extern DIO_ErrorStatus_t M_DIO_Void_TogglePortValue(u8);




#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
