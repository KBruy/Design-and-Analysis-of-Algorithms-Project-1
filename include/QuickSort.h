#ifndef QUICSORT_H
#define QUICSORT_H

#include "DynamicArray.h"

class QuickSort {

    private:
        void quickSort(DynamicArray& arr, int left, int right); // bierze fragment tablicy i sortuje go w miejscu
        void partition(DynamicArray& arr, int left, int right, int& lessEnd, int& greaterStart); // dzieli zakres na < pivot, == pivot i > pivot

    public:
        void sort(DynamicArray& arr); //wywoływane z menu

};

#endif
