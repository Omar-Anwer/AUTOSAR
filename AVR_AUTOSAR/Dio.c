/*
 * Dio.c
 *
 *  Created on: Jul 15, 2023
 *      Author: O. A.
 * 
 * Description: Source file for Dio Module.
 * 
 */

#include "Dio.h"
#include "Dio_Regs.h"


#if (DIO_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and Dio Modules */
#if ((DET_AR_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
    || (DET_AR_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
    || (DET_AR_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Det.h does not match the expected version"
#endif

#endif

STATIC const Dio_ConfigChannel* Dio_PortChannels = NULL_PTR;
STATIC uint8 Dio_Status = DIO_NOT_INITIALIZED;



/************************************************************************************
 * Service Name:        Dio_Init
 * Service ID[hex]:     0x10
 * Sync/Async:          Synchronous
 * Reentrancy:          Non-reentrant
 * Parameters (in):     ConfigPtr - Pointer to post-build configuration data
 * Parameters (inout):  None
 * Parameters (out):    None
 * Return value:        None
 * Description:         Function to Initialize the Dio module.
 ************************************************************************************/
/* Function for DIO Initialization API */
void Dio_Init(const Dio_ConfigType* ConfigPtr)
{
#if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* check if the input configuration pointer is not a NULL_PTR */
  if (ConfigPtr == NULL_PTR)
  {
    Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_INIT_SID, DIO_E_PARAM_CONFIG);
  }
  else
#endif
  {
    /*
     * Set the module state to initialized and point to the PB configuration structure using a global pointer.
     * This global pointer is global to be used by other functions to read the PB configuration structures
     */
    Dio_PortChannels = ConfigPtr->Channels; /* address of the first Channels structure --> Channels[0] */
    Dio_Status       = DIO_INITIALIZED;
  }

}

/************************************************************************************
 * Service Name:       Dio_ReadChannel
 * Service ID[hex]:    0x00
 * Sync/Async:         Synchronous
 * Reentrancy:         Reentrant
 * Parameters (in):    ChannelId - ID of DIO channel.
 * Parameters (inout): None
 * Parameters (out):   None
 * Return value:       Dio_LevelType
 * Description:        Function to return the value of the specified DIO channel.
 ************************************************************************************/
/* Function for DIO read Channel API */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType const ChannelId)
{
  volatile Dio_PortLevelType* PortId_Ptr = NULL_PTR;
  Dio_LevelType PinState = STD_LOW;
  boolean   ErrorState = FALSE;

#if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Check if the Driver is initialized before using this function */
  if (Dio_Status == DIO_NOT_INITIALIZED)
  {
    Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_READ_CHANNEL_SID, DIO_E_UNINIT);
    ErrorState = TRUE;
  }
  else
  {
  }
  /* Check if the used channel is within the valid range */
  if (DIO_CONFIGURED_CHANNLES <= ChannelId)
  {
    Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_READ_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
    ErrorState = TRUE;
  }
  else
  {
  }
#endif

  if(ErrorState == FALSE)
  {
    /* In-case there are no errors */
    /* Point to the correct PIN register according to the Port Id stored in the PortIndex member */
    switch(Dio_PortChannels[ChannelId].PortIndex)
    {
      case DIO_PORTA:
        PortId_Ptr = &DIO_PINA_REG;
        break;
      case DIO_PORTB:
        PortId_Ptr = &DIO_PINB_REG;
        break;
      case DIO_PORTC:
        PortId_Ptr = &DIO_PINC_REG;
        break;
      case DIO_PORTD:
        PortId_Ptr = &DIO_PIND_REG;
        break;
    }

    /* Read the required channel */
    if(BIT_IS_SET(*PortId_Ptr, Dio_PortChannels[ChannelId].ChannelIndex))
    {
      PinState = STD_HIGH;
    }
    else
    {
      PinState = STD_LOW;
    }
  }
  else
  {
    /* No Action Required */
  }
  return PinState;
}

/************************************************************************************
 * Service Name:        Dio_WriteChannel
 * Service ID[hex]:     0x01
 * Sync/Async:          Synchronous
 * Reentrancy:          Reentrant
 * Parameters (in):     ChannelId - ID of DIO channel.
 *                      Level - Value to be written.
 * Parameters (inout):  None
 * Parameters (out):    None
 * Return value:        None
 * Description:         Function to set a level of a channel.
 ************************************************************************************/
/* Function for DIO write Channel API */
void Dio_WriteChannel(Dio_ChannelType const ChannelId, Dio_LevelType const Level)
{
  volatile uint8* PortId_Ptr = NULL_PTR;
  boolean ErrorState = FALSE;

#if (DIO_DEV_ERROR_DETECT == STD_ON)
  /* Check if the Driver is initialized before using this function */
  if (DIO_NOT_INITIALIZED == Dio_Status)
  {
    Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_WRITE_CHANNEL_SID, DIO_E_UNINIT);
    ErrorState = TRUE;
  }
  else
  {
  }
  /* Check if the used channel is within the valid range */
  if (DIO_CONFIGURED_CHANNLES <= ChannelId)
  {
    Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_WRITE_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
    ErrorState = TRUE;
  }
  else
  {
  }
#endif

  /* In-case there are no errors */
  if(ErrorState == FALSE)
  {
    /* Point to the correct PORT register according to the Port Id stored in the PortIndex member */
    switch(Dio_PortChannels[ChannelId].PortIndex)
    {
      case DIO_PORTA:
        PortId_Ptr = &DIO_PORTA_REG;
        break;
      case DIO_PORTB:
        PortId_Ptr = &DIO_PORTB_REG;
        break;
      case DIO_PORTC:
        PortId_Ptr = &DIO_PORTC_REG;
        break;
      case DIO_PORTD:
        PortId_Ptr = &DIO_PORTD_REG;
        break;
    }
    if(Level == STD_LOW)
    {
      CLR_BIT(*PortId_Ptr, Dio_PortChannels[ChannelId].ChannelIndex);  /* Write Logic Low */
    }
    else
    {
      SET_BIT(*PortId_Ptr, Dio_PortChannels[ChannelId].ChannelIndex); /* Write Logic High */
    }
  }
  else
  {
  }
}


/************************************************************************************
 * Service Name:        Dio_GetVersionInfo
 * Service ID[hex]:     0x12
 * Sync/Async:          Synchronous
 * Reentrancy:          Reentrant
 * Parameters (in):     None
 * Parameters (inout):  None
 * Parameters (out):    VersionInfo - Pointer to where to store the version information of this module.
 * Return value:        None
 * Description:         Function to get the version information of this module.
 ************************************************************************************/
#if (DIO_VERSION_INFO_API == STD_ON)
void Dio_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
  #if (DIO_DEV_ERROR_DETECT == STD_ON)
    /* Check if input pointer is not Null pointer */
    if(NULL_PTR == versioninfo)
    {
      /* Report to DET  */
      Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_GET_VERSION_INFO_SID, DIO_E_PARAM_POINTER);
    }
    else
  #endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
  {
    versioninfo->vendorID = (uint16)DIO_VENDOR_ID;  /* Copy the vendor Id */
    versioninfo->moduleID = (uint16)DIO_MODULE_ID;/* Copy the module Id */
    versioninfo->sw_major_version = (uint8)DIO_SW_MAJOR_VERSION; /* Copy Software Major Version */
    versioninfo->sw_minor_version = (uint8)DIO_SW_MINOR_VERSION; /* Copy Software Minor Version */
    versioninfo->sw_patch_version = (uint8)DIO_SW_PATCH_VERSION; /* Copy Software Patch Version */
  }
}
#endif


