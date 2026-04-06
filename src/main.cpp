#include <iostream>
#include <iomanip>
#include "../include/CsvReader.h"
#include "../include/DataFilter.h"
#include "../include/MergeSort.h"

int main() {
    CsvReader reader;
    DataFilter filter;
    MergeSort sorter;

    DynamicArray movies = reader.loadMoviesFromFile("data/projekt1_dane.csv");
    DynamicArray filteredMovies = filter.filterMoviesWithRating(movies);
    DynamicArray dataSet = filter.prepareDataSet(filteredMovies, 10000);

    std::cout << "Przed sortowaniem:" << std::endl;
    std::cout << std::fixed << std::setprecision(1);

    for (int i = 0; i < 10 && i < dataSet.getSize(); i++) {
        std::cout << dataSet.get(i).getTitle() << " - " << dataSet.get(i).getRanking() << std::endl;
    }

    sorter.sort(dataSet);

    std::cout << std::endl;
    std::cout << "Po sortowaniu:" << std::endl;

    for (int i = 0; i < 10 && i < dataSet.getSize(); i++) {
        std::cout << dataSet.get(i).getTitle() << " - " << dataSet.get(i).getRanking() << std::endl;
    }

    std::cout << std::endl;
    if (filter.isSortedByRating(dataSet)) {
        std::cout << "Tablica jest posortowana poprawnie." << std::endl;
    } else {
        std::cout << "Tablica NIE jest posortowana poprawnie." << std::endl;
    }

    return 0;
}