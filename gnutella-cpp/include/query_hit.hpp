#pragma once

#include <string>
#include <list>

#include "gnutella-c/include/file.h"
#include "gnutella-c/include/query_hit.h"

extern "C"
{
    namespace gnutella_cpp
    {
        struct QueryHit
        {
            std::list<File *> files;

            QueryHit(std::list<File *> ctor_files) : files(ctor_files) {}

            operator ::QueryHit() const;
        };
    }
}