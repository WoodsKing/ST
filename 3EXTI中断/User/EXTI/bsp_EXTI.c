#include "bsp_exti.h"
static void EXTI_NVIC_config(void)
{
	NVIC_InitTypeDef  NVIC_InitStruct;
	
	NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);
}
void KEY_EXTI_config(void)
{
	
	GPIO_InitTypeDef  GPIO_InitStruct;
	EXTI_InitTypeDef EXTI_struct;
	//配置中断优先级
	EXTI_NVIC_config();
	//挂载端口PORTA.0在EXTI0上
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0);
	//使能GPIO
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO, ENABLE);
	//配置GPIO结构体
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;       
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	//初始化结构体
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	//配置EXTI结构体
	EXTI_struct.EXTI_Line = EXTI_Line0;
	EXTI_struct.EXTI_LineCmd = ENABLE;
	EXTI_struct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_struct.EXTI_Trigger = EXTI_Trigger_Rising;
	//初始化EXTI结构体
	EXTI_Init(&EXTI_struct);
	
}
