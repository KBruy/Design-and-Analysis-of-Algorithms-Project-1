#ifndef QUICSORT_H
#define QUICSORT_H

#include "DynamicArray.h"

class QuickSort {

    private:
        void quickSort(DynamicArray& arr, int left, int right); // bierze fragment tablicy, dzieli go i wywołuje samą siebie dla lewej i prawej części
        int partition(DynamicArray& arr, int left, int right); //wybiera pivot, ustawiwa mniejsze elementy po jednej stronie, większe po drugiej, zwraca końcową pozycję pivota

    public:
        void sort(DynamicArray& arr); //wywoływane z menu

};

#endif