#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
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

// ��ҵ

// ��KEY2�Ĵ���Ҳ��ɣ���һ�Σ�LED_R_TOGGLE

