/*
 * Dio.c
 *
 *  Created on: Jun 27, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */
#include "Dio_Interface.h"
#include "Dio_Private.h"

volatile u8* const DIO_PORTArr[DIO_NUMBER_OF_PORTS] = {&GPIO_PORTA_REG, &GPIO_PORTB_REG, &GPIO_PORTC_REG, &GPIO_PORTD_REG};
volatile u8* const DIO_DDRArr[DIO_NUMBER_OF_PORTS]  = {&GPIO_DDRA_REG,  &GPIO_DDRB_REG,  &GPIO_DDRC_REG,  &GPIO_DDRD_REG};
volatile u8* const DIO_PINArr[DIO_NUMBER_OF_PORTS]  = {&GPIO_PINA_REG,  &GPIO_PINB_REG,  &GPIO_PINC_REG,  &GPIO_PIND_REG};

/**================================================================
 * @Fn          - M_DIO_Void_SetPinDirection
 * @brief       - set specific pin as input/output
 * @param [in]  - Copy_u8PinNum: set specific pin number according to the defined pins
 * @param [in]  - Copy_u8PinDir:
 * @retval      - DIO_ErrorStatus_t
 * Note         - none
 */

DIO_ErrorStatus_t M_DIO_Void_SetPinDirection(u8 Copy_u8PinNum, u8 Copy_u8PinDir)
{
  DIO_ErrorStatus_t Local_Status = E_OK;

  if( (Copy_u8PinNum < DIO_NUMBER_OF_ALL_PINS) && ( (Copy_u8PinDir == DIO_OUTPUT) || (Copy_u8PinDir == DIO_INPUT) ) )
  {
    u8 Local_u8Port = Copy_u8PinNum >> 3;
    u8 Local_u8Bit  = Copy_u8PinNum & 7;
    /*
        u8 Local_u8Port = Copy_u8PinNum / DIO_NUMBER_OF_PORT_PINS;
        u8 Local_u8Bit  = Copy_u8PinNum % DIO_NUMBER_OF_PORT_PINS;
     */
    WRITE_BIT(*DIO_DDRArr[Local_u8Port], Local_u8Bit, Copy_u8PinDir);
  }
  else
  {
    Local_Status = E_NOK;
  }

  return Local_Status;
}


DIO_ErrorStatus_t M_DIO_Void_SetPinValue(u8 Copy_u8PinNum, u8 Copy_u8PinState)
{
  DIO_ErrorStatus_t Local_Status = E_OK;

  if((Copy_u8PinNum < DIO_NUMBER_OF_ALL_PINS) && ( (Copy_u8PinState == DIO_HIGH) || (Copy_u8PinState == DIO_LOW) ) )
  {
    u8 Local_u8Port = Copy_u8PinNum >> 3;
    u8 Local_u8Bit  = Copy_u8PinNum & 7;

    WRITE_BIT(*DIO_PORTArr[Local_u8Port], Local_u8Bit, Copy_u8PinState);
  }
  else
  {
    Local_Status = E_NOK;
  }

  return Local_Status;
}


u8 M_DIO_U8_GetPinValue(u8 Copy_u8PinNum)
{
  u8 Local_u8Port = Copy_u8PinNum >> 3;
  u8 Local_u8Bit  = Copy_u8PinNum & 7;

  return ( GET_BIT(*DIO_PINArr[Local_u8Port], Local_u8Bit) );
}



DIO_ErrorStatus_t M_DIO_Void_TogglePinValue(u8 Copy_u8PinNum)
{
  DIO_ErrorStatus_t Local_Status = E_OK;

  if(Copy_u8PinNum < DIO_NUMBER_OF_ALL_PINS)
  {
    u8 Local_u8Port = Copy_u8PinNum >> 3;
    u8 Local_u8Bit  = Copy_u8PinNum & 7;

    TOG_BIT(*DIO_PORTArr[Local_u8Port], Local_u8Bit);
  }
  else
  {
    Local_Status = E_NOK;
  }

  return Local_Status;
}



DIO_ErrorStatus_t M_DIO_Void_SetPinPullUpRes(u8 Copy_u8PinNum, u8 Copy_u8ResState)
{
  DIO_ErrorStatus_t Local_Status = E_OK;

  if( (Copy_u8PinNum < DIO_NUMBER_OF_ALL_PINS) && ((Copy_u8ResState == DIO_PULLUP_ENABLED) || (Copy_u8ResState == DIO_PULLUP_DISABLED)) )
  {
    u8 Local_u8Port = Copy_u8PinNum >> 3;
    u8 Local_u8Bit  = Copy_u8PinNum & 7;

    CLR_BIT(*DIO_DDRArr[Local_u8Port], Local_u8Bit);

    WRITE_BIT(*DIO_PORTArr[Local_u8Port], Local_u8Bit, Copy_u8ResState);
  }
  else
  {
    Local_Status = E_NOK;
  }
  return Local_Status;
}


/*************************************************************************************/


DIO_ErrorStatus_t M_DIO_Void_SetPortDirection(u8 Copy_u8PortNum, u8 Copy_u8PortDir)
{
  DIO_ErrorStatus_t Local_Status = E_OK;

  if((Copy_u8PortNum < DIO_NUMBER_OF_PORTS) && ((Copy_u8PortDir == DIO_PORT_OUTPUT) || (Copy_u8PortDir == DIO_PORT_INPUT)) )
  {
    if(Copy_u8PortDir == DIO_PORT_INPUT)
    {
      *DIO_DDRArr[Copy_u8PortNum] = DIO_PORT_INPUT;
    }
    else
    {
      *DIO_DDRArr[Copy_u8PortNum] = DIO_PORT_OUTPUT;
    }
  }
  else
  {
    Local_Status = E_NOK;
  }

  return Local_Status;
}



DIO_ErrorStatus_t M_DIO_Void_SetPortValue(u8 Copy_u8PortNum, u8 Copy_u8PortVal)
{
  DIO_ErrorStatus_t Local_Status = E_OK;

  if(Copy_u8PortNum < DIO_NUMBER_OF_PORTS)
  {
    *DIO_PORTArr[Copy_u8PortNum] = Copy_u8PortVal;
  }
  else
  {
    Local_Status = E_NOK;
  }

  return Local_Status;
}



u8 M_DIO_U8_GetPortValue(u8 Copy_u8PortNum)
{
  return (*DIO_PINArr[Copy_u8PortNum]);
}



DIO_ErrorStatus_t M_DIO_Void_TogglePortValue(u8 Copy_u8PortNum)
{
  DIO_ErrorStatus_t Local_Status = E_OK;

  if(Copy_u8PortNum < DIO_NUMBER_OF_PORTS)
  {
    *DIO_PORTArr[Copy_u8PortNum] = ~(*DIO_PORTArr[Copy_u8PortNum]);
  }
  else
  {
    Local_Status = E_NOK;
  }

  return Local_Status;
}

