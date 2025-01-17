/***************************************************************************************************************/ 
#include "ALLHeader.h"

/******************************************************************************************
*                        @宏定义
******************************************************************************************/

/******************************************************************************************
*                        @硬件实现层
******************************************************************************************/

void __led_init(led_data* self) 
{    
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    // 使能时钟（根据 GPIO 选择不同的 RCC）
    if (self->GPIOx == GPIOA) RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    else if (self->GPIOx == GPIOB) RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    else if (self->GPIOx == GPIOC) RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
    else if (self->GPIOx == GPIOD) RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    else if (self->GPIOx == GPIOE) RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
    else if (self->GPIOx == GPIOF) RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
    else if (self->GPIOx == GPIOG) RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);

    // GPIO 初始化
    GPIO_InitStructure.GPIO_Pin = self->GPIO_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;       // 普通输出模式
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;      // 推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  // 100MHz
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;        // 上拉
    GPIO_Init(self->GPIOx, &GPIO_InitStructure);

    // 初始状态设置为灯灭
    GPIO_SetBits(self->GPIOx, self->GPIO_Pin);
    self->state = Bit_SET;
}

void __led_turn_on(led_data* self) 
{
    GPIO_ResetBits(self->GPIOx, self->GPIO_Pin);
    self->state = Bit_RESET;
}

void __led_turn_off(led_data* self) 
{
    GPIO_SetBits(self->GPIOx, self->GPIO_Pin);
    self->state = Bit_SET;
}

void __led_toggle(led_data* self) 
{
    self->state = (self->state == Bit_SET) ? Bit_RESET : Bit_SET;
    GPIO_WriteBit(self->GPIOx, self->GPIO_Pin, self->state);
}

// 初始化函数指针
void led_register_functions(led_data* led) 
{
    led->init   = __led_init;
    led->on     = __led_turn_on;
    led->off    = __led_turn_off;
    led->toggle = __led_toggle;
}
/******************************************************************************************
*                        @软件抽象层
******************************************************************************************/

/******************************************************************************************
*                        @如何使用
******************************************************************************************/
/*
int main() {
    led_data led1 = {
        .GPIOx = GPIOF,
        .GPIO_Pin = GPIO_Pin_9,
    };
    led_register_functions(&led1);
    led1.init(&led1);  // 初始化 LED
    led1.on(&led1);    // 打开 LED
    led1.off(&led1);   // 关闭 LED
    led1.toggle(&led1);// 切换 LED 状态

    return 0;
}
 */
