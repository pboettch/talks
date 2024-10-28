#include <cstdint>

static void write_reg(uintptr_t addr, uint32_t value)
{
    auto access = (volatile uint32_t *) addr;
    *access = value;
}

void enable_something(void)
{
    // set values to 1 of GPIO 0 and 2 of GPIO-bank 0
    write_reg(0x004d2460, (0x5 & 0xff));

    // unset values of GPIO 1, 3, 5, 7 of GPIO-bank 1
    write_reg(0x004d3460, (~0xaa) & 0xff);
}
