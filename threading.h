#pragma once
#include "unknownstructs.h"
namespace pxd
{
    struct spinlock_t
    {
        volatile unsigned int m_lock_status;
    };

    struct recursive_spinlock_t
    {
        unsigned int m_lock_status;
    };

    struct recursive_rwspinlock_t
    {
    public:
        volatile union lock_status_t
        {
            volatile unsigned int status;
            $448937D484C8D788B4D8A9D7CDD6B1B4 __s1;
        };


        pxd::recursive_rwspinlock_t::lock_status_t m_lock_status;
    };


    template <typename spinlock, typename T>
    struct t_sync : T
    {
        spinlock m_sync_object;
    };

}