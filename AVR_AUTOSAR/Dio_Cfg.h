/*
 * Dio_Cfg.h
 *
 *  Created on: Jul 15, 2023
 *      Author: O. A.
 * 
 * Description: Pre-Compile Configuration Header file for Dio Module. (Auto generated file)
 * 
 */
#ifndef DIO_CFG_H_
#define DIO_CFG_H_

/*
 * Module Version 1.0.0
 */
#define DIO_CFG_SW_MAJOR_VERSION              (1U)
#define DIO_CFG_SW_MINOR_VERSION              (0U)
#define DIO_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define DIO_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define DIO_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define DIO_CFG_AR_RELEASE_PATCH_VERSION     (3U)


/* Pre-compile option for Development Error Detect */
#define DIO_DEV_ERROR_DETECT                (STD_ON)  /*because we checked it from tool while configuration (DioGeneral Container)*/

/* Pre-compile option for Version Info API */
#define DIO_VERSION_INFO_API                (STD_OFF)

/* Pre-compile option for presence of Dio_FlipChannel API */
#define DIO_FLIP_CHANNEL_API                (STD_ON)



/* Number of the configured Dio Channels */
#define DIO_CONFIGURED_CHANNLES             (2U)

/* Number of the configured Dio Ports */
#define DIO_CONFIGURED_PORTS                (2U)



/* Channel Index in the array of structures in Dio_PBcfg.c */
#define DioConf_LED_CHANNEL_ID_INDEX        ((uint8)0x00)
#define DioConf_BUTTON_CHANNEL_ID_INDEX     ((uint8)0x01)

/* DIO Configured Port ID's  */
#define DioConf_LED_PORT_NUM                ((Dio_PortType)DIO_PORTC) /* PORTC */
#define DioConf_BUTTON_PORT_NUM             ((Dio_PortType)DIO_PORTD) /* PORTD */

/* DIO Configured Channel ID's */
#define DioConf_LED_CHANNEL_NUM             ((Dio_ChannelType)DIO_CHANNEL5) /* Pin 5 in PORTC */
#define DioConf_BUTTON_CHANNEL_NUM          ((Dio_ChannelType)DIO_CHANNEL2) /* Pin 2 in PORTD */

#endif /* DIO_CFG_H_ */
