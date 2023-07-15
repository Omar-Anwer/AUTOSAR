/*
* Std_Types.h
 *
 *  Created on: Jul 15, 2023
 *      Author: O. A.
 *
 * Description: Platform types for AVR
 *
 */
#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

/* Id for the company in the AUTOSAR EX. Vector = 31, Valeo = 7*/
#define PLATFORM_VENDOR_ID                          (7U)

/*
 * Module Version 1.0.0
 */
#define PLATFORM_SW_MAJOR_VERSION                   (1U)
#define PLATFORM_SW_MINOR_VERSION                   (0U)
#define PLATFORM_SW_PATCH_VERSION                   (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PLATFORM_AR_RELEASE_MAJOR_VERSION           (4U)
#define PLATFORM_AR_RELEASE_MINOR_VERSION           (0U)
#define PLATFORM_AR_RELEASE_PATCH_VERSION           (3U)

/*
 * CPU register type width
 */
#define CPU_TYPE_8        (8U)
#define CPU_TYPE_16       (16U)
#define CPU_TYPE_32       (32U)

/*
 * Bit order definition
 */
#define MSB_FIRST         (0U)    /* Big endian bit ordering */
#define LSB_FIRST         (1U)    /* Little endian bit ordering */

/*
 * Byte order definition
 */
#define HIGH_BYTE_FIRST   (0U)    /* Big endian bit ordering */
#define LOW_BYTE_FIRST    (1U)    /* Little endian bit ordering */

/*
 * Platform type and endianess definitions, specific for AVR ATmega32
 */
#define CPU_TYPE        CPU_TYPE_8
#define CPU_BIT_ORDER   LSB_FIRST
#define CPU_BYTE_ORDER  LOW_BYTE_FIRST

/*
 * Boolean Values
 */
#ifndef TRUE
 #define TRUE              ((boolean) 1)
#endif

#ifndef FALSE
 #define FALSE             ((boolean) 0)
#endif

#ifndef NULL
 #define NULL ((void*) 0)
#endif

typedef unsigned char      boolean;

typedef unsigned char       uint8;        /*              0 .. 255			                  */
typedef signed char         sint8;        /*           -128 .. +127			                  */
typedef unsigned short      uint16;       /*              0 .. 65,535			                */
typedef signed short        sint16;       /*        -32,768 .. +32,767			              */
typedef unsigned long       uint32;       /*              0 .. +4,294,967,295		          */
typedef signed long         sint32;       /* -21,47,483,648 .. +2,147,483,647		          */
typedef unsigned long long  uint64;       /*              0 .. +18,446,744,073,709,551,615 */
typedef signed long long    sint64;
typedef float               float32;
typedef double              float64;

#endif /* PLATFORM_TYPES_H_ */
