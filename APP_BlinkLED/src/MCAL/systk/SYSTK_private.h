/*
 * SYSTK_private.h
 *
 *  Created on: Oct 22, 2022
 *      Author: elgendy
 */

#ifndef SYSTK_SYSTK_PRIVATE_H_
#define SYSTK_SYSTK_PRIVATE_H_
#define ENABLE 1
#define DISABLE 0



#define STK_BASE_ADDRESS 0xE000E010

typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;

}STK_MemMap_t;


#define STK ((volatile STK_MemMap_t *)STK_BASE_ADDRESS)
#endif /* SYSTK_SYSTK_PRIVATE_H_ */
