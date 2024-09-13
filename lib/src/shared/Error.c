#include <stdlib.h>
#include <stdio.h>

#include "lib/include/shared/GenericFunction.h"

#include "lib/include/shared/Error.h"


void error_mne()
{
    perror("MEMORY NOT ENOUGH");
    exit(MEMORY_NOT_ENOUGH);
}


void error_u()
{
    perror("UNKNOWN ERROR");
    exit(UNKNOWN_ERROR);
}

void error_ni()
{
    perror("ERROR CODE NOT IMPLEMENTADED");
    exit(-1);
}


void error_print(const Error e)
{    
    switch (e)
    {
    case NOT_AN_ERROR:
        break;
    case MEMORY_NOT_ENOUGH:
        error_mne();
        break;
    case UNKNOWN_ERROR:
        error_u();
        break;
    default:
        break;
    }
}

