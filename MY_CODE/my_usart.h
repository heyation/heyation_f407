#ifndef __MY_USART_H_
#define __MY_USART_H_

#include "ALLHeader.h"
/******************************************************************************************
*                        @硬件实现层
******************************************************************************************/

void __usart_configuration(uint32_t usart_bound);
void __usart_dma_tx_configuration(void);
void __usart_init(void);
	
void __usart2_send_byte(uint8_t Byte);
void __usart2_send_array(uint8_t *Arr, uint8_t Length);
void __usart_dma_begin_send(uint8_t *send_buffer , uint16_t nSendCount);
/******************************************************************************************
*                        @软件抽象层
******************************************************************************************/



#endif /* __MY_USART_H_ */
