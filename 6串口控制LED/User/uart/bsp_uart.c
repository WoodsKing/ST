#include "bsp_uart.h"
static void NVIC_config(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel 				= USART1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd 			= ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority		= 1;
	NVIC_Init(&NVIC_InitStruct);
}
void uart_config(void)
{
	
	USART_InitTypeDef	USART_InitStruct;
	GPIO_InitTypeDef	GPIO_InitStruct;
	
	//RCC_APB1PeriphResetCmd(USART_TX_clok|USART_TX_clok,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|USART_TX_clok,ENABLE);
	
	//输入输出引脚配置
	GPIO_InitStruct.GPIO_Pin = USART_TX_Pin;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(USART_TX_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin = USART_RX_Pin;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(USART_RX_PORT,&GPIO_InitStruct);
	//配置中断优先级
	NVIC_config();

	//USART配置
	USART_InitStruct.USART_BaudRate 			= USART_Boto;
	USART_InitStruct.USART_WordLength 			= USART_WordLength_8b;
	USART_InitStruct.USART_StopBits 			= USART_StopBits_1;
	USART_InitStruct.USART_Mode				= USART_Mode_Rx|USART_Mode_Tx;
	USART_InitStruct.USART_Parity				= USART_Parity_No;
	USART_InitStruct.USART_HardwareFlowControl 	= USART_HardwareFlowControl_None;
	USART_Init(USARTX,&USART_InitStruct);
	//配置中断优先级
	NVIC_config();	
	//使能串口接收中断
//	USART_ITConfig(USARTX,USART_IT_RXNE,ENABLE);	//如果使能则接收到数据则跳转至串口中断服务函数
	//使能串口
	USART_Cmd(USARTX,ENABLE);	
}

void sendbeyt(USART_TypeDef* pUSARTx,uint8_t Data)
{
	USART_SendData(pUSARTx,Data);
	while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TXE) == RESET);
}
///重定向 c 库函数 printf 到串口，重定向后可使用 printf 函数
int fputc(int ch, FILE *f)
{
	/* 发送一个字节数据到串口 */
	USART_SendData(USARTX, (uint8_t) ch);

	/* 等待发送完毕 */
	while (USART_GetFlagStatus(USARTX, USART_FLAG_TXE) == RESET);
	return (ch);
}

//重定向 c 库函数 scanf 到串口，重写向后可使用 scanf、 getchar 等函数
int fgetc(FILE *f)
{
/* 等待串口输入数据 */
	while (USART_GetFlagStatus(USARTX, USART_FLAG_RXNE) == RESET);
	return (int)USART_ReceiveData(USARTX);
}
