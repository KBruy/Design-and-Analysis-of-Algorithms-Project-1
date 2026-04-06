#include "../include/MergeSort.h"

void MergeSort::sort(DynamicArray& arr){ //jeśli tablica ma więcej niż 1 element, to uruchamiamy rekurencje dla całego zakresu
    if (arr.getSize() > 1) {
        mergeSort(arr, 0 ,arr.getSize() - 1);
    }
}
void MergeSort::mergeSort(DynamicArray& arr, int left, int right) {
    if (left >= right) { //warunek końca rekurencji
        return;
    }

int mid = (left + right) / 2;

//najpierw sortujemy lewą połowę, potem prawą
mergeSort(arr, left, mid); 
mergeSort(arr, mid + 1, right);

merge(arr, left, mid, right); //scalenie posortowanych części w jedną
}

void MergeSort::merge(DynamicArray& arr, int left, int mid, int right){

    DynamicArray temp; //tab pomocnicza do której odkładamy elementy w dobrej kolejności

    int i = left; // lewa połowa
    int j = mid + 1; // prawa połowa


    // Dopóki w obu połowach są elementy to porównujemy rankingu i mniejszy dokładamy do temp.
    // Jeśli lewy element ma mniejszy albo równy ranking, bierzemy lewy
    // W przeciwnym razie bierzemy prawy

    while (i <= mid && j <= right) {
        if (arr.get(i).getRanking() <= arr.get(j).getRanking()){
            temp.pushBack(arr.get(i));
            i++;
        } else {
            temp.pushBack(arr.get(j));
            j++;
        }
    }

    // W sytuacji gdy jedna z połówek się już skończyła a w drugiej mogą zostać jeszcze elementy
    // Dokładamy resztę lewej części lub prawej
    while (i <= mid) {
        temp.pushBack(arr.get(i));
        i++;
    }

    while (j <= right){
        temp.pushBack(arr.get(j));
        j++;
    }


    // Przypisujemy wynik scalania z temp do arr
    for (int k = 0; k < temp.getSize(); k++){
        arr.get(left + k) = temp.get(k);
    }
}