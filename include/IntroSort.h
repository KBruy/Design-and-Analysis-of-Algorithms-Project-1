#ifndef INTROSORT_H
#define INTROSORT_H

#include "DynamicArray.h"

class IntroSort {
    private:
        void introSort(DynamicArray& arr, int left, int right, int depthLimit);
        void partition(DynamicArray& arr, int left, int right, int& lessEnd, int& greaterStart); // podział 3-way partition
        void heapSort(DynamicArray& arr, int left, int right); //jeśli reku przekroczy limit, przejście na heapsort dla danego fragmentu tablicy
        void heapify(DynamicArray& arr, int heapSize, int rootIndex, int offset); //metoda pomocnicza do heapsorta
        int calculateDepthLimit(int size); //limit głębokości rekurencji

    public:
        void sort(DynamicArray& arr); //wejscie do algorytmu
};


#endif