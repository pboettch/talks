#include <cstdint>

static uint32_t read_reg(const uintptr_t addr)
{
    return *(volatile uint32_t *) addr;
}

static void write_reg(const uintptr_t addr, const uint32_t value)
{
    auto access = (volatile uint32_t *) addr;
    *access = value;
}

void enable_something(void)
{
    // set values to 1 of GPIO 0 and 2 of GPIO-bank 0
    auto v = read_reg(0x004d2460);
    write_reg(0x004d2460, (v | 0x5) & 0xff);

    // unset values of GPIO 1, 3, 5, 7 of GPIO-bank 1
    v = read_reg(0x004d3460);
    write_reg(0x004d3460, (v & ~0xaa) & 0xff);
}
