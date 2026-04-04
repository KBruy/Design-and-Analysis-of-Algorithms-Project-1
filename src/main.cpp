#include <iostream>
#include <iomanip>
#include <chrono>
#include "../include/CsvReader.h"
#include "../include/DataFilter.h"

int main() {
    CsvReader reader;
    DataFilter filter;

    DynamicArray movies = reader.loadMoviesFromFile("data/projekt1_dane.csv");

    auto searchStart = std::chrono::high_resolution_clock::now();
    int missingRatings = filter.countMoviesWithoutRating(movies);
    auto searchEnd = std::chrono::high_resolution_clock::now();

    auto filterStart = std::chrono::high_resolution_clock::now();
    DynamicArray filteredMovies = filter.filterMoviesWithRating(movies);
    auto filterEnd = std::chrono::high_resolution_clock::now();

    auto searchDuration = std::chrono::duration_cast<std::chrono::milliseconds>(searchEnd - searchStart);
    auto filterDuration = std::chrono::duration_cast<std::chrono::milliseconds>(filterEnd - filterStart);

    std::cout << "Liczba wszystkich filmow: " << movies.getSize() << std::endl;
    std::cout << "Liczba filmow bez rankingu: " << missingRatings << std::endl;
    std::cout << "Liczba filmow po filtrowaniu: " << filteredMovies.getSize() << std::endl;
    std::cout << "Czas przeszukiwania: " << searchDuration.count() << " ms" << std::endl;
    std::cout << "Czas filtrowania: " << filterDuration.count() << " ms" << std::endl;
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(1);

    int limit = 5;
    if (filteredMovies.getSize() < limit) {
        limit = filteredMovies.getSize();
    }

    for (int i = 0; i < limit; i++) {
        std::cout << "Tytul: " << filteredMovies.get(i).getTitle() << std::endl;
        std::cout << "Ranking: " << filteredMovies.get(i).getRanking() << std::endl;
        std::cout << std::endl;
    }

    return 0;
}