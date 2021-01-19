#ifndef __BSP_UART_H
#define __BSP_UART_H

#include "stm32f10x_usart.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "misc.h"
#include <stdio.h>

//TX、RX宏定义
#define USART_TX_PORT    GPIOA
#define USART_TX_Pin	GPIO_Pin_9
#define USART_TX_clok	RCC_APB2Periph_GPIOA

#define USART_RX_PORT 	GPIOA	
#define USART_RX_Pin	GPIO_Pin_10
#define USART_RX_clok	RCC_APB2Periph_GPIOA
//UART宏定义
#define USARTX 		USART1
#define USARTX_clok      RCC_APB2Periph_USART1
#define USART_Boto		115200

void uart_config(void);
void sendbeyt(USART_TypeDef* USARTx,uint8_t Data);


#endif
