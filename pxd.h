#pragma once
#include <xmmintrin.h>
#include <cstdint>
#include "unknownstructs.h"

#include "sbgl.h"
#include "threading.h"
#include "array.h"
#include "vector.h"
#include "list.h"


enum class e_heap_category : unsigned char
{

    global,		 // constant 0x0
    resident,		 // constant 0x1
    stage,		 // constant 0x2
    navimesh_res,		 // constant 0x3
    navimesh_gen,		 // constant 0x4
    collision,		 // constant 0x5
    character,		 // constant 0x6
    entity,		 // constant 0x7
    scene,		 // constant 0x8
    sound,		 // constant 0x9
    physics,		 // constant 0xA
    effect,		 // constant 0xB
    ui,		 // constant 0xC
    msg,		 // constant 0xD
    script,		 // constant 0xE
    resource,		 // constant 0xF
    temp,		 // constant 0x10
    debug,		 // constant 0x11
    tool,		 // constant 0x12
    invalid,		 // constant 0x13
    num,		 // constant 0x13
};


//pxd: Dragon Engine proprietary library
namespace pxd
{
    class cgs_mesh;

    namespace sl
    {
        struct handle_t
        {
            $081A7393FF78DEED396C29788378B83B ___u0;
        };

        struct __declspec(align(16)) mutex_t
        {
            //_RTL_CRITICAL_SECTION m_cs;
            uint8_t m_cs[0x28];
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

    struct rwspinlock_t
    {
        volatile unsigned int m_lock_status;
    };


    const struct csl_hash
    {
        union
        {
            struct
            {
                unsigned __int16 m_hash_id;
                char m_sz_hash_name[30];
            };
            unsigned __int64 m_hash[4];
        };
    };


    struct gs_pattern_t
    {
        __int16 pattern[2];
        float f_ratio;
    };

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


    struct cpr_sphere
    {
        union
        {
            //vec4f
            __m128 m_center;
            struct
            {
                float m_center_x;
                float m_center_y;
                float m_center_z;
                float m_radius;
            };
        };
    };

    struct cpr_aabox : cpr_sphere
    {
        union
        {
            __m128 m_extent;
            struct
            {
                float m_extent_x;
                float m_extent_y;
                float m_extent_z;
                float m_extent_w;
            };
        };
    };


    struct cpr_orbox : pxd::cpr_aabox
    {
        quaternion m_orient;
    };


    template <typename firstT, typename secondT>
    struct t_pair
    {
    public:
        firstT first;
        secondT second;
    };

    template<typename T, unsigned int someNum>
    struct t_static_deque
    {
        T *mp_element;
        unsigned int m_deque_size;
        unsigned int m_element_size;
        unsigned int m_index_begin;
        unsigned int m_index_end;
        pxd::t_aligned_placeholder<T, someNum + 1, 4> m_placeholder; //its not always 4. but it is for 90% of the time
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

    template <typename T>
    struct t_status_ptr
    {
        union
        {
            struct
            {
                __int64 m_ptr : 48;
                unsigned __int64 m_status : 16;
            };

            unsigned __int64 m_status_ptr;
        };
    };


    template<typename function>
    struct t_function
    {
        union
        {
            struct
            {
                void *vtbl;
                function* func;
                void *placeholder1;
                void *placeholder2;
            };
            void *m_functor_holder[4];
            struct
            {
                uint8_t gap0[8];
                void *placeholder0;
            };
        };
    };

    template <typename T, typename spinlock, typename allocator, typename invoker>
    struct t_sync_delegate
    {
        uint8_t placeholder[0x28];
    };

    template <typename T>
    struct t_const_traits
    {
    };
    template <typename T>
    struct t_nonconst_traits
    {
    };


    template <typename T, typename traits, typename instance_list, typename traits2, typename linker>
    // base    pxd::t_list_iterator_base<pxd::t_instance_list<ec_handle<cec_ccc>, pxd::t_aligned_allocator<pxd::t_instance_list_node_struct<ec_handle<cec_ccc> >, 0> >::node_t, pxd::t_nonconst_traits<pxd::t_instance_list<ec_handle<cec_ccc>, pxd::t_aligned_allocator<pxd::t_instance_list_node_struct<ec_handle<cec_ccc> >, 0> >::node_t>, pxd::t_pointer_list_linker<pxd::t_instance_list<ec_handle<cec_ccc>, pxd::t_aligned_allocator<pxd::t_instance_list_node_struct<ec_handle<cec_ccc> >, 0> >::node_t> >
    struct t_node_list_iterator
    {
    };


    template <typename functionType, typename allocator>
    struct t_delegate_invoker
    {
        pxd::t_instance_list<pxd::t_function<functionType>, allocator> *m_list;
        void* it_current;
        void* it_next;
      //  pxd::t_node_list_iterator<pxd::t_function<functionType>, pxd::t_const_traits<pxd::t_function<functionType> >, pxd::t_instance_list<pxd::t_function<functionType>, pxd::t_aligned_allocator<pxd::t_instance_list_node_struct<pxd::t_function<functionType> >, 0> >::node_t, pxd::t_const_traits<pxd::t_instance_list<pxd::t_function<functionType>, pxd::t_aligned_allocator<pxd::t_instance_list_node_struct<pxd::t_function<functionType> >, 0> >::node_t>, pxd::t_pointer_list_linker<pxd::t_instance_list<pxd::t_function<functionType>, pxd::t_aligned_allocator<pxd::t_instance_list_node_struct<pxd::t_function<functionType> >, 0> >::node_t> > *it_current;
      //  pxd::t_node_list_iterator<pxd::t_function<functionType>, pxd::t_const_traits<pxd::t_function<functionType> >, pxd::t_instance_list<pxd::t_function<functionType>, pxd::t_aligned_allocator<pxd::t_instance_list_node_struct<pxd::t_function<functionType> >, 0> >::node_t, pxd::t_const_traits<pxd::t_instance_list<pxd::t_function<functionType>, pxd::t_aligned_allocator<pxd::t_instance_list_node_struct<pxd::t_function<functionType> >, 0> >::node_t>, pxd::t_pointer_list_linker<pxd::t_instance_list<pxd::t_function<functionType>, pxd::t_aligned_allocator<pxd::t_instance_list_node_struct<pxd::t_function<functionType> >, 0> >::node_t> > *it_next;
    };


    template <typename functionType, typename allocator, typename invoker>
    struct t_delegate
    {
        pxd::t_instance_list<pxd::t_function<functionType>, allocator> m_list;
        uint8_t m_it_current[0x8]; // temp
        uint8_t m_it_next[0x8]; // temp

       // pxd::t_node_list_iterator<pxd::t_function<functionType>, pxd::t_const_traits<pxd::t_function<functionType> >, pxd::t_instance_list<pxd::t_function<functionType>, allocator>::node_t, pxd::t_const_traits<pxd::t_instance_list<pxd::t_function<functionType>, allocator>::node_t>, pxd::t_pointer_list_linker<pxd::t_instance_list<pxd::t_function<functionType>, allocator>::node_t> > m_it_current;
        //pxd::t_node_list_iterator<functionType, pxd::t_const_traits<pxd::t_function<functionType> >, pxd::t_instance_list<pxd::t_function<functionType>, allocator >::node_t, pxd::t_const_traits<pxd::t_instance_list<pxd::t_function<functionType>, allocator >::node_t>, pxd::t_pointer_list_linker<pxd::t_instance_list<pxd::t_function<functionType>, allocator>::node_t> > m_it_next;
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

    template <typename T, typename T2>
    struct t_compare
    {
    };

    //Only used at one place in DE. Not really important?
    template<typename T>
    struct t_unique_id
    {
        pxd::spinlock_t m_sync;
        unsigned int m_capacity;
        unsigned int m_active_num;
        unsigned int m_current_idx;
        pxd::t_vector<unsigned __int64 *, 16, T> m_tbl_vector;
    };

    template <typename T>
    struct t_avl_tree_node
    {
        class pair_t
        {
            pxd::t_status_ptr<T> mp_left;
            pxd::t_status_ptr<T> mp_right;
        };

        //i..umm.. both classes are fucking same?
        pxd::t_status_ptr<T> mp_left;
        pxd::t_status_ptr<T> mp_right;
    };

    //no clue if the definition is correct
    template <typename T, typename T2, typename T3, unsigned int num>
    struct t_avl_tree
    {
        pxd::t_avl_tree_node<T> *mp_root;
    };


    template<typename T, typename T2>
    class t_instance_map_pair_struct
    {
        pxd::t_avl_tree_node<T2> node;
        T first;
        T2 *second;
    };

    template<typename T, typename T2, typename comparer, typename allocator>
    class t_instance_map
    {
    public:
        struct linker_t
        {
        };

        struct pair_t
        {
            pxd::t_avl_tree_node<pxd::t_instance_map<T, T2, comparer, allocator>::pair_t> node;
            T first;
            T2 *second;
        };

        //improve definition
        pxd::t_avl_tree<pxd::t_instance_map<T, T2, comparer, allocator>::pair_t, T, pxd::t_instance_map<T, T2, comparer, allocator>::linker_t, 24> m_tree;
    };


    template <typename T, unsigned int some_num, typename allocator>
    class t_deque
    {
        T *mp_element;
        unsigned int m_deque_size;
        unsigned int m_element_size;
        unsigned int m_index_begin;
        unsigned int m_index_end;
    };

    template <typename T>
    struct t_lockfree_ptr
    {
        struct counter_ptr_t
        {
            union
            {
                struct
                {
                    __int64 m_ptr : 48;
                    __int64 m_counter : 16;
                };
                unsigned __int64 m_quad_ptr;
            };
        };

        pxd::t_lockfree_ptr<T>::counter_ptr_t m_counter_ptr;
    };


    template <typename T>
    class t_lockfree_stack_native_linker
    {

    };

    template <typename T, typename linker>
    class t_lockfree_stack
    {
        pxd::t_lockfree_ptr<T> m_top;

        //ida pro you better not fail me you piece of shit

    public:
        T* pop()
        {

        }
    };
}