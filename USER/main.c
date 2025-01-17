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
	// usart_init();
	__usart2_init(115200);
	__usart3_init(115200);

}


int main(void)
{
	all_init();
	led1.toggle(&led1);
	led2.toggle(&led2);
	delay_ms(1000);
	led1.toggle(&led1);
	led2.toggle(&led2);
	
	char data_to_send[] = "222";
  	// 获取字符串长度（包括终止符 '\0'）

	char data_to_send1[] = "1111";
  	// 获取字符串长度（包括终止符 '\0'）
	
	while(1)
	{
		//__usart2_send_array("111",3);
		// usart2.tx(&usart2,data_to_send);
		__usart2_dma_send_string(data_to_send);
		// __usart3_send_array("222",3);
		 __usart3_dma_send_string(data_to_send);
		//led1.toggle(&led1);
		led2.toggle(&led2);
		delay_ms(1000);
		// usart2.tx(&usart2,data_to_send1);
		__usart2_dma_send_string(data_to_send1);
		//__usart3_send_array("1111",4);
		__usart3_dma_send_string(data_to_send1);
		//led1.toggle(&led1);
		led2.toggle(&led2);
		delay_ms(1000);
	}
}
