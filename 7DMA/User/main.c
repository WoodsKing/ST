#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "bsp_led.h"
#include "systick.h"
#include "bsp_dam.h"
void Delay( uint32_t count )
{
	for(; count!=0; count--);
}

int main(void)
{
	LED_GPIO_Config();
	config_dma();
	Delay(0xfffff);
	while(buff_s[1]==buff_f[1])
	{		
			if(buff_s[2]==buff_f[2]) {LED_G(0);}
			else	{LED_G(1);}
	}
}

// ��ҵ

// ��KEY2�Ĵ���Ҳ��ɣ���һ�Σ�LED_R_TOGGLE

