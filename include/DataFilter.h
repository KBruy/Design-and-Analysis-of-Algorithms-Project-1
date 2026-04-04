#ifndef DATAFILTER_H
#define DATAFILTER_H

#include "DynamicArray.h"

class DataFilter {
public:
    DynamicArray filterMoviesWithRating(const DynamicArray& movies);
    int countMoviesWithoutRating(const DynamicArray& movies);
};

#endif