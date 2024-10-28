#include <cstdint>

#include "gpio_banks.h"

#define gpio_bank0_set_high(gpios) gpio_set_high(GPIO_BANK0_ADDR, (gpios))
#define gpio_bank0_unset_high(gpios) gpio_unset_high(GPIO_BANK0_ADDR, (gpios))

#define gpio_bank1_set_high(gpios) gpio_unset_high(GPIO_BANK1_ADDR, (gpios))
#define gpio_bank1_unset_high(gpios) gpio_unset_high(GPIO_BANK1_ADDR, (gpios))

void enable_something(void)
{
    gpio_bank0_set_high(GPIO0 | GPIO2);
    gpio_bank1_unset_high(GPIO1 | GPIO3 | GPIO5 | GPIO7);
}
