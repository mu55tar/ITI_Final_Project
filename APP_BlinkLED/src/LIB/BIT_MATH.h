#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(x,b)  ((x)|= (1<<(b)))
#define CLR_BIT(x,b)  ((x)&=~(1<<(b)))
#define TOG_BIT(x,b)  ((x)^= (1<<(b)))
#define GET_BIT(x,b)  (((x)>>(b))&1)

#endif
