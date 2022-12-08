/*
 * SYSTK_program.c
 *
 *  Created on: Oct 22, 2022
 *      Author: elgendy
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "SYSTK_interface.h"
#include "SYSTK_config.h"
#include "SYSTK_private.h"

#define NULL 0
static u8 singelflag ;
static void (*STK_callback)(void);

void STK_vidInit(void)
{
	/*clock source selection*/
	 CLR_BIT(STK->CTRL,2);
	 /* interrupt enable /disable
	 */
#if STK_INTERRUPT_ENABLE == ENABLE
	 SET_BIT(STK->CTRL,1);
#elif STK_INTERRUPT_ENABLE == DISABLE
	 CLR_BIT(STK->CTRL,1);
#endif

}
void STK_vidSetBusyWait(u32 cpy_u32TimerTicks)
{

/*Clear timer value regester */
	STK->VAL= 0;
 /* reload the timer ticks in load regester */
	STK->LOAD = cpy_u32TimerTicks;

 /* start timer*/
	SET_BIT(STK->CTRL,0);

 /* poll on count flag
 */
	while(GET_BIT(STK->CTRL,16)!=1){};
	/*clear flag and clear count flag*/
	CLR_BIT(STK->CTRL,0);
	STK->VAL= 0;


}
void STK_vidSetInterval_single(u32 cpy_u32TimerTicks,void (*fbtr)(void))
{
	singelflag =1;
	STK_callback = fbtr;


	/*Clear timer value regester */
		STK->VAL= 0;
	 /* reload the timer ticks in load regester */
		STK->LOAD = cpy_u32TimerTicks;

	 /* start timer*/
		SET_BIT(STK->CTRL,0);
}
void STK_vidSetInterval_periodic(u32 cpy_u32TimerTicks,void (*fbtr)(void))
{
	singelflag = 0;
	STK_callback = fbtr;
	/*Clear timer value regester */
		STK->VAL= 0;
	 /* reload the timer ticks in load regester */
		STK->LOAD = cpy_u32TimerTicks;

	 /* start timer*/
		SET_BIT(STK->CTRL,0);
}
void STK_StopTimer(void)
{
	CLR_BIT(STK->CTRL,0);
}
u32 STK_u32GetELapsedTime(void)
{

return STK->LOAD - STK->VAL;


}
u32 STK_u32GetReamainigTime(void)
{
	return STK->VAL ;
}

void SysTick_Handler(void)
{
	if (STK_callback !=NULL)
	{
		if (singelflag)
		{
			singelflag = 0;
			STK->VAL =0;
			CLR_BIT(STK->CTRL,0);

		}
		STK_callback();
	}
}
