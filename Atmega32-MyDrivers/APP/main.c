/*
 * main.c
 *
 *  Created on: Jun 27, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */
#include "Project_Interface.h"

int main(void)
{
  H_LED_Void_LedInit(LED_RED);
  H_LED_Void_LedInit(LED_BLUE);
  H_LED_Void_LedInit(LED_GREEN);
  H_LED_Void_LedInit(LED_YELLOW);

  H_PushButton_Void_PushButtonInit(PUSHBUTTON_0, PUSHBUTTON_PULLUP_DISABLED);
  H_PushButton_Void_PushButtonInit(PUSHBUTTON_1, PUSHBUTTON_PULLUP_DISABLED);
  H_PushButton_Void_PushButtonInit(PUSHBUTTON_2, PUSHBUTTON_PULLUP_DISABLED);
  H_PushButton_Void_PushButtonInit(PUSHBUTTON_3, PUSHBUTTON_PULLUP_DISABLED);



  while(1)
  {
    if(H_PushButton_U8_PushButtonRead(PUSHBUTTON_0, PUSHBUTTON_LONG_PRESS) == PUSHBUTTON_PRESSED)
    {
      H_LED_Void_LedBlink(LED_RED);
    }

    if(H_PushButton_U8_PushButtonRead(PUSHBUTTON_1, PUSHBUTTON_LONG_PRESS) == PUSHBUTTON_PRESSED)
    {
      H_LED_Void_LedBlink(LED_GREEN);
    }

    if(H_PushButton_U8_PushButtonRead(PUSHBUTTON_2, PUSHBUTTON_SINGLE_PRESS) == PUSHBUTTON_PRESSED)
    {
      H_LED_Void_LedBlink(LED_YELLOW);
    }

    if(H_PushButton_U8_PushButtonRead(PUSHBUTTON_3, PUSHBUTTON_SINGLE_PRESS) == PUSHBUTTON_PRESSED)
    {
      H_LED_Void_LedBlink(LED_BLUE);
    }


  }
  return 0;
}
