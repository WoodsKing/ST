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
	
	//���������������
	GPIO_InitStruct.GPIO_Pin = USART_TX_Pin;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(USART_TX_PORT,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin = USART_RX_Pin;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(USART_RX_PORT,&GPIO_InitStruct);
	//�����ж����ȼ�
	NVIC_config();

	//USART����
	USART_InitStruct.USART_BaudRate 			= USART_Boto;
	USART_InitStruct.USART_WordLength 			= USART_WordLength_8b;
	USART_InitStruct.USART_StopBits 			= USART_StopBits_1;
	USART_InitStruct.USART_Mode				= USART_Mode_Rx|USART_Mode_Tx;
	USART_InitStruct.USART_Parity				= USART_Parity_No;
	USART_InitStruct.USART_HardwareFlowControl 	= USART_HardwareFlowControl_None;
	USART_Init(USARTX,&USART_InitStruct);
	//�����ж����ȼ�
	NVIC_config();	
	//ʹ�ܴ��ڽ����ж�
//	USART_ITConfig(USARTX,USART_IT_RXNE,ENABLE);	//���ʹ������յ���������ת�������жϷ�����
	//ʹ�ܴ���
	USART_Cmd(USARTX,ENABLE);	
}

void sendbeyt(USART_TypeDef* pUSARTx,uint8_t Data)
{
	USART_SendData(pUSARTx,Data);
	while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TXE) == RESET);
}
///�ض��� c �⺯�� printf �����ڣ��ض�����ʹ�� printf ����
int fputc(int ch, FILE *f)
{
	/* ����һ���ֽ����ݵ����� */
	USART_SendData(USARTX, (uint8_t) ch);

	/* �ȴ�������� */
	while (USART_GetFlagStatus(USARTX, USART_FLAG_TXE) == RESET);
	return (ch);
}

//�ض��� c �⺯�� scanf �����ڣ���д����ʹ�� scanf�� getchar �Ⱥ���
int fgetc(FILE *f)
{
/* �ȴ������������� */
	while (USART_GetFlagStatus(USARTX, USART_FLAG_RXNE) == RESET);
	return (int)USART_ReceiveData(USARTX);
}
