/***************************************************************************************************************/ 
#include "ALLHeader.h"

/******************************************************************************************
*                        @LED
******************************************************************************************/  
led_data led1 = {
	.GPIOx = GPIOF,
	.GPIO_Pin = GPIO_Pin_9,
};
led_data led2 = {
	.GPIOx = GPIOF,
	.GPIO_Pin = GPIO_Pin_10,
};

void led_init(void)
{
  led_register_functions(&led1);
	led1.init(&led1);
  led_register_functions(&led2);
	led2.init(&led2);
}

/*
		led1.toggle(&led1);
		delay_ms(500);	
		led2.toggle(&led2);
		delay_ms(500);
*/
/******************************************************************************************
*                        @USART
******************************************************************************************/  
// usart_data usart2 = {
// 	.USARTx = USART2,
// 	.bound	= 115200,
// };

// usart_data usart3 = {
// 	.USARTx = USART3,
// 	.bound	= 115200,
// };
// void usart_init(void)
// {
// 	usart_register_functions(&usart2);
// 	usart3.init(&usart2);
// 	usart_register_functions(&usart3);
// 	usart3.init(&usart3);
// }


