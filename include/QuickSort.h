#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "DynamicArray.h"

class QuickSort {
private:
    void quickSort(DynamicArray& arr, int left, int right);
    void partition(DynamicArray& arr, int left, int right, int& lessEnd, int& greaterStart);

public:
    void sort(DynamicArray& arr);
};

#endif