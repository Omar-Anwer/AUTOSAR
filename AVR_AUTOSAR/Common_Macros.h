#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

/* Non-AUTOSAR files */
/* Description: Commonly used Macros */


/* Set a certain bit in any register */
#define SET_BIT(REG, BIT)			( REG |= (1<<BIT) )

 /* Clear a certain bit in any register */
#define CLR_BIT(REG, BIT)			( REG &= ~(1<<BIT))

/* Toggle a certain bit in any register */
#define TOG_BIT(REG, BIT)		  ( REG ^= (1<<BIT) )

/* Return the value of a specific bit */
#define GET_BIT(REG, BIT)			( (REG >> BIT) & 1)

/**/
#define WRITE_BIT(REG, BIT, VAL)	( CLEAR_BIT( (REG), (BIT) ) | (VAL << BIT) )

/* Rotate right the register value with specific number of rotates */
#define ROR(REG, NUM)           	( REG = (REG >> NUM) | (REG << (sizeof(REG) * 8) - NUM) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG, NUM)				      ( REG = (REG << NUM) | (REG >> (sizeof(REG ) *8) - NUM) )

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG, BIT)		  ( (REG >> BIT) & 1 )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLR(REG, BIT)		( !((REG >> BIT) & 1) )

#endif /* COMMON_MACROS_H_ */
