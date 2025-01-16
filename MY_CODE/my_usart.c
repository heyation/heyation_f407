/***************************************************************************************************************/ 
#include "ALLHeader.h"

/******************************************************************************************
*                        @宏定义
******************************************************************************************/


/******************************************************************************************
*                        @硬件实现层
******************************************************************************************/
void __usart_configuration(uint32_t usart_bound)
{
	//GPIO端口设置
  	GPIO_InitTypeDef 	GPIO_InitStructure		={0};
	USART_InitTypeDef 	USART_InitStructure		={0};
	//NVIC_InitTypeDef 	NVIC_InitStructure		={0};
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); 							//使能GPIOA时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);							//使能USART2时钟
 
	//串口2对应引脚复用映射
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_USART2); 						//GPIOA2复用为USART2
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_USART2); 						//GPIOA3复用为USART2
	
	//USART1端口配置
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3; 							//GPIOA2与GPIOA3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;									//复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;								//速度50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 									//推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;									//上拉
	GPIO_Init(GPIOA,&GPIO_InitStructure); 											//初始化PA2，PA3

   //USART1 初始化设置
	USART_InitStructure.USART_BaudRate = usart_bound;								//波特率设置
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;						//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;							//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;								//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;	//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;					//收发模式
  	USART_Init(USART2, &USART_InitStructure); 										//初始化串口2
	
  	USART_Cmd(USART2, ENABLE);  													//使能串口2

	
}


// 发送单个字节
void __usart2_send_byte(uint8_t Byte)
{
	USART_SendData(USART2, Byte);													//向串口2发送数据
	while(USART_GetFlagStatus(USART2,USART_FLAG_TC)!=SET);							//等待发送结束
}

// 发送数组
void __usart2_send_array(uint8_t *Arr, uint8_t Length)
{
    uint8_t i;  
    for (i = 0; i < Length; ++i)
    {
        __usart2_send_byte(Arr[i]);
    }
}

