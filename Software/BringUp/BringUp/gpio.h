#include <stdbool.h>

// Types
typedef enum
{
    input = 0,
    output = 1
} IO;

typedef enum
{
    low = 0,
    high = 1
} LEVEL;

typedef enum
{
    high_z = 0,
    pullup = 1
} INPUT_Z;

typedef struct
{
    uint8_t pin;
    uint8_t *port;
    uint8_t *input_reg;
    uint8_t *ddr;
    IO io_type;
    LEVEL level;            // outputs only
    INPUT_Z impedance;      // inputs only    
} GPIO_PIN;

// Functions
void gpio_init_pin(GPIO_PIN pin);
void gpio_set_pin(GPIO_PIN gpio_pin);
void gpio_clear_pin(GPIO_PIN gpio_pin);
void gpio_toggle_pin(GPIO_PIN gpio_pin);
bool gpio_get_pin(GPIO_PIN gpio_pin);

// Global Variable Declarations
extern GPIO_PIN POS_A_PIN;
extern GPIO_PIN POS_B_PIN;
extern GPIO_PIN POS_C_PIN;
extern GPIO_PIN MODE_PIN;
extern GPIO_PIN INV_MCU_SHDN_PIN;
extern GPIO_PIN INV_EXT_SHDN_PIN;
extern GPIO_PIN LED_PIN;
extern GPIO_PIN LINK_CUR_PIN;
extern GPIO_PIN CMD_CURR_0_PIN;
extern GPIO_PIN CMD_CURR_1_PIN;
extern GPIO_PIN CMD_CURR_2_PIN;
extern GPIO_PIN CMD_CURR_3_PIN;
extern GPIO_PIN CMD_CURR_4_PIN;
extern GPIO_PIN YLW_L_PIN;
extern GPIO_PIN YLW_H_PIN;
extern GPIO_PIN GRN_L_PIN;
extern GPIO_PIN GRN_H_PIN;
extern GPIO_PIN BLU_L_PIN;
extern GPIO_PIN BLU_H_PIN;