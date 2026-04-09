#include "../include/BucketSort.h"

int BucketSort::getBucketIndex(double rating, double minRating, double maxRating, int bucketCount) {
    // jeśli wszystkie elementy mają tę samą wartość, wrzucamy wszystko do pierwszego kubełka
    if (maxRating == minRating) {
        return 0;
    }

    // Wyznaczamy pozycję wartości w zakresie od minRating do maxRating
    double normalizedValue = (rating - minRating) / (maxRating - minRating);

    // Na tej podstawie wyliczamy numer kubełka
    int index = static_cast<int>(normalizedValue * bucketCount);

    // Jeśli wartość trafi dokładnie w górną granicę, poprawiamy indeks na ostatni kubełek
    if (index >= bucketCount) {
        index = bucketCount - 1;
    }

    if (index < 0) {
        index = 0;
    }

    return index;
}

double BucketSort::findMinRating(const DynamicArray& arr) {
    double minRating = arr.get(0).getRanking();

    for (int i = 1; i < arr.getSize(); i++) {
        if (arr.get(i).getRanking() < minRating) {
            minRating = arr.get(i).getRanking();
        }
    }

    return minRating;
}

double BucketSort::findMaxRating(const DynamicArray& arr) {
    double maxRating = arr.get(0).getRanking();

    for (int i = 1; i < arr.getSize(); i++) {
        if (arr.get(i).getRanking() > maxRating) {
            maxRating = arr.get(i).getRanking();
        }
    }

    return maxRating;
}

void BucketSort::insertionSort(DynamicArray& arr) {
    for (int i = 1; i < arr.getSize(); i++) {
        Movie key = arr.get(i);
        int j = i - 1;

        // Przesuwamy większe elementy w prawo
        while (j >= 0 && arr.get(j).getRanking() > key.getRanking()) {
            arr.get(j + 1) = arr.get(j);
            j--;
        }

        // Wstawiamy element na właściwe miejsce
        arr.get(j + 1) = key;
    }
}

void BucketSort::sort(DynamicArray& arr) {
    // Jeśli tablica ma 0 lub 1 element, to jest już posortowana
    if (arr.getSize() <= 1) {
        return;
    }

    // Ustalamy stałą liczbę kubełków
    const int bucketCount = 20;

    // Wyznaczamy rzeczywisty zakres danych w aktualnym zbiorze
    double minRating = findMinRating(arr);
    double maxRating = findMaxRating(arr);

    // Tworzymy tablicę kubełków
    DynamicArray buckets[bucketCount];

    // Rozrzucamy elementy do kubełków na podstawie położenia w zakresie min-max
    for (int i = 0; i < arr.getSize(); i++) {
        double rating = arr.get(i).getRanking();
        int bucketIndex = getBucketIndex(rating, minRating, maxRating, bucketCount);
        buckets[bucketIndex].pushBack(arr.get(i));
    }

    // Sortujemy każdy kubełek osobno insertion sortem
    for (int i = 0; i < bucketCount; i++) {
        insertionSort(buckets[i]);
    }

    // Sklejamy wszystkie kubełki z powrotem do oryginalnej tablicy
    int index = 0;

    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < buckets[i].getSize(); j++) {
            arr.get(index) = buckets[i].get(j);
            index++;
        }
    }
}