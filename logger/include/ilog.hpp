#pragma once

#include <string>

namespace local_peregrine
{
    namespace logger
    {
        enum class LogLevel
        {
            kDebug,
            kInfo,
            kWarn,
            kError,
            kFatal
        };

        struct ILog
        {
            void write(LogLevel, std::string message);

            virtual ~ILog() = 0;
        };
    }
}