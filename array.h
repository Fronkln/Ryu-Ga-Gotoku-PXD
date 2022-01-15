#pragma once
namespace pxd
{
    template <typename T, unsigned int count>
    struct t_array
    {
    public:
        T m_data[count];

        t_array()
        {
            memset(this, 0, sizeof(T) * count);
        }

        t_array<T, count>* operator=(t_array<T, count>* rhs)
        {
            for (int i = 0; i < count; i++)
                m_data[i] = rhs->m_data[i];

            return this;
        }

        //not part of the original template
        T operator[](unsigned int index)
        {
            return m_data[index];
        }

        //not part of the original template
        void length()
        {
            return count;
        }
    };

    template <typename valtype, typename enumType, unsigned int length, unsigned int some_val_that_always_matches_length>
    struct t_enum_array : pxd::t_array<valtype, length>
    {
    };
}