#include "bsp_dam.h"

//Êý¾Ý´¢´æÔÚflash
const uint32_t buff_f[sezi] = {
						0x01020304,0x05060708,0x090A0B0C,0x0D0E0F10
						};
uint32_t buff_s[sezi];

						
void config_dma(void)
{
	DMA_InitTypeDef DMA_struct;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	
	DMA_struct.DMA_PeripheralBaseAddr  = (uint32_t)buff_f;
	DMA_struct.DMA_MemoryBaseAddr		= (uint32_t)buff_s;
	DMA_struct.DMA_DIR				= DMA_DIR_PeripheralSRC;
	
	DMA_struct.DMA_BufferSize		= sezi;
	
	DMA_struct.DMA_PeripheralInc		= DMA_PeripheralInc_Enable;
	DMA_struct.DMA_PeripheralDataSize	= DMA_PeripheralDataSize_Word;
	DMA_struct.DMA_MemoryInc			= DMA_MemoryInc_Enable;
	DMA_struct.DMA_MemoryDataSize		= DMA_MemoryDataSize_Word;
	
	DMA_struct.DMA_Mode				= DMA_Mode_Normal;
	DMA_struct.DMA_Priority			= DMA_Priority_High;
	DMA_struct.DMA_M2M				= DMA_M2M_Enable;
	
	DMA_Init(DMA1_Channel2,&DMA_struct);
	DMA_Cmd(DMA1_Channel2,ENABLE);
	
}
