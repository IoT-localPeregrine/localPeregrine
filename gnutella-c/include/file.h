#pragma once

#include "utils.h"
#include "sstring.h"
#include "list.h"

typedef struct {
    uint32_t index;
    uint32_t size;
    SString name;
} File;

LIST_DECLARE(File);