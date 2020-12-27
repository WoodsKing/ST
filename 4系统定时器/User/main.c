#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "bsp_led.h"
#include "systick.h"

void Delay( uint32_t count )
{
	for(; count!=0; count--);
}

int main(void)
{
	LED_GPIO_Config();
	while(1)
	{		
		LED_G(1);
		sysdelay_us(500);
		LED_G(0);
		sysdelay_us(3000);
	}
}

// 作业

// 把KEY2的代码也完成，按一次，LED_R_TOGGLE

