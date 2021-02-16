#ifndef	__BSP_DMA_H
#define	__BSP_DAM_H

#include "stm32f10x.h"
#define sezi 4

extern uint32_t buff_s[sezi];
extern const uint32_t buff_f[sezi];						
void config_dma(void);
#endif
