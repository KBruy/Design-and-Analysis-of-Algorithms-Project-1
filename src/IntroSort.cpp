#include "../include/IntroSort.h"
#include <cmath>

void IntroSort::sort(DynamicArray& arr){
    if (arr.getSize() > 1) {
        int depthLimit = calculateDepthLimit(arr.getSize());
        introSort(arr, 0, arr.getSize() - 1, depthLimit);
    }
}

void IntroSort::introSort(DynamicArray& arr, int left, int right, int depthLimit){
    if (left >= right) {
        return;
    }

    //po przekroczeniu limitu przechodzimy na heapsorty dla danego fragmentu taba
    if (depthLimit <= 0){
        heapSort(arr, left, right);
        return;
    }

    int lessEnd;
    int greaterStart;

    //dzielenie danych na mniejsze, równe i większe od pivota
    partition(arr, left, right, lessEnd, greaterStart);

    //rekurencyjne sortowanie częsci mniejszej
    introSort(arr, left, lessEnd - 1, depthLimit - 1);
    introSort(arr, greaterStart + 1, right, depthLimit - 1); //większej

}

void IntroSort::partition(DynamicArray& arr, int left, int right, int& lessEnd, int& greaterStart){


    double pivot = arr.get(right).getRanking();

    int lessIndex = left; //początek obszaru ele równych pivotowi
    int currentIndex = left; //aktualnie sprawdzany element
    int greaterIndex = right; //koniec obszaru elementów równych pivotowi

    //od left do lessEnd - 1 -> mniejsze pivotowi
    //od lessEnd do greaterStart -> równe pivotowi
    // od greaterStart + 1 do right -> większe pivotowi



    //przejscie po zakresie i ułożenie ele w 3 grupy
    while (currentIndex <= greaterIndex){
        //element mniejszy od pivota przenosimy na lewo
        if (arr.get(currentIndex).getRanking() < pivot) {
            Movie temp = arr.get(lessIndex);
            arr.get(lessIndex) = arr.get(currentIndex);
            arr.get(currentIndex) = temp;

            lessIndex++;
            currentIndex++;
        }

        //element wiekszy od pivota przenosimy na prawo
        else if (arr.get(currentIndex).getRanking() > pivot) {
            Movie temp = arr.get(currentIndex);
            arr.get(currentIndex) = arr.get(greaterIndex);
            arr.get(greaterIndex) = temp;

            greaterIndex--;
        }

        //element równy pivotowi zostawiamy w środkowej części
        else {
            currentIndex++;
        }
        
    }

    //Zwracamy granice środkowego obszaru elementow równych pivotowi
    lessEnd = lessIndex;
    greaterStart = greaterIndex;
}

void IntroSort::heapSort(DynamicArray& arr, int left, int right){

    int heapSize = right - left + 1; //rozmiar fragmentu tablicy który chcemy posortować

    //najwiekszy element jest na początku kopcja -> zamieniamy go z ostatnim elementem kopca i zmniejszamy kopiec
    for (int i = heapSize - 1; i>0; i--) {
        Movie temp = arr.get(left);
        arr.get(left) = arr.get(left + i);
        arr.get(left + i) = temp;

        //przywracamy własności kopca dla pomniejszonego kopcja
        heapify(arr, i, 0, left);
    }
}

void IntroSort::heapify(DynamicArray& arr, int heapSize, int rootIndex, int offset){
    int largestIndex = rootIndex; //zakładamy że największy element jest w korzeniu

    //lewy i prawy syn w kopcu zapisanym w tablicy
    int leftChild = 2 * rootIndex + 1;
    int rightChild = 2 * rootIndex + 2;

    // jeśli lewy syn istnieje i jest większy od aktualnie największego
    if (leftChild < heapSize && arr.get(offset + leftChild).getRanking() > arr.get(offset + largestIndex).getRanking()){
        largestIndex = leftChild;
    }

    //jeśli prawy syn istnieje i jest większy od aktualnie największego
    if (rightChild < heapSize && arr.get(offset + rightChild).getRanking() > arr.get(offset + largestIndex).getRanking()){
        largestIndex = rightChild;
    }

    //kiedy największy ele nie jest już w korzeniu zamieniamy miejscami i naprawiamy kopiec niżej
    if (largestIndex != rootIndex) {
        Movie temp = arr.get(offset + rootIndex);
        arr.get(offset + rootIndex) = arr.get(offset + largestIndex);
        arr.get(offset + largestIndex) = temp;

        heapify(arr, heapSize, largestIndex, offset);

        heapify(arr, heapSize, largestIndex, offset);
    }
}

int IntroSort::calculateDepthLimit(int size){
    //limit głębokości w przybliżeniu na 2 * log2(n)

    return 2 * static_cast<int>(std::log2(size));
}

