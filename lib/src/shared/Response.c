#include <stdlib.h>
#include <stdio.h>

#include "lib/include/shared/GenericFunction.h"
#include "lib/include/shared/Error.h"

#include "lib/include/shared/Response.h"


void response_free(Response* r)
{
    if(r != NULL)
        free(r);
}


void response_free_full(Response* r, generic_free_function iff)
{
    if(r == NULL)
        return;
    
    iff(r->info);
    free(r);
}


Response* response_create()
{
    Response* r;

    r = (Response*)malloc(sizeof(Response));

    if(r == NULL)
        error_print(MEMORY_NOT_ENOUGH);
    
    r->info = malloc(sizeof(int));
    if(r->info == NULL)
        {
            free(r);
            error_print(MEMORY_NOT_ENOUGH);
        }

    return r;
}

Response* response_create_andInsert(const Error e, void* info)
{
    Response* r;

    r = (Response*)malloc(sizeof(Response));

    if(r == NULL)
        error_print(MEMORY_NOT_ENOUGH);
    
    r->error = e;
    r->info = info;

    return r;
}

Response* response_create_andCopy(const Error e, void* info, generic_function info_copy)
{
    Response* r;

    r = (Response*)malloc(sizeof(Response));

    if(r == NULL)
        error_print(MEMORY_NOT_ENOUGH);
    
    r->info = info_copy(info);
    if(r->info == NULL)
        {
            free(r);
            error_print(MEMORY_NOT_ENOUGH);
        }  

    r->error = e;

    return r;
}

