#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "bsp_led.h"
#include "sysrcc.h"
void Delay( uint32_t count )
{
	for(; count!=0; count--);
}

int main(void)
{
	// ���������ʱ��ϵͳ��ʱ���Ѿ������ó�72M��
	configg_rcc( RCC_PLLMul_4);
	LED_GPIO_Config();
	
	while(1)
	{
		
		LED_G(0x01);
		Delay(0xfffff);
		LED_G(0x00);
		Delay(0xfffff);			
		
	}
}

// ��ҵ

// ��KEY2�Ĵ���Ҳ��ɣ���һ�Σ�LED_R_TOGGLE

