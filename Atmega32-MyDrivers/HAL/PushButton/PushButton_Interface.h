/*
 * PushButton_Interface.h
 *
 */

#ifndef HAL_PUSHBUTTON_PUSHBUTTON_INTERFACE_H_
#define HAL_PUSHBUTTON_PUSHBUTTON_INTERFACE_H_

/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include <util/delay.h>
#include "LIB/Std_Types.h"
#include "DIO/Dio_Interface.h"

/*--------------------------------------------------------------------------------------------*/
/*   DEFINES   */
/*--------------------------------------------------------------------------------------------*/
#define PUSHBUTTON_0                    0
#define PUSHBUTTON_1                    1
#define PUSHBUTTON_2                    2
#define PUSHBUTTON_3                    3

#define PUSHBUTTON_PRESSED              (0U)
#define PUSHBUTTON_RELEASED             (1U)

#define PUSHBUTTON_SINGLE_PRESS         (0U)
#define PUSHBUTTON_LONG_PRESS           (1U)

#define PUSHBUTTON_PULLUP_ENABLED       (1U)
#define PUSHBUTTON_PULLUP_DISABLED      (0U)

/*--------------------------------------------------------------------------------------------*/
/*   PROTOTYPES   */
/*--------------------------------------------------------------------------------------------*/
void H_PushButton_Void_PushButtonInit(u8, u8);
u8   H_PushButton_U8_PushButtonRead(u8, u8);

#endif /* HAL_PUSHBUTTON_PUSHBUTTON_INTERFACE_H_ */
