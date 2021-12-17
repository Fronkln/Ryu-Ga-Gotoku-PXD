#pragma once
//rw spinlock


namespace pxd
{
    struct $448937D484C8D788B4D8A9D7CDD6B1B4
    {
        unsigned __int32 ref_count : 16;
        unsigned __int32 thread_sid : 16;
    };


    struct $4CF3E51AF38D69769AFF2ACB8C496C0A
    {
        unsigned __int32 m_bank : 20;
        unsigned __int32 m_serial : 12;
    };

    union $081A7393FF78DEED396C29788378B83B
    {
        $4CF3E51AF38D69769AFF2ACB8C496C0A __s0;
        unsigned int m_handle;
    };

}
