#pragma once

template<typename T, uintptr_t base_offset>
class io
{
public:
    static T read(uintptr_t offset)
    {
        return *(volatile T *) ((base_offset << 12) | offset);
    }

    static void write(const uintptr_t offset, const T value)
    {
        *(volatile T *) ((base_offset << 12) | offset) = value;
    }
};

template<uintptr_t base_offset>
class io32 : public io<uint32_t, base_offset>
{ };
