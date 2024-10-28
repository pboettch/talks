#include <cstdint>

#include "io_basic.h"

#define GPIO_BANK0_ADDR ((1234 << 12) | (1120))
#define GPIO_BANK1_ADDR ((1235 << 12) | (1120))

#define GPIO0 (1 << 0)
#define GPIO1 (1 << 1)
#define GPIO2 (1 << 2)
#define GPIO3 (1 << 3)
#define GPIO4 (1 << 4)
#define GPIO5 (1 << 5)
#define GPIO6 (1 << 6)
#define GPIO7 (1 << 7)

static void gpio_set_high(uintptr_t addr, uint32_t gpios)
{
    auto v = read_reg(addr);
    write_reg(GPIO_BANK0_ADDR, (v | gpios) & 0xff);
}

static void gpio_unset_high(uintptr_t addr, uint32_t gpios)
{
    auto v = read_reg(addr);
    write_reg(GPIO_BANK1_ADDR, (v & ~gpios) & 0xff);
}

void enable_something(void)
{
    // set values to 1 of GPIO 0 and 2 of GPIO-bank 0
    gpio_set_high(GPIO_BANK0_ADDR, GPIO0 | GPIO2);

    // unset values of GPIO 1, 3, 5, 7 of GPIO-bank 1
    gpio_unset_high(GPIO_BANK1_ADDR, GPIO1 | GPIO3 | GPIO5 | GPIO7);
}
