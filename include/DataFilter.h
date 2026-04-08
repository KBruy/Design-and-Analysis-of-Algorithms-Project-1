#ifndef DATAFILTER_H
#define DATAFILTER_H

#include "DynamicArray.h"

class DataFilter {
public:
    DynamicArray filterMoviesWithRating(const DynamicArray& movies);
    int countMoviesWithoutRating(const DynamicArray& movies);
    DynamicArray prepareDataSet(const DynamicArray& movies, int size);

    bool isSortedByRating(const DynamicArray& movies);

    double calculateAverageRating(const DynamicArray& movies);
    double calculateMedianRating(const DynamicArray& movies);
};

#endif