#include "include/string.h"

String *string_new()
{
    return my_malloc(String);
}

void string_ctor(String *const str, const char *const val, const size_t size)
{
    str->val = my_malloc_array(char, size);
    strncpy(str->val, val, size);
    str->cnt = size;
}

void string_dtor(String *str)
{
    free(str->val);
    free(str);
}