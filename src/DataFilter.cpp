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