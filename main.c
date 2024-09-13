#include <stdio.h>

#include "lib/include/shared/GenericFunction.h"
#include "lib/include/shared/Error.h"
#include "lib/include/shared/Response.h"
#include "lib/include/math/Point2d.h"


int main()
{
    Response* r;

    Point2d* p1 = p2d_create(1, 1);
    Point2d* p2 = p2d_create(2, 2);

    r = p2d_x_distance(p1, p2);
    if(r->error != NOT_AN_ERROR)
        {
            response_free(r);
            error_print(r->error);
        }
    printf("X DISTANCE: %d", *(int*)(r->info));
    response_free_full(r, generic_free);


    r = p2d_y_distance(p1, p2);
    if(r->error != NOT_AN_ERROR)
        {
            response_free(r);
            error_print(r->error);
        }
    printf("\nY DISTANCE: %d", *(int*)(r->info));
    response_free_full(r, generic_free);


    r = p2d_euclidean_distance(p1, p2);
    if(r->error != NOT_AN_ERROR)
        {
            response_free(r);
            error_print(r->error);
        }
    printf("EUCLEDEAN DISTANCE: %.2f", *(double*)(r->info));
    response_free_full(r, generic_free);

    return 0;
}