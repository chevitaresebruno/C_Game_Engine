#pragma once


typedef enum Error
{
    NOT_AN_ERROR,
    INVALID_PARAMS,
    MEMORY_NOT_ENOUGH,
    UNKNOWN_ERROR
} Error;


void error_print(const Error e);

