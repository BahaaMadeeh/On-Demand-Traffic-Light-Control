/*
 * BIT_MATHS.h
 *
 * Created: 9/5/2022 5:42:55 PM
 *  Author: Bahaa Madeeh
 */


#ifndef BIT_MATHS_H_
#define BIT_MATHS_H_
#include <math.h>


#define SET_BIT(REG,BITNO) REG |=  (1 << (BITNO))
#define CLEAR_BIT(REG,BITNO) REG&=~(1<<BITNO)
#define TOG_BIT(REG,BITNO) REG ^=  (1 << (BITNO))
#define GET_BIT(REG,BITNO) (REG&(1<<BITNO))>>BITNO     //(((REG) >> (BITNO)) & 0x01)



#endif /* BIT_MATHS_H_ */
