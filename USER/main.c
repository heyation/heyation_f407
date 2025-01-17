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
	__usart2_init(115200);
	led1.toggle(&led1);
	led2.toggle(&led2);
	usart_init();
	led1.toggle(&led1);
	led2.toggle(&led2);


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

		usart2.tx(&usart2,data_to_send);
		usart3.tx(&usart3,data_to_send);

		led1.toggle(&led1);
		//led2.toggle(&led2);
		delay_ms(1000);

		
		usart2.tx(&usart2,data_to_send1);
		usart3.tx(&usart3,data_to_send1);

		led1.toggle(&led1);
		//led2.toggle(&led2);
		delay_ms(1000);
	}
}
