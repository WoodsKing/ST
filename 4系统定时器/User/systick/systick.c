#include "stm32f10x.h"
#include "systick.h"

void sysdelay_us(uint32_t us)
{
	uint32_t i;
	SysTick_Config(72);
	for(i=0;i<us;i++)
	{
		while( !((SysTick->CTRL) & 1<<16) );
	}
	SysTick->CTRL &= ~SysTick_CALIB_NOREF_Msk;
} 

void sysdelay_ms(uint32_t us)
{
	uint32_t i;
	SysTick_Config(72);
	for(i=0;i<us;i++)
	{
		while( !((SysTick->CTRL) & 1<<16) );
	}
	SysTick->CTRL &= ~SysTick_CALIB_NOREF_Msk;
} 
