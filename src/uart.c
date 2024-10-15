#include "uart.h"


void uart_init() 
{
    rcu_periph_clock_enable(RCU_GPIOA);  
    gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_9);  // TX
    gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_10); // RX

    rcu_periph_clock_enable(RCU_USART0);
    usart_deinit(USART0);
    usart_baudrate_set(USART0, 115200);
    usart_word_length_set(USART0, USART_WL_8BIT);
    usart_stop_bit_set(USART0, USART_STB_1BIT);
    usart_parity_config(USART0, USART_PM_NONE);
    usart_transmit_config(USART0, USART_TRANSMIT_ENABLE);
    usart_enable(USART0);
}


void uart_send(const char* data) 
{
    for (size_t i = 0; i < strlen(data); i++) {
        while (usart_flag_get(USART0, USART_FLAG_TBE) == RESET)
        {}
        usart_data_transmit(USART0, (uint8_t)data[i]);
    }
}
