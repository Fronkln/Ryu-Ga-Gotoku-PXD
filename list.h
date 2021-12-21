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

    template <typename T>
    struct t_instance_list_node_struct
    {
        T* m_value;
        void *mp_prev;
        void *mp_next;
    };


    template <typename T, typename allocator>
    struct t_instance_list
    {
        struct node_t
        {
            T* m_value;
            pxd::t_instance_list<T*, allocator>::node_t *mp_prev;
            pxd::t_instance_list<T*, allocator>::node_t *mp_next;
        };

        pxd::t_pointer_list<pxd::t_instance_list<T, allocator>::node_t, pxd::t_pointer_list_linker<pxd::t_instance_list<T, allocator>::node_t>> m_list;
    };
}