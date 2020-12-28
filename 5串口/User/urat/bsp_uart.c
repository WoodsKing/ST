#include "bsp_uart.h"

static void NVIC_usart_config(void)
{
	NVIC_InitTypeDef  NVIC_InitStruct;
	//配置NVIC结构体
	NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	//初始化结构体
	NVIC_Init(&NVIC_InitStruct);
	
}
void UART_s_config(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	USART_InitTypeDef 	USART_Struct;
	
	RCC_APB2PeriphClockCmd(DEBUG_USART_GPIO_CLK|DEBUG_USART_CLK, ENABLE);
	//TX
	GPIO_InitStruct.GPIO_Pin = DEBUG_USART_TX_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DEBUG_USART_TX_GPIO_PORT, &GPIO_InitStruct);
	//RX
	GPIO_InitStruct.GPIO_Pin = DEBUG_USART_RX_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;	
	GPIO_Init(DEBUG_USART_RX_GPIO_PORT, &GPIO_InitStruct);
	
	
	//波特率设置
	USART_Struct.USART_BaudRate = DEBUG_USART_BAUDRATE; 
	//模式
	USART_Struct.USART_Mode =  USART_Mode_Rx|USART_Mode_Tx;
	//字长
	USART_Struct.USART_WordLength = USART_WordLength_8b;
	//效验位
	USART_Struct.USART_Parity = USART_Parity_No;
	//硬件控制流
	USART_Struct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	//停止位
	USART_Struct.USART_StopBits = USART_StopBits_1;
	//初始化USART结构体
	USART_Init(USART1,&USART_Struct);
	//配置中断优先级
	NVIC_usart_config();
	//使能串口接收中断
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	//使能串口
	USART_Cmd(USART1,ENABLE);
}
void uart_sendbeyt(USART_TypeDef* pUSARTx, uint8_t Data)
{
	USART_SendData(pUSARTx,Data);
	while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TXE) == RESET);
}
