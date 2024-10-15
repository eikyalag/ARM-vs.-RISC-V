#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "timer.h"
#include "uart.h"



#define TOGGLE_GPIO

#if defined TOGGLE_GPIO
    #include "gpio.h"
#endif


#define NUM_OF_RUNS 1000

void perform_C_operations();

void measure_elapsed_time();