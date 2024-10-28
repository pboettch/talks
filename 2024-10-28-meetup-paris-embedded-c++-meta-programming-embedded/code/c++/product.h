#pragma once

#include <cstdint>

#include "hardware_description_generated.h"

#include "gpio_bank.h"

typedef gpio_bank<PERIPHERAL_BANK0_OFFSET, PERIPHERAL_GPIO_OFFSET> gpio_bank0;
typedef gpio_bank<PERIPHERAL_BANK1_OFFSET, PERIPHERAL_GPIO_OFFSET> gpio_bank1;
