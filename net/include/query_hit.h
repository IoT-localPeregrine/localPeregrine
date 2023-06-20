#pragma once

#include "address.h"
#include "file.h"

typedef struct {
    Address address;
    List_File files;
} QueryHit;