#pragma once

#include "file.hpp"

namespace local_peregrine
{
    namespace fs
    {
        class Repository
        {
            std::filesystem::path base_dir_;

        public:
            std::list<::File> FindByCriteria(std::string criteria) {
                //TODO
            }
        };
    }
}