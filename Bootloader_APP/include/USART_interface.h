/**************************************************************/
/***********     Author    :  Mokhtar                **********/
/***********     Version   :  V0.1                   **********/
/***********     Date      :  26-11-2022             **********/
/**************************************************************/

#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

void USART1_vidInit (void);
void USART1_vidTransmit(u8 data);
void USART1_vidEnableClock(void);
void USART1_vidEnableRecieveInterrupt(void (*copy_ptr)(u8 x));
void USART1_vidDisableRecieveInterrupt();
#endif
