#include "../include/QuickSort.h"

//jeśli tablica ma więcej niż 1 element to odpalamy quicksort dla całego zakresu
void QuickSort::sort(DynamicArray& arr){
    if (arr.getSize() > 1) {
        quickSort(arr, 0, arr.getSize() - 1);
    }
}

void QuickSort::quickSort(DynamicArray& arr, int left, int right) {
    if (left >= right) { //warunek kończący rekurencje
        return;
    }

    int pivotIndex = partition(arr, left, right);

    quickSort(arr, left, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, right);
}

int QuickSort::partition(DynamicArray& arr, int left, int right) {
    double pivot = arr.get(right).getRanking();
    int i = left;


    //jeśli element ma ranking <= pivot to zamieniamy go z elementem na pozycji i oraz przesuwamy i
    for (int j = left; j < right; j++){
        if (arr.get(j).getRanking() <= pivot) {
            Movie temp = arr.get(i);
            arr.get(i) = arr.get(j);
            arr.get(j) = temp;
            i++;
        }
    }

    //Wstawiamy pivot na pozycję i, czyli tam gdzie powinien być po podziale
    Movie temp = arr.get(i);
    arr.get(i) = arr.get(right);
    arr.get(right) = temp;

    return i; //zwracamy końcową pozycję pivota żeby później móc podzielić tab na lewą i prawą część
}