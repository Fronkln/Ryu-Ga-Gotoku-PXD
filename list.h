#pragma once
namespace pxd
{
    template<typename T>
    struct t_intrusive_list
    {
        class node_t
        {
            T* mp_base;
            t_intrusive_list<T>::node_t* mp_prev;
            t_intrusive_list<T>::node_t* mp_next;
        };
    };

    template<typename T>
    struct t_pointer_list_linker
    {
    };

    template<typename T, typename linker>
    struct t_pointer_list
    {
        T *mp_top;
        T *mp_bottom;
    };
}