#include "sysrcc.h"

void configg_rcc(uint32_t RCC_PLLMul_x)
{
	ErrorStatus HSEStatus;
	RCC_DeInit();
	
	RCC_HSEConfig(RCC_HSE_ON); //ʹ��HSE
	HSEStatus = RCC_WaitForHSEStartUp();
	if (HSEStatus == SUCCESS )
	{
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);//ʹ��Ԥȡַ
		FLASH_SetLatency(FLASH_Latency_2);//�ȴ�ʹ��Ԥȡַ
		
		RCC_HCLKConfig(RCC_SYSCLK_Div1);//����AHB
		RCC_PCLK1Config(RCC_HCLK_Div2); //����PCLK1
		RCC_PCLK2Config(RCC_HCLK_Div1); //����PCLK2
		
		RCC_PLLConfig( RCC_PLLSource_HSE_Div1,RCC_PLLMul_x);//�������໷ʱ��
		RCC_PLLCmd(ENABLE);//ʹ�����໷
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);//�ȴ�PLL�ȶ�
		
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);//����ϵͳʱ��ԴΪ���໷ʱ��	
		while(RCC_GetSYSCLKSource() != 0x08);
		
	}

	
	
	
	
	
	
	
}

