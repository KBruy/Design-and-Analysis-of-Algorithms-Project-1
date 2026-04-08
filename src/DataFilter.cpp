#include "../include/DataFilter.h"

DynamicArray DataFilter::filterMoviesWithRating(const DynamicArray& movies) {
    DynamicArray filteredMovies;

    for (int i = 0; i < movies.getSize(); i++) {
        if (movies.get(i).getHasRating()) {
            filteredMovies.pushBack(movies.get(i));
        }
    }

    return filteredMovies;
}

int DataFilter::countMoviesWithoutRating(const DynamicArray& movies) {
    int count = 0;

    for (int i = 0; i < movies.getSize(); i++) {
        if (!movies.get(i).getHasRating()) {
            count++;
        }
    }

    return count;
}

DynamicArray DataFilter::prepareDataSet(const DynamicArray& movies, int size) {
    return movies.getFirstN(size);
}

bool DataFilter::isSortedByRating(const DynamicArray& movies) {
    for (int i = 0; i < movies.getSize() - 1; i++) {
        if (movies.get(i).getRanking() > movies.get(i+1).getRanking()){
            return false;
        }
    }
    return true;
}

double DataFilter::calculateAverageRating(const DynamicArray& movies) {
    if (movies.getSize() == 0){
        return 0.0;
    }

    double sum = 0.0;

    for (int i = 0; i < movies.getSize(); i++) {
        sum += movies.get(i).getRanking();
    }

    //Średnia = suma / liczba elementów
    
    return sum / movies.getSize();
}

double DataFilter::calculateMedianRating(const DynamicArray& movies) {
    if (movies.getSize() == 0){
        return 0.0;
    }

    int size = movies.getSize();
    int middleIndex = size / 2;

    // tablica przekazana do tej funkcji jest już posortowana

    if (size % 2 == 1) {
        return movies.get(middleIndex).getRanking();
    }

    return (movies.get(middleIndex - 1).getRanking() + movies.get(middleIndex).getRanking()) / 2.0;
}