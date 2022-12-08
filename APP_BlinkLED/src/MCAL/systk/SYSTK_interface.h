/*
 * SYSTK_interface.h
 *
 *  Created on: Oct 22, 2022
 *      Author: elgendy
 */

#ifndef SYSTK_SYSTK_INTERFACE_H_
#define SYSTK_SYSTK_INTERFACE_H_


void STK_vidInit(void);
void STK_vidSetBusyWait(u32 cpy_u32TimerTicks);


u32 STK_u32GetReamainigTime(void);
u32 STK_u32GetELapsedTime(void);
void STK_StopTimer(void);
void STK_vidSetInterval_periodic(u32 cpy_u32TimerTicks,void (*fbtr)(void));
void STK_vidSetInterval_single(u32 cpy_u32TimerTicks,void (*fbtr)(void));
#endif /* SYSTK_SYSTK_INTERFACE_H_ */
