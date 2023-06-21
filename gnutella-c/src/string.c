#include "include/string.h"

SString *string_new()
{
    return my_malloc(SString);
}

void string_ctor(SString *const str, const char *const val, const size_t size)
{
    str->val = my_malloc_array(char, size);
    strncpy(str->val, val, size);
    str->cnt = size;
}

void string_dtor(SString *str)
{
    free(str->val);
    free(str);
}