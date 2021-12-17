#pragma once
#include <xmmintrin.h>
#include <cstdint>
#include "unknownstructs.h"

#include "threading.h"
#include "array.h"
#include "vector.h"
#include "list.h"


//pxd: Dragon Engine proprietary library
namespace pxd
{
    namespace sl
    {
        struct handle_t
        {
            $081A7393FF78DEED396C29788378B83B ___u0;
        };
    }

    //these two have to stay here because of stuff
    struct $B61FAE900E1E5B3A68C5BBB76CDCB143
    {
        unsigned int bone_id;
        pxd::sl::handle_t h_node;
    };


    union $1E858A01ACB3C112B0E3DABA4459AE1F
    {
        unsigned __int64 uid;
        $B61FAE900E1E5B3A68C5BBB76CDCB143 __s1;
    };


    namespace ct
    {
        struct dynamics_handle_t
        {
            $1E858A01ACB3C112B0E3DABA4459AE1F ___u0;
        };
    }

    namespace mm
    {
        enum VFFLAG
        {
            VFFLAG_X = 0x1,
            VFFLAG_Y = 0x2,
            VFFLAG_Z = 0x4,
            VFFLAG_W = 0x8,
            VFFLAG_XYZW = 0xF,
            VFFLAG_XYZ = 0x7,
            VFFLAG_XYW = 0xB,
            VFFLAG_XY = 0x3,
            VFFLAG_XZW = 0xD,
            VFFLAG_XZ = 0x5,
            VFFLAG_XW = 0x9,
            VFFLAG_YZW = 0xE,
            VFFLAG_YZ = 0x6,
            VFFLAG_YW = 0xA,
            VFFLAG_ZW = 0xC,
            VFFLAG_ALL = 0xF,
            VFFLAG_NONE = 0x0,
        };

        enum CORNER
        {
            CORNER_XnYnZn = 0x0,
            CORNER_XpYnZn = 0x1,
            CORNER_XnYpZn = 0x2,
            CORNER_XpYpZn = 0x3,
            CORNER_XnYnZp = 0x4,
            CORNER_XpYnZp = 0x5,
            CORNER_XnYpZp = 0x6,
            CORNER_XpYpZp = 0x7,
            CORNER_NUM = 0x8,
        };

        enum AXIS
        {
            AXIS_POSITIVE_X = 0x0,
            AXIS_NEGATIVE_X = 0x1,
            AXIS_POSITIVE_Y = 0x2,
            AXIS_NEGATIVE_Y = 0x3,
            AXIS_POSITIVE_Z = 0x4,
            AXIS_NEGATIVE_Z = 0x5,
            AXIS_POSITIVE_W = 0x6,
            AXIS_NEGATIVE_W = 0x7,
            AXIS_NUM = 0x8,
        };


        struct context_t
        {
            unsigned int tag_id;
            unsigned int version;
            unsigned int size_of_struct;
            unsigned int random_seed;
            __m128 xrand_seed;
        };
    }





    struct alignas(0x10) quaternion
    {
    public:
        __m128 m_vf;
    };

    struct matrix
    {
    public:
        __m128 m_vm0;
        __m128 m_vm1;
        __m128 m_vm2;
        __m128 m_vm3;
    };


    template <typename firstT, typename secondT>
    struct t_pair
    {
    public:
        firstT first;
        secondT second;
    };

    //size / (someType * someType2)
    template <unsigned int size, typename someType, typename someType2>
    struct t_bitset
    {
    public: //this is the worst size calculation of All Time;
        someType2 m_bits_array[size / (sizeof(someType) * sizeof(someType2)) > 0 ? size / (sizeof(someType) * sizeof(someType2)) : 1];
    };

    //It's unknown what the number does for the relative pointer.
    template <typename T, unsigned int someNumber>
    struct t_relative_ptr
    {
    public:
        int m_relative_ptr;
    };

    template <typename T>
    struct t_scoped_ptr
    {
        T* mp_raw_ptr;
    };

    template <typename _char, typename allocator>
    struct t_string
    {
        struct bstr_t
        {
            struct header_t
            {
                unsigned int length;
                _char sz_string[12 / sizeof(_char)];
            };

            union
            {
                __int64 mp_header : 44;
                unsigned __int64 m_size : 20;
                unsigned __int64 m_data;
            };

        };

        pxd::t_string<_char, allocator>::bstr_t m_bstr;
    };

}