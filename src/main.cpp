#include <iostream>
#include <chrono>
#include <iomanip>
#include "../include/CsvReader.h"
#include "../include/DataFilter.h"
#include "../include/MergeSort.h"
#include "../include/QuickSort.h"

int main() {
    int choice;
    std::cout << std::fixed << std::setprecision(1);
    
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
            case 1: { //przeszukiwanie i filtrowanie danych
                CsvReader reader;
                DataFilter filter;

                DynamicArray movies = reader.loadMoviesFromFile("data/projekt1_dane.csv");

                auto searchStart = std::chrono::high_resolution_clock::now();
                int missingRatings = filter.countMoviesWithoutRating(movies);
                auto searchEnd = std::chrono::high_resolution_clock::now();

                auto filterStart = std::chrono::high_resolution_clock::now();
                DynamicArray filteredMovies = filter.filterMoviesWithRating(movies);
                auto filterEnd = std::chrono::high_resolution_clock::now();

                auto searchDuration = std::chrono::duration_cast<std::chrono::microseconds>(searchEnd - searchStart);
                auto filterDuration = std::chrono::duration_cast<std::chrono::microseconds>(filterEnd - filterStart);

                std::cout << std::endl;
                std::cout << "Liczba wszystkich filmow: " << movies.getSize() << std::endl;
                std::cout << "Liczba filmow bez rankingu: " << missingRatings << std::endl;
                std::cout << "Liczba filmow po filtrowaniu: " << filteredMovies.getSize() << std::endl;
                std::cout << "Czas przeszukiwania: " << searchDuration.count() << " us" << std::endl;
                std::cout << "Czas filtrowania: " << filterDuration.count() << " us" << std::endl;
                break;
            }
// ===============================================================
// MERGE SORT
            case 2: { 
                CsvReader reader;
                DataFilter filter;
                MergeSort sorter;

                int sizeChoice;
                int dataSize = 0;
                bool visualTest = false;

                std::cout << std::endl;
                std::cout << "===== MERGE SORT =====" << std::endl;
                std::cout << "1. 50 (test wizualny)" << std::endl;
                std::cout << "2. 10000" << std::endl;
                std::cout << "3. 100000" << std::endl;
                std::cout << "4. 500000" << std::endl;
                std::cout << "5. 1000000" << std::endl;
                std::cout << "6. max" << std::endl;
                std::cout << "Wybor: ";
                std::cin >> sizeChoice;

                DynamicArray movies = reader.loadMoviesFromFile("data/projekt1_dane.csv");
                DynamicArray filteredMovies = filter.filterMoviesWithRating(movies);

                if (sizeChoice == 1) {
                    dataSize = 50;
                    visualTest = true;
                } else if (sizeChoice == 2) {
                    dataSize = 10000;
                } else if (sizeChoice == 3) {
                    dataSize = 100000;
                } else if (sizeChoice == 4) {
                    dataSize = 500000;
                } else if (sizeChoice == 5) {
                    dataSize = 1000000;
                } else if (sizeChoice == 6) {
                    dataSize = filteredMovies.getSize();
                } else {
                    std::cout << "Nieprawidlowy wybor." << std::endl;
                    break;
                }

                DynamicArray dataSet = filter.prepareDataSet(filteredMovies, dataSize);

                if (visualTest) {
                    std::cout << std::endl;
                    std::cout << "Przed sortowaniem:" << std::endl;

                    for (int i = 0; i < dataSet.getSize(); i++) {
                        std::cout << dataSet.get(i).getTitle() << " - " << dataSet.get(i).getRanking() << std::endl;
                    }

                    sorter.sort(dataSet);

                    std::cout << std::endl;
                    std::cout << "Po sortowaniu:" << std::endl;

                    for (int i = 0; i < dataSet.getSize(); i++) {
                        std::cout << dataSet.get(i).getTitle() << " - " << dataSet.get(i).getRanking() << std::endl;
                    }

                    std::cout << std::endl;
                    std::cout << "Weryfikacja poprawnosci sortowania:" << std::endl;

                    if (filter.isSortedByRating(dataSet)) {
                        std::cout << "Tablica jest posortowana poprawnie." << std::endl;
                    } else {
                        std::cout << "Tablica NIE jest posortowana poprawnie." << std::endl;
                    }
                } else {
                    auto sortStart = std::chrono::high_resolution_clock::now();
                    sorter.sort(dataSet);
                    auto sortEnd = std::chrono::high_resolution_clock::now();

                    auto sortDuration = std::chrono::duration_cast<std::chrono::microseconds>(sortEnd - sortStart);

                    std::cout << std::endl;
                    std::cout << "Rzeczywisty rozmiar zbioru: " << dataSet.getSize() << std::endl;
                    std::cout << "Czas sortowania merge sort: " << sortDuration.count() << " us" << std::endl;
                    std::cout << "Weryfikacja poprawnosci sortowania:" << std::endl;

                    if (filter.isSortedByRating(dataSet)) {
                        std::cout << "Tablica jest posortowana poprawnie." << std::endl;
                    } else {
                        std::cout << "Tablica NIE jest posortowana poprawnie." << std::endl;
                    }
                }

                break;
            }

//======================================================================================================
// QUICKSORT

                case 3: {
                    CsvReader reader;
                    DataFilter filter;
                    QuickSort sorter;

                    int sizeChoice;
                    int dataSize = 0;
                    bool visualTest = false;

                    std::cout << std::endl;
                    std::cout << "===== QUICKSORT =====" << std::endl;
                    std::cout << "1. 50 (test wizualny)" << std::endl;
                    std::cout << "2. 10000" << std::endl;
                    std::cout << "3. 100000" << std::endl;
                    std::cout << "4. 500000" << std::endl;
                    std::cout << "5. 1000000" << std::endl;
                    std::cout << "6. max" << std::endl;
                    std::cout << "Wybor: ";
                    std::cin >> sizeChoice;

                    DynamicArray movies = reader.loadMoviesFromFile("data/projekt1_dane.csv");
                    DynamicArray filteredMovies = filter.filterMoviesWithRating(movies);

                    if (sizeChoice == 1) {
                        dataSize = 50;
                        visualTest = true;
                    } else if (sizeChoice == 2) {
                        dataSize = 10000;
                    } else if (sizeChoice == 3) {
                        dataSize = 100000;
                    } else if (sizeChoice == 4) {
                        dataSize = 500000;
                    } else if (sizeChoice == 5) {
                        dataSize = 1000000;
                    } else if (sizeChoice == 6) {
                        dataSize = filteredMovies.getSize();
                    } else {
                        std::cout << "Nieprawidlowy wybor." << std::endl;
                        break;
                    }

                    DynamicArray dataSet = filter.prepareDataSet(filteredMovies, dataSize);

                    if (visualTest) {
                        std::cout << std::endl;
                        std::cout << "Przed sortowaniem:" << std::endl;

                        for (int i = 0; i < dataSet.getSize(); i++) {
                            std::cout << dataSet.get(i).getTitle() << " - " << dataSet.get(i).getRanking() << std::endl;
                        }

                        sorter.sort(dataSet);

                        std::cout << std::endl;
                        std::cout << "Po sortowaniu:" << std::endl;

                        for (int i = 0; i < dataSet.getSize(); i++) {
                            std::cout << dataSet.get(i).getTitle() << " - " << dataSet.get(i).getRanking() << std::endl;
                        }

                        std::cout << std::endl;
                        std::cout << "Weryfikacja poprawnosci sortowania:" << std::endl;

                        if (filter.isSortedByRating(dataSet)) {
                            std::cout << "Tablica jest posortowana poprawnie." << std::endl;
                        } else {
                            std::cout << "Tablica NIE jest posortowana poprawnie." << std::endl;
                        }
                    } else {
                        auto sortStart = std::chrono::high_resolution_clock::now();
                        sorter.sort(dataSet);
                        auto sortEnd = std::chrono::high_resolution_clock::now();

                        auto sortDuration = std::chrono::duration_cast<std::chrono::microseconds>(sortEnd - sortStart);

                        std::cout << std::endl;
                        std::cout << "Rzeczywisty rozmiar zbioru: " << dataSet.getSize() << std::endl;
                        std::cout << "Czas sortowania quicksort: " << sortDuration.count() << " us" << std::endl;
                        std::cout << "Weryfikacja poprawnosci sortowania:" << std::endl;

                        if (filter.isSortedByRating(dataSet)) {
                            std::cout << "Tablica jest posortowana poprawnie." << std::endl;
                        } else {
                            std::cout << "Tablica NIE jest posortowana poprawnie." << std::endl;
                        }
                    }

                    break;
                }

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