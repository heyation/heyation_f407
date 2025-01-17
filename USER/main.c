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

	__usart2_init();

}


int main(void)
{
	all_init();
	char data_to_send[] = "222";
  	// 获取字符串长度（包括终止符 '\0'）

	char data_to_send1[] = "1111";
  	// 获取字符串长度（包括终止符 '\0'）
	
	while(1)
	{
		//__usart2_send_array("111",3);
		__usart2_dma_send_string((uint8_t *)data_to_send);
		//led1.toggle(&led1);
		led2.toggle(&led2);
		delay_ms(1000);
		__usart2_dma_send_string((uint8_t *)data_to_send1);
		//led1.toggle(&led1);
		led2.toggle(&led2);
		delay_ms(1000);
		__usart2_dma_send_string((uint8_t *)data_to_send);
		//led1.toggle(&led1);
		led2.toggle(&led2);
		delay_ms(1000);
	}
}
