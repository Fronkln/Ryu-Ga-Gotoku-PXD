#pragma once
#include <d3d11.h>
namespace sbgl
{
    struct ccommon
    {
    };


    struct cdevice_common : ccommon
    {
    };

    struct casync_native : cdevice_common
    {
        union
        {
            struct
            {
                sbgl::casync_native *m_p_async_array;
                uint8_t gap8[4];
                unsigned int m_num_arrays;
            };

            ID3D11Query *m_pD3DQuery;
            ID3D11Predicate *m_pD3DPredicate;
            void *m_p_rsrc;
            __m128 m_dummy_for_inheritance_probrem;
           
            struct
            {
                uint8_t gap0[8];
                unsigned __int32 m_state : 8;
                unsigned __int32 m_type : 8;
            };
        };
    };

    struct cbase_async : casync_native
    {
    };


    struct casync_occlusion : cbase_async
    {
    };


    struct csbgl_async_occlusion_gs : casync_occlusion
    {
    };
}