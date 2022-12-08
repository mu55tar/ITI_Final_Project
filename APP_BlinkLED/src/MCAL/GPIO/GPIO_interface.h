/**************************************************************/
/***********     Author    :  Mokhtar                **********/
/***********     Version   :  V0.1                   **********/
/***********     Date      :  26-11-2022             **********/
/**************************************************************/
#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

#define OUTPUT_2MHz_GPPP 0b0010
#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2

#define GPIO_PIN0  0
#define GPIO_PIN1	1
#define GPIO_PIN2	2

typedef enum
{
	mGPIO_PORTA,
	mGPIO_PORTB,
	mGPIO_PORTC

}GPIO_Port_t;

typedef enum
{
	mGPIO_PIN0,
	mGPIO_PIN1,
	mGPIO_PIN2,
	mGPIO_PIN3,
	mGPIO_PIN4,
	mGPIO_PIN5

}GPIO_PIN_t;

typedef enum
{
	mGPIO_2MHZ,
	mGPIO_10MHZ,
	mGPIO_50MHZ

}GPIO_OutputSpeed_t;

//typedef enum
//{
//	GPIO_Port_t port;
//	GPIO_Pin_t Pin;
//
//
//}GPIO_mode_t;


#define GPIO_HIGH 1
#define GPIO_LOW  0


void GPIO_writepinDirection(u8 cpy_u8portNo ,u8 cpy_u8pinNO,u8 cpy_u8Dir);
void GPIO_writepinValue(u8 cpy_u8portNo ,u8 cpy_u8pinNO,u8 cpy_u8val);
u8 GPIO_GETpinValue(u8 cpy_u8portNo ,u8 cpy_u8pinNO);
void GPIO_vidPortDirection_High(u8 cpy_u8portNo,u8 cpy_u8Dir);
void GPIO_vidPortDirection_Low(u8 cpy_u8portNo,u8 cpy_u8Dir);
void GPIO_vidPortValue_HIGH(u8 cpy_u8portNo,u8 cpy_u8val);
void GPIO_vidPortValue_Low(u8 cpy_u8portNo,u8 cpy_u8val);

#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
