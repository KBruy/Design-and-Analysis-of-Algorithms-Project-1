#include <iostream>
#include "../include/CsvReader.h"
#include "../include/DataFilter.h"

int main() {
    CsvReader reader;
    DataFilter filter;

    DynamicArray movies = reader.loadMoviesFromFile("data/projekt1_dane.csv");
    DynamicArray filteredMovies = filter.filterMoviesWithRating(movies);

    DynamicArray data10000 = filter.prepareDataSet(filteredMovies, 10000);
    DynamicArray data100000 = filter.prepareDataSet(filteredMovies, 100000);

    std::cout << "Liczba filmow po filtrowaniu: " << filteredMovies.getSize() << std::endl;
    std::cout << "Rozmiar zbioru 10000: " << data10000.getSize() << std::endl;
    std::cout << "Rozmiar zbioru 100000: " << data100000.getSize() << std::endl;

    return 0;
}