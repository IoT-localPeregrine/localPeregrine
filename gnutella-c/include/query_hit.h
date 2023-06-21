#pragma once

extern "C"
{
#include "file.h"

    typedef struct
    {
        /*
        Deleted: Вырезали по причине того, что адрес будет заполняться на уровне сетевого протокола
        Address address;
        */
        List_File *files;
    } QueryHit;
}