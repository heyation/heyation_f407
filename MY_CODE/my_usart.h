#ifndef __MY_USART_H_
#define __MY_USART_H_

#include "ALLHeader.h"
/******************************************************************************************
*                        @硬件实现层
******************************************************************************************/

void __usart2_configuration(uint32_t usart_bound);
void __usart2_dma_tx_configuration(void);
void __usart2_init(void);
	
void __usart2_send_byte(uint8_t Byte);
void __usart2_send_array(uint8_t *Arr, uint8_t Length);
void __usart2_dma_send_data(uint8_t *send_buffer , uint16_t nSendCount);
void __usart2_dma_send_string(char *data_to_send);
/******************************************************************************************
*                        @软件抽象层
******************************************************************************************/



#endif /* __MY_USART_H_ */
