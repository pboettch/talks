static uint32_t read_reg(const uintptr_t addr)
{
    return *(volatile uint32_t *) addr;
}

static void write_reg(const uintptr_t addr, const uint32_t value)
{
    auto access = (volatile uint32_t *) addr;
    *access = value;
}
