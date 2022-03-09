#pragma once
#include <stdio.h>

struct Room
{
    int number;    // số phòng
    char type[20]; // loại phòng
    bool status;   // tình trạng phòng - 0:trống   1:đầy
};