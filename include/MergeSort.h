#ifndef MERGESORT_H
#define MERGESORT_H

#include "DynamicArray.h"

class MergeSort{
    private:
    void merge(DynamicArray& arr, int left, int mid, int right);
    void mergeSort(DynamicArray& arr, int left, int right);

    public:
    void sort(DynamicArray& arr);
};

#endif