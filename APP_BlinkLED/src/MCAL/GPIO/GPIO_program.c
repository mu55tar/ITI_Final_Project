/**************************************************************/
/***********     Author    :  Mokhtar                **********/
/***********     Version   :  V0.1                   **********/
/***********     Date      :  26-11-2022             **********/
/**************************************************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"


#include "GPIO_interface.h"
#include "GPIO_config.h"
#include "GPIO_private.h"





void GPIO_writepinDirection(u8 cpy_u8portNo ,u8 cpy_u8pinNO,u8 cpy_u8Dir)
{
	switch(cpy_u8portNo)
	{
	case GPIO_PORTA:
		if (cpy_u8pinNO<8)
		{
			GPIOA->CRL &=~((0b1111)<<(4*cpy_u8pinNO));
			GPIOA->CRL |=(cpy_u8Dir << (4*cpy_u8pinNO));
		}
		else if (cpy_u8pinNO<16)
		{
			GPIOA->CRH &=~((0b1111)<<(4*(cpy_u8pinNO-8)));
			GPIOA->CRH |=(cpy_u8Dir << (4*(cpy_u8pinNO-8)));

		}
		break;
	case GPIO_PORTB:
			if (cpy_u8pinNO<8)
			{
				GPIOB->CRL &=~((0b1111)<<(4*cpy_u8pinNO));
				GPIOB->CRL |=(cpy_u8Dir << (4*cpy_u8pinNO));
			}
			else if (cpy_u8pinNO<16)
			{
				GPIOB->CRH &=~((0b1111)<<(4*(cpy_u8pinNO-8)));
				GPIOB->CRH |=(cpy_u8Dir << (4*(cpy_u8pinNO-8)));

			}
			break;
	case GPIO_PORTC:
			if (cpy_u8pinNO<8)
			{
				GPIOC->CRL &=~((0b1111)<<(4*cpy_u8pinNO));
				GPIOC->CRL |=(cpy_u8Dir << (4*cpy_u8pinNO));
			}
			else if (cpy_u8pinNO<16)
			{
				GPIOC->CRH &=~((0b1111)<<(4*(cpy_u8pinNO-8)));
				GPIOC->CRH |=(cpy_u8Dir << (4*(cpy_u8pinNO-8)));

			}
			break;



	}

}
void GPIO_writepinValue(u8 cpy_u8portNo ,u8 cpy_u8pinNO,u8 cpy_u8val)
{

	if(cpy_u8pinNO <16)
	{

	if(cpy_u8val == GPIO_HIGH)
	{
	switch(cpy_u8portNo)
		{
		case GPIO_PORTA:
			SET_BIT(GPIOA->ODR,cpy_u8pinNO);
			break;
		case GPIO_PORTB:
			SET_BIT(GPIOB->ODR,cpy_u8pinNO);
			break;
		case GPIO_PORTC:
			SET_BIT(GPIOC->ODR,cpy_u8pinNO);
			break;
		}

	}
	else if(cpy_u8val == GPIO_LOW)
	{
		switch(cpy_u8portNo)
				{
				case GPIO_PORTA:
					CLR_BIT(GPIOA->ODR,cpy_u8pinNO);
					break;
				case GPIO_PORTB:
					CLR_BIT(GPIOB->ODR,cpy_u8pinNO);
					break;
				case GPIO_PORTC:
					CLR_BIT(GPIOC->ODR,cpy_u8pinNO);
					break;
				}
	}
	}




}
u8 GPIO_GETpinValue(u8 cpy_u8portNo ,u8 cpy_u8pinNO)
{
	u8 pin_value=0;
	if(cpy_u8pinNO <16)
		{

	switch(cpy_u8portNo)
					{
					case GPIO_PORTA:
						pin_value=GET_BIT(GPIOA->IDR,cpy_u8pinNO);
						break;
					case GPIO_PORTB:
						pin_value=GET_BIT(GPIOB->IDR,cpy_u8pinNO);
						break;
					case GPIO_PORTC:
						pin_value=GET_BIT(GPIOC->IDR,cpy_u8pinNO);
						break;
					}

		}
	return pin_value;
}

//.........................
void GPIO_vidPortDirection_High(u8 cpy_u8portNo,u8 cpy_u8Dir)
{




}
void GPIO_vidPortDirection_Low(u8 cpy_u8portNo,u8 cpy_u8Dir)
{

}
void GPIO_vidPortValue_HIGH(u8 cpy_u8portNo,u8 cpy_u8val)
{

}
void GPIO_vidPortValue_Low(u8 cpy_u8portNo,u8 cpy_u8val)
{

}


