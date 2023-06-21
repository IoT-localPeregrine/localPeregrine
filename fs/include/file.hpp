#pragma once

#include <filesystem>

#include "gnutella-cpp/include/query_hit.hpp"

namespace local_peregrine
{
    namespace fs
    {
        struct File : ::File
        {
            std::filesystem::path sys_path;
        };
    }
}