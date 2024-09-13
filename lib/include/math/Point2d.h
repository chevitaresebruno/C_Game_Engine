#pragma once

#include "lib/include/shared/Bool.h"
#include "lib/include/shared/Response.h"


typedef struct p2d
{
    int x;
    int y;
} Point2d;


Point2d* p2d_create(const int x_axis, const int y_axis);


void p2d_free(Point2d* point_2d);


Response* p2d_x_distance(const Point2d* first_point, const Point2d* second_point);

Response* p2d_y_distance(const Point2d* first_point, const Point2d* second_point);

Response* p2d_euclidean_distance(const Point2d* first_point, const Point2d* second_point);

