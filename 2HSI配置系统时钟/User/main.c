#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "bsp_led.h"
#include "sysrcc.h"
void Delay( uint32_t count )
{
	for(; count!=0; count--);
}

int main(void)
{
	// 来到这里的时候，系统的时钟已经被配置成72M。
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

// 作业

// 把KEY2的代码也完成，按一次，LED_R_TOGGLE

