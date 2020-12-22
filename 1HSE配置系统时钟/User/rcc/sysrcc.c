#include "sysrcc.h"

void configg_rcc(uint32_t RCC_PLLMul_x)
{
	ErrorStatus HSEStatus;
	RCC_DeInit();
	
	RCC_HSEConfig(RCC_HSE_ON); //使能HSE
	HSEStatus = RCC_WaitForHSEStartUp();
	if (HSEStatus == SUCCESS )
	{
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);//使能预取址
		FLASH_SetLatency(FLASH_Latency_2);//等待使能预取址
		
		RCC_HCLKConfig(RCC_SYSCLK_Div1);//配置AHB
		RCC_PCLK1Config(RCC_HCLK_Div2); //配置PCLK1
		RCC_PCLK2Config(RCC_HCLK_Div1); //配置PCLK2
		
		RCC_PLLConfig( RCC_PLLSource_HSE_Div1,RCC_PLLMul_x);//配置锁相环时钟
		RCC_PLLCmd(ENABLE);//使能锁相环
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);//等待PLL稳定
		
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);//设置系统时钟源为锁相环时钟	
		while(RCC_GetSYSCLKSource() != 0x08);
		
	}

	
	
	
	
	
	
	
}

