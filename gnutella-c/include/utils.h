#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

#define my_clear(PTR) memset(PTR, 0, sizeof(typeof(*PTR)))
#define my_malloc(T) ((T *)malloc(sizeof(T)))
#define my_calloc(T) ((T *)calloc(1, sizeof(T)))

#define my_malloc_array(T, count) ((T *)malloc(sizeof(T) * count))
