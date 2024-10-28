// no include, it is part of the product

void enable_something(void)
{
    gpio_bank0::set_high(0, 2);
    gpio_bank1::unset_high(1, 3, 5, 7);
}
