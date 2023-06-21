#pragma once

#include <string>
#include <list>

struct File
{
    uint32_t index;
    uint32_t size;
    std::string name;
};

namespace gnutella_cpp
{
    struct QueryHit
    {
        std::list<File> files;

        QueryHit(std::list<File> ctor_files) : files(ctor_files) {}
    };
}