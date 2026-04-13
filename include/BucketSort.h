#ifndef BUCKETSORT_H
#define BUCKETSORT_H

#include "DynamicArray.h"

class BucketSort {
private:
    int getBucketIndex(double rating, double minRating, double maxRating, int bucketCount);
    double findMinRating(const DynamicArray& arr);
    double findMaxRating(const DynamicArray& arr);
    void insertionSort(DynamicArray& arr);

public:
    void sort(DynamicArray& arr);
};

#endif