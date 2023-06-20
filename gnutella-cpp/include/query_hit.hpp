#pragma once

#include <string>
#include <list>

#include "address.hpp"

struct File
{
    uint32_t index;
    uint32_t size;
    std::string name;
};

struct QueryHit
{
    Address *address;
    std::list<File> files;
};