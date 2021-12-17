#pragma once
namespace pxd
{
    template <typename T, unsigned int count>
    struct t_array
    {
        T m_data[count];
    };

    template <typename valtype, typename enumType, unsigned int length, unsigned int some_val_that_always_matches_length>
    struct t_enum_array : pxd::t_array<valtype, length>
    {
    };
}