#pragma once

#include <string.h>

#include "utils.h"

typedef struct
{
    char *val;
    size_t cnt;
} SString;

SString *string_new();

void string_ctor(SString *const str, const char *const val, const size_t size);
void string_dtor(SString *str);