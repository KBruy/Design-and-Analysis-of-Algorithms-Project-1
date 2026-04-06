#include "../include/QuickSort.h"

void QuickSort::sort(DynamicArray& arr) {
    if (arr.getSize() > 1) {
        quickSort(arr, 0, arr.getSize() - 1);
    }
}

//3-way partition
void QuickSort::quickSort(DynamicArray& arr, int left, int right) {
    
    if (left >= right) { // warunek stopu rekurencji
        return;
    }

    int lessEnd; //wyznaczają środkowy zakres elementów równych pivotowi (po wykonaniu partition) 
    int greaterStart;

    // dzielimy tablicę na 3 części: mniejsze od pivota, równe i większe
    partition(arr, left, right, lessEnd, greaterStart);

    // rekurencyjne sortowanie tylko części mniejszej od pivota
    quickSort(arr, left, lessEnd - 1);

    // tylko część większa od pivota
    quickSort(arr, greaterStart + 1, right);
}

void QuickSort::partition(DynamicArray& arr, int left, int right, int& lessEnd, int& greaterStart) {
    // Jako pivot wybieramy ostatni element zakresu
    double pivot = arr.get(right).getRanking();

    int lessIndex = left; //początek obszaru elementów równych pivotowi
    int currentIndex = left; //aktualnie sprawdzany element
    int greaterIndex = right; //koniec obszaru elementów równych pivotowi

    // Przechodzimy po tablicy dopóki currentIndex nie minie greaterIndex
    while (currentIndex <= greaterIndex) {
        // Jeśli bieżący element jest mniejszy od pivota to przenosimy go na początek
        if (arr.get(currentIndex).getRanking() < pivot) {
            Movie temp = arr.get(lessIndex);
            arr.get(lessIndex) = arr.get(currentIndex);
            arr.get(currentIndex) = temp;

            lessIndex++;
            currentIndex++;
        }
        // Jeśli bieżący element jest większy od pivota, to przenosimy go na koniec
        else if (arr.get(currentIndex).getRanking() > pivot) {
            Movie temp = arr.get(currentIndex);
            arr.get(currentIndex) = arr.get(greaterIndex);
            arr.get(greaterIndex) = temp;

            greaterIndex--;
        }
        // Jeśli bieżący element jest równy pivotowi, zostawiamy go w środkowej części i idziemy dalej
        else {
            currentIndex++;
        }
    }

    // Zwracamy granice środkowego zakresu elementów równych pivotowi
    lessEnd = lessIndex;
    greaterStart = greaterIndex;
}