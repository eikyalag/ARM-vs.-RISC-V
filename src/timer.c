#include "timer.h"


void timer0_init()
{
    rcu_periph_clock_enable(RCU_TIMER0);

    timer_parameter_struct timer_initpara;

    timer_deinit(TIMER0); //reset
    timer_initpara.prescaler = 108 - 1;  // prescale 108 MHz Clock 
    timer_initpara.period = 0xFFFFFFFF;    // maximum
    timer_initpara.clockdivision = TIMER_CKDIV_DIV1;
    timer_initpara.counterdirection = TIMER_COUNTER_UP;
    timer_init(TIMER0, &timer_initpara);
    timer_enable(TIMER0);
}


uint32_t get_time() 
{
    return timer_counter_read(TIMER0);  // Aktuellen Timerwert auslesen
}