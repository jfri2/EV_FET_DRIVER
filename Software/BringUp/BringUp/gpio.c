#include <avr/io.h>
#include "gpio.h"


// Pin definitions
 GPIO_PIN POS_A_PIN =
{
    .pin = PORTB0,
    .port = &PORTB,
    .input_reg = &PINB,
    .ddr = &DDRB,
    .io_type = input,
    .impedance = pullup
};

GPIO_PIN POS_B_PIN =
{
    .pin = PORTB1,
    .port = &PORTB,
    .input_reg = &PINB,
    .ddr = &DDRB,
    .io_type = input,
    .impedance = pullup
};

GPIO_PIN POS_C_PIN =
{
    .pin = PORTB2,
    .port = &PORTB,
    .input_reg = &PINB,
    .ddr = &DDRB,
    .io_type = input,
    .impedance = pullup
};

GPIO_PIN MODE_PIN =
{
    .pin = PORTB3,
    .port = &PORTB,
    .input_reg = &PINB,
    .ddr = &DDRB,
    .io_type = input,
    .impedance = high_z
};

GPIO_PIN INV_MCU_SHDN_PIN =
{
    .pin = PORTB4,
    .port = &PORTB,
    .input_reg = &PINB,
    .ddr = &DDRB,
    .io_type = output,
    .level = high
};

GPIO_PIN INV_EXT_SHDN_PIN =
{
    .pin = PORTB5,
    .port = &PORTB,
    .input_reg = &PINB,
    .ddr = &DDRB,
    .io_type = input,
    .impedance = pullup
};

GPIO_PIN LED_PIN =
{
    .pin = PORTB7,
    .port = &PORTB,
    .input_reg = &PINB,
    .ddr = &DDRB,
    .io_type = output,
    .level = high
};

GPIO_PIN LINK_CUR_PIN =
{
    .pin = PORTC0,
    .port = &PORTC,
    .input_reg = &PINC,
    .ddr = &DDRC,
    .io_type = input,
    .impedance = high_z
};

GPIO_PIN CMD_CURR_0_PIN =
{
    .pin = PORTC1,
    .port = &PORTC,
    .input_reg = &PINC,
    .ddr = &DDRC,
    .io_type = input,
    .impedance = high_z
};

GPIO_PIN CMD_CURR_1_PIN =
{
    .pin = PORTC2,
    .port = &PORTC,
    .input_reg = &PINC,
    .ddr = &DDRC,
    .io_type = input,
    .impedance = high_z
};

GPIO_PIN CMD_CURR_2_PIN =
{
    .pin = PORTC3,
    .port = &PORTC,
    .input_reg = &PINC,
    .ddr = &DDRC,
    .io_type = input,
    .impedance = high_z
};

GPIO_PIN CMD_CURR_3_PIN =
{
    .pin = PORTC4,
    .port = &PORTC,
    .input_reg = &PINC,
    .ddr = &DDRC,
    .io_type = input,
    .impedance = high_z
};

GPIO_PIN CMD_CURR_4_PIN =
{
    .pin = PORTC5,
    .port = &PORTC,
    .input_reg = &PINC,
    .ddr = &DDRC,
    .io_type = input,
    .impedance = high_z
};

GPIO_PIN YLW_L_PIN =
{
    .pin = PORTD2,
    .port = &PORTD,
    .input_reg = &PIND,
    .ddr = &DDRD,
    .io_type = output,
    .level = low
};

GPIO_PIN YLW_H_PIN =
{
    .pin = PORTD3,
    .port = &PORTD,
    .input_reg = &PIND,
    .ddr = &DDRD,
    .io_type = output,
    .level = low
};

GPIO_PIN GRN_L_PIN =
{
    .pin = PORTD4,
    .port = &PORTD,
    .input_reg = &PIND,
    .ddr = &DDRD,
    .io_type = output,
    .level = low
};

GPIO_PIN GRN_H_PIN =
{
    .pin = PORTD5,
    .port = &PORTD,
    .input_reg = &PIND,
    .ddr = &DDRD,
    .io_type = output,
    .level = low
};

GPIO_PIN BLU_L_PIN =
{
    .pin = PORTD6,
    .port = &PORTD,
    .input_reg = &PIND,
    .ddr = &DDRD,
    .io_type = output,
    .level = low
};

GPIO_PIN BLU_H_PIN =
{
    .pin = PORTD7,
    .port = &PORTD,
    .input_reg = &PIND,
    .ddr = &DDRD,
    .io_type = output,
    .level = low
};

// Functions
void gpio_init_pin(GPIO_PIN gpio_pin)
{
// Input
    if (gpio_pin.io_type == input)
    {
        *gpio_pin.ddr &= ~(1<<gpio_pin.pin);
        if (gpio_pin.impedance == high_z)
        {
            *gpio_pin.port &= ~(1<<gpio_pin.pin);
        }
        else if (gpio_pin.impedance == pullup)
        {
            *gpio_pin.port |= (1<<gpio_pin.pin);
        }
    }

// Output
    else if (gpio_pin.io_type == output)
    {
        *gpio_pin.ddr |= (1<<gpio_pin.pin);
        if (gpio_pin.level == low)
        {
            *gpio_pin.port &= ~(1<<gpio_pin.pin);
            
        }
        else if (gpio_pin.level == high)
        {
            *gpio_pin.port |= (1<<gpio_pin.pin);
        }
    }
}

void gpio_set_pin(GPIO_PIN gpio_pin)
{
    *gpio_pin.port |= (1<<gpio_pin.pin);
}

void gpio_clear_pin(GPIO_PIN gpio_pin)
{
    *gpio_pin.port &= ~(1<<gpio_pin.pin);
}

void gpio_toggle_pin(GPIO_PIN gpio_pin)
{
    *gpio_pin.port ^= (1<<gpio_pin.pin);
}

bool gpio_get_pin(GPIO_PIN gpio_pin)
{
    if ((*gpio_pin.input_reg) & gpio_pin.pin)
    {
        return (true);
    }
    else
    {
        return (false);
    }
}
