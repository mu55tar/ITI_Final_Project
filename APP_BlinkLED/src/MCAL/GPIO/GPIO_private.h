/**************************************************************/
/***********     Author    :  Mokhtar                **********/
/***********     Version   :  V0.1                   **********/
/***********     Date      :  26-11-2022             **********/
/**************************************************************/
#ifndef MCAL_GPIO_GPIO_PRIVATE_H_
#define MCAL_GPIO_GPIO_PRIVATE_H_

#define GPIOA_Base_ADDR 0x40010800
#define GPIOB_Base_ADDR 0x40010C00
#define GPIOC_Base_ADDR 0x40011000

typedef struct
{
	volatile u32 CRL;
	volatile u32 CRH;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 BRR;
	volatile u32 LCkR;
}GPIO_MemMap;

#define GPIOA ((volatile GPIO_MemMap*)(GPIOA_Base_ADDR))
#define GPIOB ((volatile GPIO_MemMap*)(GPIOB_Base_ADDR))
#define GPIOC ((volatile GPIO_MemMap*)(GPIOC_Base_ADDR))




#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
