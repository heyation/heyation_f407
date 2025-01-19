/***************************************************************************************************************/ 
#include "ALLHeader.h"

/******************************************************************************************
*                        @宏定义
******************************************************************************************/

/******************************************************************************************
*                        @TIM4 —— 中断
******************************************************************************************/
void __tim4_configuration(uint16_t arr,uint16_t psc)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure   = {0};
	NVIC_InitTypeDef        NVIC_InitStructure          = {0};
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);             ///使能TIM4时钟
	
    TIM_TimeBaseInitStructure.TIM_Period = arr; 	                //自动重装载值
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;                    //定时器分频
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;   //向上计数模式
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStructure);              //初始化TIM4
	
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE);                        //允许定时器4更新中断
	TIM_Cmd(TIM4,ENABLE);                                           //使能定时器4
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM4_IRQn;                   //定时器4中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01;      //抢占优先级1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03;             //子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

//定时器4中断服务函数
void TIM4_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM4,TIM_IT_Update)==SET) //溢出中断
	{
        led1.toggle(&led1);
	}
	TIM_ClearITPendingBit(TIM4,TIM_IT_Update);  //清除中断标志位
}
/******************************************************************************************
*                        @TIM9 & TIM8 —— 舵机
******************************************************************************************/

/******************************************************************************************
*                        @TIM2 —— 直流电机
******************************************************************************************/

/******************************************************************************************
*                        @TIM3 —— 步进电机
******************************************************************************************/

/******************************************************************************************
*                        @软件抽象层
******************************************************************************************/

/******************************************************************************************
*                        @如何使用
******************************************************************************************/


