#pragma once

#include <string>
#include <filesystem>

namespace local_peregrine
{
    namespace fs
    {
        struct File
        {
            std::filesystem::path path;
        };
    }
}