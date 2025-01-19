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
	usart_init();

	__tim4_configuration(5000-1,8400-1);

	led0.toggle(&led0);
	led1.toggle(&led1);


}


int main(void)
{
	all_init();

	led0.toggle(&led0);
	led1.toggle(&led1);
	
	while(1)
	{
		//led0.toggle(&led0);
		delay_ms(200);
	}
}
