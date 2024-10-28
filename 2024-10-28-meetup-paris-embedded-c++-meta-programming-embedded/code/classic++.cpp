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


class GPIOBank
{
    const uintptr_t base_offset_;

public:
    GPIOBank(uintptr_t base_offset) : base_offset_(base_offset) {}

    void set_high(uint32_t gpios)
    {
        auto v = read_reg(base_offset_);
        write_reg(base_offset_, (v | gpios) & 0xff);
    }


    void unset_high(uint32_t gpios)
    {
        auto v = read_reg(base_offset_);
        write_reg(base_offset_, (v & ~gpios) & 0xff);
    }
};

static GPIOBank gpio_bank0(GPIO_BANK0_ADDR);
static GPIOBank gpio_bank1(GPIO_BANK1_ADDR);

void enable_something(void)
{
    gpio_bank0.set_high(GPIO0 | GPIO2);
    gpio_bank1.unset_high(GPIO1 | GPIO3 | GPIO5 | GPIO7);
}
