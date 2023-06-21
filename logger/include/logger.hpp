#pragma once

#include "ilog.hpp"

namespace local_peregrine
{
    namespace logger
    {
        class Logger
        {
            std::unique_ptr<ILog> log_driver_;
        };
    }
}