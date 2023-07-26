/*
 * PushButton_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include "PushButton/PushButton_Config.h"
#include "PushButton/PushButton_Interface.h"

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_PushButton_Void_PushButtonInit(u8 Copy_u8PushButton, u8 Copy_u8PushButtonRes)
{
  switch(Copy_u8PushButton)
  {
    case PUSHBUTTON_0:
      M_DIO_Void_SetPinPullUpRes(PUSHBUTTON_0_PIN, Copy_u8PushButtonRes);
      break;
    case PUSHBUTTON_1:
      M_DIO_Void_SetPinPullUpRes(PUSHBUTTON_1_PIN, Copy_u8PushButtonRes);
      break;
    case PUSHBUTTON_2:
      M_DIO_Void_SetPinPullUpRes(PUSHBUTTON_2_PIN, Copy_u8PushButtonRes);
      break;
    case PUSHBUTTON_3:
      M_DIO_Void_SetPinPullUpRes(PUSHBUTTON_3_PIN, Copy_u8PushButtonRes);
      break;
  }
}

u8 H_PushButton_U8_PushButtonRead(u8 Copy_u8PushButton, u8 Copy_u8PushButtonPressType)
{
  u8 Local_u8PushButtonState = PUSHBUTTON_RELEASED;
  switch(Copy_u8PushButton)
  {
    case PUSHBUTTON_0:
      if(M_DIO_U8_GetPinValue(PUSHBUTTON_0_PIN) == PUSHBUTTON_PRESSED)
      {
        if(Copy_u8PushButtonPressType == PUSHBUTTON_LONG_PRESS)
        {
          while(M_DIO_U8_GetPinValue(PUSHBUTTON_0_PIN) == PUSHBUTTON_PRESSED);
        }
        else
        {
          _delay_ms(PUSHBUTTON_DEBOUNCING_TIME_MS);
        }
        Local_u8PushButtonState = PUSHBUTTON_PRESSED;
      }
      break;

    case PUSHBUTTON_1:
      if(M_DIO_U8_GetPinValue(PUSHBUTTON_1_PIN) == PUSHBUTTON_PRESSED)
      {
        if(Copy_u8PushButtonPressType == PUSHBUTTON_LONG_PRESS)
        {
          while(M_DIO_U8_GetPinValue(PUSHBUTTON_1_PIN) == PUSHBUTTON_PRESSED);
        }
        else
        {
          _delay_ms(PUSHBUTTON_DEBOUNCING_TIME_MS);
        }
        Local_u8PushButtonState = PUSHBUTTON_PRESSED;
      }
      break;

    case PUSHBUTTON_2:
      if(M_DIO_U8_GetPinValue(PUSHBUTTON_2_PIN) == PUSHBUTTON_PRESSED)
      {
        if(Copy_u8PushButtonPressType == PUSHBUTTON_LONG_PRESS)
        {
          while(M_DIO_U8_GetPinValue(PUSHBUTTON_2_PIN) == PUSHBUTTON_PRESSED);
        }
        else
        {
          _delay_ms(PUSHBUTTON_DEBOUNCING_TIME_MS);
        }
        Local_u8PushButtonState = PUSHBUTTON_PRESSED;
      }
      break;

    case PUSHBUTTON_3:
      if(M_DIO_U8_GetPinValue(PUSHBUTTON_3_PIN) == PUSHBUTTON_PRESSED)
      {
        if(Copy_u8PushButtonPressType == PUSHBUTTON_LONG_PRESS)
        {
          while(M_DIO_U8_GetPinValue(PUSHBUTTON_3_PIN) == PUSHBUTTON_PRESSED);
        }
        else
        {
          _delay_ms(PUSHBUTTON_DEBOUNCING_TIME_MS);
        }
        Local_u8PushButtonState = PUSHBUTTON_PRESSED;
      }
      break;
  }
  return Local_u8PushButtonState;
}

