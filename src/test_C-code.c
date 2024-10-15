#include "test_C-code.h"



void perform_C_operations()
{
    
    volatile double result = sqrt(4095) + (64 % 7) / (128 / 3.0);  // math.h function

    char buffer1[1024];
    char *buffer2 = (char*) malloc(1024 * sizeof(char));  // memory allocation
    memset(buffer1, 'A', sizeof(buffer1));  // memset
    memcpy(buffer2, buffer1, sizeof(buffer1));  // memcpy

    char str1[512] = "Testing GD32VF103V-EVAL with C operations!";
    char str2[512];
    strcpy(str2, str1);  // strcpy
    volatile size_t length = strlen(str2);  // strlen

    if (buffer2) {
        free(buffer2);  // free used memory
    }
}


void measure_elapsed_time()
{
    uart_init();

    #if defined TOGGLE_GPIO
        pin_init();   // init GPIOC, Pin 1

    #else
        timer0_init();
    #endif
    
 
    #if defined TOGGLE_GPIO
        pin_set();  // set PC1

    #else
    uint8_t start_time = get_time();  // get starting time in ticks
    #endif


    for (int i = 0; i < NUM_OF_RUNS; i++)
    {
        perform_C_operations();
    }


    #if defined TOGGLE_GPIO
        pin_reset();  // reset PC1

    #else
        uint8_t end_time = get_time();  // get end time in ticks


        uint8_t res_time = end_time - start_time;   // substract starting time from end time

        char elapsed_time[50];
        sprintf(elapsed_time, "\nElapsed time: %d ticks\n", res_time);  // put time in ticks into string
            
        uart_send(elapsed_time);  // transmit string
    #endif
}


