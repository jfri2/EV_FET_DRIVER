/*
 * BringUp.c
 *
 * Created: 5/28/2017 9:11:08 PM
 * Author : John Fritz (jfri2)
 */ 

/*
TODOs:
 - Replace GPIO structs with pointers rather than passing them to functions
 - Add UART & test
 - Test with Arduino Bootloader (especially uploading code using Purdue loader)
     - Make required changes to bootloader image to support reprogramming the 328PB 
       w/ the Purdue Loader
 - Test gate drivers & verify proper drive levels on all outputs
*/

#define F_CPU 16000000L		// Core clock speed for util/delay.h

#include <avr/io.h>
#include <util/delay.h>
#include "gpio.h"

int main(void)
{
    // Init GPIO Pins
    gpio_init_pin(POS_A_PIN);
    gpio_init_pin(POS_B_PIN);
    gpio_init_pin(POS_C_PIN);
    gpio_init_pin(MODE_PIN);
    gpio_init_pin(INV_MCU_SHDN_PIN);
    gpio_init_pin(INV_EXT_SHDN_PIN);
    gpio_init_pin(LED_PIN);
    gpio_init_pin(LINK_CUR_PIN);
    gpio_init_pin(CMD_CURR_0_PIN);
    gpio_init_pin(CMD_CURR_1_PIN);
    gpio_init_pin(CMD_CURR_2_PIN);
    gpio_init_pin(CMD_CURR_3_PIN);
    gpio_init_pin(CMD_CURR_4_PIN);
    gpio_init_pin(YLW_L_PIN);
    gpio_init_pin(YLW_H_PIN);
    gpio_init_pin(GRN_L_PIN);
    gpio_init_pin(GRN_H_PIN);
    gpio_init_pin(BLU_L_PIN);
    gpio_init_pin(BLU_H_PIN);

    while (1) 
    {
        gpio_toggle_pin(LED_PIN);
        _delay_ms(500);
    }
}

