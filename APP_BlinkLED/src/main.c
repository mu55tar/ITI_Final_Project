#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "RCC/RCC_Interface.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/systk/SYSTK_interface.h"
//delay (d) in milli seconds
#define ARM_delay(d) \
	do{u32 i=500*d;\
while(i--){asm("nop");}\
}while(0)

//d =500*d

int main(void)
{

	RCC_voidInit();

	RCC_voidEnableClock(RCC_APB2,2);

	GPIO_writepinDirection(GPIO_PORTA,GPIO_PIN0,OUTPUT_2MHz_GPPP);
	GPIO_writepinDirection(GPIO_PORTA,GPIO_PIN1,OUTPUT_2MHz_GPPP);
	GPIO_writepinDirection(GPIO_PORTA,GPIO_PIN2,OUTPUT_2MHz_GPPP);


	while(1)
	{
		GPIO_writepinValue(GPIO_PORTA,GPIO_PIN2,GPIO_HIGH);
		GPIO_writepinValue(GPIO_PORTA,GPIO_PIN0,GPIO_HIGH);
		GPIO_writepinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
		STK_vidSetBusyWait(1000000);
		GPIO_writepinValue(GPIO_PORTA,GPIO_PIN0,GPIO_LOW);
		GPIO_writepinValue(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);
		STK_vidSetBusyWait(1000000);





	}
}
