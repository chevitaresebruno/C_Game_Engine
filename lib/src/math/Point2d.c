#include <stdlib.h>
#include <math.h>

#include "lib/include/math/Point2d.h"


Point2d* p2d_create(const int x, const int y)
{
    Point2d* p2d;

    p2d = (Point2d*)malloc(sizeof(Point2d));

    if(p2d == NULL)
        return NULL;

    p2d->x = x;
    p2d->y = y;

    return p2d;
}


void p2d_free(Point2d* p2d)
{
    if(p2d != NULL)
        free(p2d);
}


Response* p2d_x_distance(const Point2d* fp, const Point2d* sp)
{
    Response* r;

    r = response_create();

    if(fp == NULL || sp == NULL)
        {
            r->error = INVALID_PARAMS;
            return r;
        }
    
    r->info = (void*)abs(fp->x - sp->x);
    r->error = NOT_AN_ERROR;

    return r;
}

Response* p2d_y_distance(const Point2d* fp, const Point2d* sp)
{
    Response* r;

    r = response_create();

    if(fp == NULL || sp == NULL)
        {
            r->error = INVALID_PARAMS;
            return r;
        }
    
    r->info = (void*)abs(fp->y - sp->y);
    r->error = NOT_AN_ERROR;

    return r;
}

Response* p2d_euclidean_distance(const Point2d* fp, const Point2d* sp)
{
    Response* r;
    int x, y;
    double i;

    r = response_create();

    if(fp == NULL || sp == NULL)
        {
            r->error = INVALID_PARAMS;
            return r;
        }

    x = abs(fp->x - sp->x);
    y = abs(fp->y - sp->y);

    i = sqrt(x*x + y*y);
    
    r->info = &i;
    r->error = NOT_AN_ERROR;

    return r;
}

