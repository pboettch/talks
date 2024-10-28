#pragma once

#include "io.h"

#include <bitset>

template<uintptr_t base_offset, uintptr_t instance_offset>
class gpio_bank : public io32<base_offset>
{
    using io32<base_offset>::write;
    using io32<base_offset>::read;

public:
    template <typename... Args>
	static void set_high(Args... args)
	{
		std::bitset<8> bitmask(read(instance_offset));
		(bitmask.set(args), ...);
		write(instance_offset, bitmask.to_ulong());
	}

	template <typename... Args>
	static void unset_high(Args... args)
	{
  		std::bitset<8> bitmask(read(instance_offset));
		(bitmask.reset(args), ...);
        write(instance_offset, bitmask.to_ulong());
	}
};
