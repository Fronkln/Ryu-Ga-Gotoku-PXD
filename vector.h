#pragma once
#include "alignedtypes.h"

namespace pxd
{
    template <typename T>
    struct t_base_vector
    {
    public:
        T* mp_element;
        unsigned int m_vector_size;
        unsigned m_element_size;

        void set(unsigned int index, T value)
        {
            __int64 vectorSize = this->m_vector_size;
            if ((unsigned int)vectorSize <= index)
            {
                //uh oh
            }

            this->mp_element[index] = value;
        }

        __int64 push_back(T valueToPush)
        {
            __int64 elementSize; // rdi
            T inputVal; // rsi
            __int64 vectorSize; // r8
            __int64 result; // rax

            elementSize = this->m_element_size;
            inputVal = valueToPush;
            vectorSize = this->m_vector_size;
            if ((unsigned int)vectorSize <= (unsigned int)elementSize)
            {
                //uh oh
            }
            result = (unsigned int)elementSize;
            this->mp_element[elementSize] = inputVal;
            ++this->m_element_size;
            return result;
        }
    };

    template <typename T, unsigned int size, typename allocator>
    struct t_vector : t_base_vector<T>
    {

    };

    template<typename T, unsigned int someVal, typename allocator>
    struct t_fixed_vector : t_base_vector<T>
    {

    };

    template<typename T, unsigned int count>
    struct t_static_vector : t_base_vector<T>
    {
        //how are these even calculated
        t_aligned_placeholder<T, count, sizeof(T)> m_placeholder;
    };
}