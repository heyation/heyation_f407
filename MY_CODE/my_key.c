/***************************************************************************************************************/ 
#include "ALLHeader.h"



#define LONG_PRESS_THRESHOLD 500  // 长按阈值（单位：毫秒）




/******************************************************************************************
*                        @硬件实现层
******************************************************************************************/
void __key_init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure = {0};

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOE, ENABLE);  //使能GPIOA,GPIOE时钟

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;                                   //KEY0 对应引脚
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;                                //普通输入模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;                          //100M
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN ;                             //下拉
	GPIO_Init(GPIOE, &GPIO_InitStructure);                                      //初始化GPIOE4
	 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;                                   //WK_UP对应引脚PA0
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN ;                             //下拉
	GPIO_Init(GPIOA, &GPIO_InitStructure);                                      //初始化GPIOA0
}

uint8_t __get_key_up_value(void) 
{
    if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == Bit_SET) 
    {  // 检测按键高电平（下拉模式按下时为高电平）
        delay_ms(20);  // 去抖延时
        if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == Bit_SET) 
        {
            return 1;  // 按键被按下
        }
    }
    return 0;  // 按键未按下
}

/******************************************************************************************
*                        @如何使用
******************************************************************************************/
/*

*/

