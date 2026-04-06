#include "../include/QuickSort.h"
#include <utility>

//jeśli tablica ma więcej niż 1 element to odpalamy quicksort dla całego zakresu
void QuickSort::sort(DynamicArray& arr){
    if (arr.getSize() > 1) {
        quickSort(arr, 0, arr.getSize() - 1);
    }
}

void QuickSort::quickSort(DynamicArray& arr, int left, int right) {
    while (left < right) {
        int lessEnd;
        int greaterStart;
        partition(arr, left, right, lessEnd, greaterStart);

        // Rekurencyjnie sortujemy tylko mniejszą część, żeby ograniczyć głębokość stosu.
        if (lessEnd - left < right - greaterStart) {
            quickSort(arr, left, lessEnd);
            left = greaterStart;
        } else {
            quickSort(arr, greaterStart, right);
            right = lessEnd;
        }
    }
}

void QuickSort::partition(DynamicArray& arr, int left, int right, int& lessEnd, int& greaterStart) {
    double pivot = arr.get(left + (right - left) / 2).getRanking();
    int less = left;
    int current = left;
    int greater = right;

    while (current <= greater) {
        double ranking = arr.get(current).getRanking();

        if (ranking < pivot) {
            std::swap(arr.get(less), arr.get(current));
            less++;
            current++;
        } else if (ranking > pivot) {
            std::swap(arr.get(current), arr.get(greater));
            greater--;
        } else {
            current++;
        }
    }

    lessEnd = less - 1;
    greaterStart = greater + 1;
}
