/*
 * LED_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include "LED/LED_Config.h"
#include "LED/LED_Interface.h"

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_LED_Void_LedInit(u8 Copy_u8Led)
{
  switch(Copy_u8Led)
  {
    case LED_YELLOW:
      M_DIO_Void_SetPinDirection(LED_YELLOW_PIN, DIO_OUTPUT);
      break;
    case LED_BLUE:
      M_DIO_Void_SetPinDirection(LED_BLUE_PIN, DIO_OUTPUT);
      break;
    case LED_GREEN:
      M_DIO_Void_SetPinDirection(LED_GREEN_PIN, DIO_OUTPUT);
      break;
    case LED_RED:
      M_DIO_Void_SetPinDirection(LED_RED_PIN, DIO_OUTPUT);
      break;
  }
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_LED_Void_LedOn(u8 Copy_u8Led)
{
  switch(Copy_u8Led)
  {
    case LED_YELLOW:
      M_DIO_Void_SetPinValue(LED_YELLOW_PIN, LED_ON);
      break;
    case LED_BLUE:
      M_DIO_Void_SetPinValue(LED_BLUE_PIN, LED_ON);
      break;
    case LED_GREEN:
      M_DIO_Void_SetPinValue(LED_GREEN_PIN, LED_ON);
      break;
    case LED_RED:
      M_DIO_Void_SetPinValue(LED_RED_PIN, LED_ON);
      break;
  }
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_LED_Void_LedOff(u8 Copy_u8Led)
{
  switch(Copy_u8Led)
  {
    case LED_YELLOW:
      M_DIO_Void_SetPinValue(LED_YELLOW_PIN, LED_OFF);
      break;
    case LED_BLUE:
      M_DIO_Void_SetPinValue(LED_BLUE_PIN, LED_OFF);
      break;
    case LED_GREEN:
      M_DIO_Void_SetPinValue(LED_GREEN_PIN, LED_OFF);
      break;
    case LED_RED:
      M_DIO_Void_SetPinValue(LED_RED_PIN, LED_OFF);
      break;
  }
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_LED_Void_LedBlink(u8 Copy_u8Led)
{
  switch(Copy_u8Led)
  {
    case LED_YELLOW:
      M_DIO_Void_SetPinValue(LED_YELLOW_PIN, LED_ON);
      _delay_ms(LED_BLINKING_TIME_MS);
      M_DIO_Void_SetPinValue(LED_YELLOW_PIN, LED_OFF);
      break;
    case LED_BLUE:
      M_DIO_Void_SetPinValue(LED_BLUE_PIN, LED_ON);
      _delay_ms(LED_BLINKING_TIME_MS);
      M_DIO_Void_SetPinValue(LED_BLUE_PIN, LED_OFF);
      break;
    case LED_GREEN:
      M_DIO_Void_SetPinValue(LED_GREEN_PIN, LED_ON);
      _delay_ms(LED_BLINKING_TIME_MS);
      M_DIO_Void_SetPinValue(LED_GREEN_PIN, LED_OFF);
      break;
    case LED_RED:
      M_DIO_Void_SetPinValue(LED_RED_PIN, LED_ON);
      _delay_ms(LED_BLINKING_TIME_MS);
      M_DIO_Void_SetPinValue(LED_RED_PIN, LED_OFF);
      break;
  }
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void H_LED_Void_LedToggle(u8 Copy_u8Led)
{
  switch(Copy_u8Led)
  {
    case LED_YELLOW:
      M_DIO_Void_TogglePinValue(LED_YELLOW_PIN);
      break;
    case LED_BLUE:
      M_DIO_Void_TogglePinValue(LED_BLUE_PIN);
      break;
    case LED_GREEN:
      M_DIO_Void_TogglePinValue(LED_GREEN_PIN);
      break;
    case LED_RED:
      M_DIO_Void_TogglePinValue(LED_RED_PIN);
      break;
  }
}
