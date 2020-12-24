#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "bsp_led.h"
#include "bsp_exti.h"
void Delay( uint32_t count )
{
	for(; count!=0; count--);
}

int main(void)
{
	LED_GPIO_Config();
	KEY_EXTI_config();
	while(1)
	{		
		
	}
}

// 作业

// 把KEY2的代码也完成，按一次，LED_R_TOGGLE

