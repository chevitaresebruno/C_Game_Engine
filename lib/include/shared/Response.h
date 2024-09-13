#pragma once


#include "lib/include/shared/Error.h"
#include "lib/include/shared/GenericFunction.h"


typedef struct r
{
    Error error;
    void* info;
} Response;


void response_free(Response* r);

void response_free_full(Response* r, generic_free_function info_free_function);


Response* response_create();

Response* response_create_andInsert(const Error e, void* info);

Response* response_create_andCopy(const Error e, void* info, generic_function info_copy);

