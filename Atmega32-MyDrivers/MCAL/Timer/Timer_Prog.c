/*
 * Timer_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include "Timer_Config.h"
#include "Timer_Interface.h"
#include "Timer_Private.h"

/*--------------------------------------------------------------------------------------------*/
/*   GLOBAL VARIABLES   */
/*--------------------------------------------------------------------------------------------*/
static void(*Timer0_OvfCallBackPtr)(void) = NULL;
static void(*Timer0_CtcCallBackPtr)(void) = NULL;

static u32 Timer0_U32_NumOfOV = 0;
static u8  Timer0_U8_RemTicks = 0;

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void M_Timer_Void_TimerInit(const u8 Copy_U8_TimerChannel)
{
  TIMER0_TCCR0_REG = 0x00;
  /*set CS-bits to 000, WGM-bit is 00 Normal mode and COM-bits 00 OC0 is disconnected*/

  switch(Copy_U8_TimerChannel)
  {
    case TIMER0_CHANNEL:
#if (TIMER0_MODE == TIMER0_MODE_NORMAL)
      TIMER0_TCCR0_REG |= TIMER0_MODE_NORMAL;

#elif (TIMER0_MODE == TIMER0_MODE_CTC)
      TIMER0_TCCR0_REG |= TIMER0_MODE_CTC;

#elif (TIMER0_MODE == TIMER0_MODE_PWM_FAST)
      TIMER0_TCCR0_REG |= TIMER0_MODE_PWM_FAST;

#elif (TIMER0_MODE == TIMER0_MODE_PWM_PHASE_CORRECT)
      TIMER0_TCCR0_REG |= TIMER0_PWM_PHASE_CORRECT;

#else
#error "You Shall Define Timer0 Operation Mode In Timer_Config.h"

#endif
      break;
    case TIMER1_CHANNEL:
      break;
    case TIMER2_CHANNEL:
      break;
  }

}
/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/

u16 M_Timer_Void_TimerSetPrescaler(const u8 Copy_U8_TimerChannel, const u16 Copy_u16Prescaler)
{
  u16 Local_U16_Prescaler;
  switch(Copy_U8_TimerChannel)
  {
    case TIMER0_CHANNEL:
      TIMER0_TCCR0_REG &= 0xF8; /* stop Timer0 */
      switch(TIMER0_PRESCALER)
            {
              case TIMER0_CS_PRESCALER_8:
                TIMER0_TCCR0_REG |= TIMER0_CS_PRESCALER_8;
                Local_U16_Prescaler = 8;
                break;
              case TIMER0_CS_PRESCALER_64:
                TIMER0_TCCR0_REG |= TIMER0_CS_PRESCALER_64;
                Local_U16_Prescaler = 64;
                break;
              case TIMER0_CS_PRESCALER_256:
                TIMER0_TCCR0_REG |= TIMER0_CS_PRESCALER_256;
                Local_U16_Prescaler = 256;
                break;
              case TIMER0_CS_PRESCALER_1024:
                TIMER0_TCCR0_REG |= TIMER0_CS_PRESCALER_1024;
                Local_U16_Prescaler = 1024;
                break;
            }
      break;
    case TIMER1_CHANNEL:
      break;
    case TIMER2_CHANNEL:
      break;
  }
  return Local_U16_Prescaler;
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void M_Timer_Void_TimerSetTime(const u8 Copy_U8_TimerChannel, const u32 Copy_U32_DesiredTime_ms)
{
  u32 Local_U32_TickTime;
  u32 Local_U32_TotalTicks;
  u16 Local_U16_Prescaler;

  switch(Copy_U8_TimerChannel)
  {
    case TIMER0_CHANNEL:
      Local_U16_Prescaler = M_Timer_Void_TimerSetPrescaler(TIMER0_CHANNEL, TIMER0_PRESCALER);
      Local_U32_TickTime   = Local_U16_Prescaler / F_OSC; /* TickTime RESULT WILL BE IN MICRO SECONDS */
      Local_U32_TotalTicks = (Copy_U32_DesiredTime_ms * 1000UL) / Local_U32_TickTime;

#if   (TIMER0_OPERATION_MODE   ==   TIMER0_MODE_NORMAL)
      Timer0_U32_NumOfOV        = Local_U32_TotalTicks >> 8;   /* Local_U32_TotalTicks / 256 */
      Timer0_U8_RemTicks        = Local_U32_TotalTicks & 255; /* Local_U32_TotalTicks % 256 */
      if(Timer0_U8_RemTicks != 0)
      {
        TIMER0_TCNT0_REG = 256 - Timer0_U8_RemTicks;
        Timer0_U32_NumOfOV++;
      }
#elif (TIMER0_MODE   ==   CTC_MODE)
      u8 Local_U8_DivisionValue = 255;
      while(Local_U32_TotalTicks % Local_U8_DivisionValue)
      {
        Local_U8_DivisionValue--;
      }
      TIMER0_OCR0_REG = Local_U8_DivisionValue - 1;
      Timer_U32_NumOfCM = Local_U32_TotalTicks / Local_U8_DivisionValue;
#endif
      break;
        case TIMER1_CHANNEL:
          break;
        case TIMER2_CHANNEL:
          break;
  }

}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void M_Timer_Void_TimerStart(const u8 Copy_U8_TimerChannel)
{
  switch(Copy_U8_TimerChannel)
  {
    case TIMER0_CHANNEL:
      M_Timer_Void_TimerSetPrescaler(TIMER0_CHANNEL, TIMER0_PRESCALER);
      break;
    case TIMER1_CHANNEL:
      break;
    case TIMER2_CHANNEL:
      break;
    default: break;
  }
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void M_Timer_Void_TimerStop(const u8 Copy_U8_TimerChannel)
{
  switch(Copy_U8_TimerChannel)
  {
    case TIMER0_CHANNEL:
      TIMER0_TCCR0_REG &= 0xF8; /*set CS-bits to 000 No CLK*/
      break;
    case TIMER1_CHANNEL:
      break;
    case TIMER2_CHANNEL:
      break;
  }
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void M_Timer_Void_PWMInit(const u8 Copy_U8_TimerChannel)
{
  switch(Copy_U8_TimerChannel)
  {
    case TIMER0_CHANNEL:
      M_DIO_Void_SetPinDirection(DIO_PB3_PIN, DIO_OUTPUT);
      TIMER0_TCCR0_REG |= TIMER0_PWM_OC0_MODE;
      break;
    case TIMER1_CHANNEL:
      break;
    case TIMER2_CHANNEL:
      break;
  }
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void M_Timer_Void_PWMSetDutyCycle(const u8 Copy_U8_TimerChannel, const f32 Copy_F32_DutyCycle)
{
  if((Copy_F32_DutyCycle >= 0) && (Copy_F32_DutyCycle <= 100))
  {
    switch(Copy_U8_TimerChannel)
      {
        case TIMER0_CHANNEL:
    #if (TIMER0_MODE   ==   TIMER0_MODE_PWM_FAST)
          TIMER0_OCR0_REG = ((Copy_F32_DutyCycle / 100.0 ) * 256) - 1;

    #elif (TIMER0_MODE   ==   TIMER0_MODE_PWM_PHASE_CORRECT)
          TIMER0_OCR0_REG = (Copy_F32_DutyCycle / 100.0 ) * 255;
    #endif
          break;
        case TIMER1_CHANNEL:
          break;
        case TIMER2_CHANNEL:
          break;
      }
  }

}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void M_Timer_Void_PWMStart(u8 Copy_U8_TimerChannel)
{
  M_Timer_Void_TimerStart(Copy_U8_TimerChannel);
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void M_Timer_Void_PWMStop(u8 Copy_U8_TimerChannel)
{
  M_Timer_Void_TimerStop(Copy_U8_TimerChannel);
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void M_Timer_Void_SetCallBack(const u8 Copy_U8_TimerChannel, void(*Copy_CallBackPtr)(void))
{
  switch(Copy_U8_TimerChannel)
  {
    case TIMER0_CHANNEL:
      Timer0_OvfCallBackPtr = Copy_CallBackPtr;
      break;
    case TIMER1_CHANNEL:
      break;
    case TIMER2_CHANNEL:
      break;
  }
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void M_Timer_Void_TimerEnableInterrupt(const u8 Copy_U8_TimerChannel)
{
  switch(Copy_U8_TimerChannel)
  {
    case TIMER0_CHANNEL:
#if (TIMER_OPERATION_MODE == TIMER0_MODE_NORMAL)
      SET_BIT(TIMER0_TIMSK_REG, TIMSK_TOIE0_BIT);
#elif (TIMER_OPERATION_MODE == TIMER0_MODE_CTC)
      SET_BIT(TIMER0_TIMSK_REG, TIMSK_OCIE0_BIT);
#endif
      break;
    case TIMER1_CHANNEL:
      break;
    case TIMER2_CHANNEL:
      break;
  }
}

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
void M_Timer_Void_TimerDisableInterrupt(const u8 Copy_U8_TimerChannel)
{
  switch(Copy_U8_TimerChannel)
  {
    case TIMER0_CHANNEL:
#if (TIMER_OPERATION_MODE == TIMER0_MODE_NORAML)
      CLR_BIT(TIMER0_TIMSK_REG, TIMSK_TOIE0_BIT);
#elif (TIMER_OPERATION_MODE == TIMER0_MODE_CTC)
      CLR_BIT(TIMER0_TIMSK_REG, TIMSK_OCIE0_BIT);
#endif
      break;
    case TIMER1_CHANNEL:
      break;
    case TIMER2_CHANNEL:
      break;
  }
}


#if   (TIMER0_MODE   ==   TIMER0_MODE_NORMAL)
ISR(TIMER0_OVF_vect)
{
  static u32 Local_U32_Counter = 0;
  Local_U32_Counter++;
  if(Local_U32_Counter == Timer0_U32_NumOfOV)
  {
    if(Timer0_OvfCallBackPtr != NULL)
    {
      Timer0_OvfCallBackPtr();
    }
    else
    {
      /* Do Nothing */
    }
    Local_U32_Counter = 0;
    TIMER0_TCNT0_REG = 256 - Timer0_U8_RemTicks;
  }
  else
  {
    /* Do Nothing */
  }
}
#endif

#if (TIMER0_MODE   ==   TIMER0_MODE_CTC)

/*--------------------------------------------------------------------------------------------*/
/*   FUNCTION BODY   */
/*--------------------------------------------------------------------------------------------*/
ISR(TIMER0_COMP_vect)
{
  static u32 Local_U32_Counter = 0;
  Local_U32_Counter++;
  if(Local_U32_Counter == Timer_U32_NumOfCM)
  {
    Timer0_CtcCallBackPtr();
    Local_U32_Counter = 0;
  }
}
#endif
