/***************************************************************************************************************/ 
#include "ALLHeader.h"
/******************************************************************************************
*                        @宏定义
******************************************************************************************/
void all_init(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);

	delay_init(168);

	led_init();

	__usart_configuration(115200);
	__usart_dma_tx_configuration();
}


int main(void)
{
	all_init();
	char data_to_send[] = "222";
  // 获取字符串长度（包括终止符 '\0'）
  uint16_t data_length = strlen(data_to_send); 
	
		char data_to_send1[] = "1111";
  // 获取字符串长度（包括终止符 '\0'）
  uint16_t data_length1 = strlen(data_to_send); 
	
	while(1)
	{
		//__usart2_send_array("111",3);
		
    	__usart_dma_send_data((uint8_t *)data_to_send, data_length);
		//led1.toggle(&led1);
		led2.toggle(&led2);
		DMA_ClearFlag(DMA1_Stream6, DMA_FLAG_TCIF6);  // 清除 DMA 完成标志
		delay_ms(1000);
		__usart_dma_send_data((uint8_t *)data_to_send1, data_length1);
		//led1.toggle(&led1);
		led2.toggle(&led2);
		DMA_ClearFlag(DMA1_Stream6, DMA_FLAG_TCIF6);  // 清除 DMA 完成标志
		delay_ms(1000);
		__usart_dma_send_data((uint8_t *)data_to_send, data_length);
		//led1.toggle(&led1);
		led2.toggle(&led2);
		DMA_ClearFlag(DMA1_Stream6, DMA_FLAG_TCIF6);  // 清除 DMA 完成标志
		delay_ms(1000);
	}
}
