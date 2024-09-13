#pragma once

#include <stdlib.h>


typedef void* (*generic_function)(void*);
typedef void (*generic_free_function)(void*);


void generic_free(void* param)
{
    free(param);
}
