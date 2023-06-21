#pragma once

#include <string>

#include "./gnutella-c/include/string.h"

namespace gnutella_cpp
{
    namespace utils
    {
        std::string FromSString(SString sstr)
        {
            return std::string(sstr.val, sstr.cnt);
        }

        SString ToSString(std::string std_string)
        {
            return (SString){.val = const_cast<char *>(std_string.c_str()), .cnt = std_string.length()};
        }
    }
}