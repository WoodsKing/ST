#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "bsp_led.h"
#include "systick.h"
#include "bsp_uart.h"

void Delay( uint32_t count )
{
	for(; count!=0; count--);
}

int main(void)
{
	uint8_t		ch;
	LED_GPIO_Config();
	uart_config();
	while(1)
	{	
		ch = getchar();
		printf("%d",ch/2);
		if((ch%2)==0)	{LED_G(1);}
		else 		{LED_G(0);}
	}
}

// 作业

// 把KEY2的代码也完成，按一次，LED_R_TOGGLE

