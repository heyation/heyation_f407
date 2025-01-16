#ifndef __MY_LED_H_
#define __MY_LED_H_


/******************************************************************************************
*                        @硬件实现层
******************************************************************************************/
typedef struct led_data {
    GPIO_TypeDef* GPIOx;
    uint16_t      GPIO_Pin;
    
    BitAction     state;

    void          (*init)(struct led_data* self);
    void          (*on)(struct led_data* self);
    void          (*off)(struct led_data* self);
    void          (*toggle)(struct led_data* self);
} led_data;

void __led_init(led_data* self);
void __led_turn_on(led_data* self);
void __led_turn_off(led_data* self);
void __led_toggle(led_data* self);
void led_register_functions(led_data* led);
/******************************************************************************************
*                        @软件抽象层
******************************************************************************************/


#endif /* __MY_LED_H_ */
