#include "gpio.h"


void pin_init()
{
    rcu_periph_clock_enable(RCU_GPIOC);
    gpio_init(GPIOC, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_1);
}

void pin_set()
{
    gpio_bit_set(GPIOC, GPIO_PIN_1);
}

void pin_reset()
{
    gpio_bit_reset(GPIOC, GPIO_PIN_1);
}