#include <iostream>
#include <chrono>
#include "../include/CsvReader.h"
#include "../include/DataFilter.h"

int main() {
    int choice;

    do {
        std::cout << std::endl;
        std::cout << "===== MENU =====" << std::endl;
        std::cout << "1. Przefiltruj dane" << std::endl;
        std::cout << "2. Merge sort" << std::endl;
        std::cout << "3. Quicksort" << std::endl;
        std::cout << "4. Introsort" << std::endl;
        std::cout << "0. Wyjscie" << std::endl;
        std::cout << "Wybor: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
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

                std::cout << std::endl;
                std::cout << "Liczba wszystkich filmow: " << movies.getSize() << std::endl;
                std::cout << "Liczba filmow bez rankingu: " << missingRatings << std::endl;
                std::cout << "Liczba filmow po filtrowaniu: " << filteredMovies.getSize() << std::endl;
                std::cout << "Czas przeszukiwania: " << searchDuration.count() << " ms" << std::endl;
                std::cout << "Czas filtrowania: " << filterDuration.count() << " ms" << std::endl;
                break;
            }
            case 2:
                std::cout << "Wybrano merge sort." << std::endl;
                break;
            case 3:
                std::cout << "Quicksort jeszcze niezaimplementowany." << std::endl;
                break;
            case 4:
                std::cout << "Introsort jeszcze niezaimplementowany." << std::endl;
                break;
            case 0:
                std::cout << "Koniec programu." << std::endl;
                break;
            default:
                std::cout << "Nieprawidlowy wybor." << std::endl;
        }

    } while (choice != 0);

    return 0;
}