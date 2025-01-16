/***************************************************************************************************************/ 
#include "ALLHeader.h"
/******************************************************************************************
*                        @宏定义
******************************************************************************************/

/******************************************************************************************
*                        @数据
******************************************************************************************/

// typedef struct usart_data {
// 	USART_TypeDef*	USARTx;

// 	GPIO_TypeDef* 	TX_GPIOx;
// 	uint16_t		TX_GPIO_Pin;
// 	GPIO_TypeDef* 	RX_GPIOx;
// 	uint16_t		RX_GPIO_Pin;

// 	uint32_t		usart_bound;
// 	uint8_t			PreemptionPriority;
// 	uint8_t			SubPriority;

// 	uint16_t 		usart_rx_state;
// 	uint8_t			usart_rec_length;
// 	uint16_t		usart_rx_rec_buf[usart_rec_length];
// }


/******************************************************************************************
*                        @硬件实现层
******************************************************************************************/
void __usart_configuration(uint32_t usart_bound)
{
	//GPIO端口设置
  	GPIO_InitTypeDef 	GPIO_InitStructure		={0};
	USART_InitTypeDef 	USART_InitStructure		={0};
	NVIC_InitTypeDef 	NVIC_InitStructure		={0};
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); 							//使能GPIOA时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);							//使能USART2时钟
 
	//串口2对应引脚复用映射
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_USART2); 						//GPIOA2复用为USART2
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_USART2); 						//GPIOA3复用为USART2
	
	//USART2端口配置
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3; 							//GPIOA2与GPIOA3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;									//复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;								//速度50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; 									//推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;									//上拉
	GPIO_Init(GPIOA,&GPIO_InitStructure); 											//初始化PA2，PA3

   //USART2 初始化设置
	USART_InitStructure.USART_BaudRate = usart_bound;								//波特率设置
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;						//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;							//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;								//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;	//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;					//收发模式
  	USART_Init(USART2, &USART_InitStructure); 										//初始化串口2
	
  	USART_Cmd(USART2, ENABLE);  													//使能串口2

	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);									//开启相关中断

	//USART2 NVIC 配置
  	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;								//串口2中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3;							//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =3;								//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;									//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);													//根据指定的参数初始化NVIC寄存器
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

/******************************************************************************************
*                        @中断
******************************************************************************************/
void USART2_IRQHandler(void)//串口2中断服务程序
{
	if(USART_GetITStatus(USART2, USART_IT_RXNE) == SET)//判断是不是真的有中断发生
  	{
    USART_SendData(USART2,USART_ReceiveData(USART2));//又将数据发回去
    USART_ClearITPendingBit(USART2, USART_IT_RXNE); //已经处理就清楚标志位 
  	}  
} 
