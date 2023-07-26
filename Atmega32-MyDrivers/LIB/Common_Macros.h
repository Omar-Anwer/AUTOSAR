/*
 * Utils.h
 *
 *  Created on: Jun 27, 2023
 *      Author: O. A.
 * 
 * Description:
 * 
 */
#ifndef LIB_COMMON_MACROS_H_
#define LIB_COMMON_MACROS_H_

/* Non AUTOSAR files */

/* Bit Macros */

#define SET_BIT(REG, BIT)           (   (REG) |=  (1 << (BIT) )  )
#define CLR_BIT(REG, BIT)           (   (REG) &= ~(1 << (BIT) )  )
#define TOG_BIT(REG, BIT)           (   (REG) ^=  (1 << (BIT) )  )
#define GET_BIT(REG, BIT)           ( ( (REG) >>  (BIT) )  &  1  )

#define WRITE_BIT(REG, BIT, VAL)    (REG = (REG & (~(1 << BIT) ) ) | (VAL << BIT))

#define ROR(REG, NUM)               ( REG = (REG >> NUM) | (REG << (sizeof(REG) * 8) - NUM) )
#define ROL(REG, NUM)               ( REG = (REG << NUM) | (REG >> (sizeof(REG) * 8) - NUM) )

#define BIT_IS_SET(REG, BIT)        (    ( (REG) >> (BIT) )  &  1   )
#define BIT_IS_CLEAR(REG, BIT)      ( !( ( (REG) >> (BIT) )  & 1  ) )

#define GET_LOWER_NIBBLE(REG)       ( (REG) & 0x0F )
#define GET_HIGHER_NIBBLE(REG)      ( (REG) & 0xF0 )

/**
 * #define clr_low_nible(reg ) reg&= 0xf0
#define set_low_nible(reg )  reg|=0x0f
#define toggle_low_nible(reg) reg^=0x0f
#define assign_low_nible(reg,value) reg=(reg&0xf0)|(value&0x0f)
#define get_high_nible(reg) (reg& 0x0f )>> 4
#define clr_high_nible(reg) reg&=0x0f
#define set_high_nible(reg) reg|=0xf0
#define toggle_high_nible(reg) reg^=0xf0
#define assign_high_nible(reg,value) reg=(reg&0x0f)|(value<<4)
 */


#endif /* LIB_COMMON_MACROS_H_ */
