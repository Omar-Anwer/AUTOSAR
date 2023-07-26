/*
 * Std_Types.h
 *
 *  Created on: Jun 27, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */
#ifndef LIB_STD_TYPES_H_
#define LIB_STD_TYPES_H_


typedef unsigned char                  u8;
typedef signed char                    s8;

typedef unsigned short int            u16;
typedef signed short int              s16;

typedef unsigned long  int            u32;
typedef signed long  int              s32;

typedef unsigned long long int        u64;
typedef signed long long int          s64;

typedef float                         f32;
typedef double                        f64;

/******************************************/

typedef unsigned char                  uint8;
typedef signed char                    sint8;

typedef unsigned short int            uint16;
typedef signed short int              sint16;

typedef unsigned long  int            uint32;
typedef signed long  int              sint32;

typedef unsigned long long int        uint64;
typedef signed long long int          sint64;

typedef float                         float32;
typedef double                        float64;

/******************************************/

#ifndef TRUE
 #define TRUE              (1U)
#endif

#ifndef FALSE
 #define FALSE             (0U)
#endif

#ifndef DISABLED
 #define DISABLED                 (0U)
#endif

#ifndef ENABLED
 #define ENABLED                  (1U)
#endif

#ifndef OFF
 #define OFF                     (0U)
#endif

#ifndef ON
 #define ON                      (1U)
#endif

#ifndef NULL
 #define NULL              ((void*) 0)
#endif

#endif /* LIB_STD_TYPES_H_ */
