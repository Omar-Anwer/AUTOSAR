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

#define SREG_REG      (*(volatile u8* const) 0x5F)


void Task_500ms(void)
{
  H_LED_Void_LedToggle(LED_RED);
}

int main(void)
{
  H_LED_Void_LedInit(LED_RED);


  H_PushButton_Void_PushButtonInit(PUSHBUTTON_0, PUSHBUTTON_PULLUP_DISABLED);


//  M_Timer_Void_TimerInit(TIMER0_CHANNEL);
//  M_Timer_Void_TimerSetTime(TIMER0_CHANNEL, 100);
//  M_Timer_Void_SetCallBack(TIMER0_CHANNEL, &Task_500ms);
//  M_Timer_Void_TimerEnableInterrupt(TIMER0_CHANNEL);
//  M_Timer_Void_TimerStart(TIMER0_CHANNEL);


  M_Timer_Void_TimerInit(TIMER0_CHANNEL);
  M_Timer_Void_PWMInit(TIMER0_CHANNEL);
  M_Timer_Void_PWMSetDutyCycle(TIMER0_CHANNEL, 50);
  M_Timer_Void_PWMStart(TIMER0_CHANNEL);



  /*Enable global interrupt*/
  SREG |= (1 << 7);



  for(;;)
  {
        if(H_PushButton_U8_PushButtonRead(PUSHBUTTON_1, PUSHBUTTON_SINGLE_PRESS) == PUSHBUTTON_PRESSED)
        {
          M_Timer_Void_PWMStop(TIMER0_CHANNEL);
        }
        else
        {
          M_Timer_Void_PWMStart(TIMER0_CHANNEL);
        }
  }
  return 0;
}
