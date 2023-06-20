#pragma once

#include <string.h>

#include "utils.h"

typedef struct
{
    char *val;
    size_t cnt;
} String;

String *string_new();

void string_ctor(String *const str, const char *const val, const size_t size);
void string_dtor(String *str);