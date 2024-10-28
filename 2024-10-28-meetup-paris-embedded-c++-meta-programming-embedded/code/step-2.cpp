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

void enable_something(void)
{
    auto v = read_reg(GPIO_BANK0_ADDR);
    write_reg(GPIO_BANK0_ADDR, (v | GPIO0 | GPIO2) & 0xff);

    v = read_reg(GPIO_BANK1_ADDR);
    write_reg(GPIO_BANK1_ADDR, (v & ~(GPIO1 | GPIO3 | GPIO5 | GPIO7)) & 0xff);

    // Problem ???
}

