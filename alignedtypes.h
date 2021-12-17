#pragma once
namespace pxd
{
    //has helper functions prolly
    //definition seems to be correct
    template <typename T, unsigned int size>
    struct t_aligned_allocator
    {
    };

    template <typename T, unsigned int size, unsigned int count>
    struct t_aligned_placeholder
    {
        //consistent for 50% of the time! how do they fuckin "align" this?
        uint8_t placeholder[count == 0 ? 1 : size * count];
    };
}