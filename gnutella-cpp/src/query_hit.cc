#include "gnutella-cpp/include/query_hit.hpp"

gnutella_cpp::QueryHit::operator ::QueryHit() const
{
    List_File *lf = list_File_new();
    for (auto &i : files)
    {
        list_File_push_back(lf, i);
    }

    return (::QueryHit){.files = lf};
}