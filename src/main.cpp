#include <iostream>
#include <iomanip>
#include <chrono>
#include "../include/CsvReader.h"
#include "../include/DataFilter.h"
#include "../include/MergeSort.h"
#include "../include/QuickSort.h"
#include "../include/BucketSort.h"

int main() {
    int choice;
    std::cout << std::fixed << std::setprecision(1);

    do {
        std::cout << std::endl;
        std::cout << "===== MENU =====" << std::endl;
        std::cout << "1. Przefiltruj dane" << std::endl;
        std::cout << "2. Merge sort" << std::endl;
        std::cout << "3. Quicksort" << std::endl;
        std::cout << "4. Bucket sort" << std::endl;
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

                double searchDuration = std::chrono::duration<double, std::milli>(searchEnd - searchStart).count();
                double filterDuration = std::chrono::duration<double, std::milli>(filterEnd - filterStart).count();

                std::cout << std::endl;
                std::cout << "Liczba wszystkich filmow: " << movies.getSize() << std::endl;
                std::cout << "Liczba filmow bez rankingu: " << missingRatings << std::endl;
                std::cout << "Liczba filmow po filtrowaniu: " << filteredMovies.getSize() << std::endl;
                std::cout << "Czas przeszukiwania: " << searchDuration << " ms" << std::endl;
                std::cout << "Czas filtrowania: " << filterDuration << " ms" << std::endl;
                break;
            }

            case 2: {
                CsvReader reader;
                DataFilter filter;
                MergeSort sorter;

                int sizeChoice;
                int dataSize = 0;
                bool visualTest = false;
                bool validChoice = true;

                std::cout << std::endl;
                std::cout << "===== MERGE SORT =====" << std::endl;
                std::cout << "1. 50 (test wizualny)" << std::endl;
                std::cout << "2. 10000" << std::endl;
                std::cout << "3. 50000" << std::endl;
                std::cout << "4. 100000" << std::endl;
                std::cout << "5. 250000" << std::endl;
                std::cout << "6. 500000" << std::endl;
                std::cout << "7. 1000000" << std::endl;
                std::cout << "8. max" << std::endl;
                std::cout << "Wybor: ";
                std::cin >> sizeChoice;

                DynamicArray movies = reader.loadMoviesFromFile("data/projekt1_dane.csv");
                DynamicArray filteredMovies = filter.filterMoviesWithRating(movies);

                switch (sizeChoice) {
                    case 1:
                        dataSize = 50;
                        visualTest = true;
                        break;
                    case 2:
                        dataSize = 10000;
                        break;
                    case 3:
                        dataSize = 50000;
                        break;
                    case 4:
                        dataSize = 100000;
                        break;
                    case 5:
                        dataSize = 250000;
                        break;
                    case 6:
                        dataSize = 500000;
                        break;
                    case 7:
                        dataSize = 1000000;
                        break;
                    case 8:
                        dataSize = filteredMovies.getSize();
                        break;
                    default:
                        validChoice = false;
                        std::cout << "Nieprawidlowy wybor." << std::endl;
                        break;
                }

                if (!validChoice) {
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

                    double sortDuration = std::chrono::duration<double, std::milli>(sortEnd - sortStart).count();

                    double averageRating = filter.calculateAverageRating(dataSet);
                    double medianRating = filter.calculateMedianRating(dataSet);

                    std::cout << std::endl;
                    std::cout << "Rzeczywisty rozmiar zbioru: " << dataSet.getSize() << std::endl;
                    std::cout << "Czas sortowania merge sort: " << sortDuration << " ms" << std::endl;
                    std::cout << "Srednia rankingu: " << averageRating << std::endl;
                    std::cout << "Mediana rankingu: " << medianRating << std::endl;
                    std::cout << "Weryfikacja poprawnosci sortowania:" << std::endl;

                    if (filter.isSortedByRating(dataSet)) {
                        std::cout << "Tablica jest posortowana poprawnie." << std::endl;
                    } else {
                        std::cout << "Tablica NIE jest posortowana poprawnie." << std::endl;
                    }
                }

                break;
            }

            case 3: {
                CsvReader reader;
                DataFilter filter;
                QuickSort sorter;

                int sizeChoice;
                int dataSize = 0;
                bool visualTest = false;
                bool validChoice = true;

                std::cout << std::endl;
                std::cout << "===== QUICKSORT =====" << std::endl;
                std::cout << "1. 50 (test wizualny)" << std::endl;
                std::cout << "2. 10000" << std::endl;
                std::cout << "3. 50000" << std::endl;
                std::cout << "4. 100000" << std::endl;
                std::cout << "5. 250000" << std::endl;
                std::cout << "6. 500000" << std::endl;
                std::cout << "7. 1000000" << std::endl;
                std::cout << "8. max" << std::endl;
                std::cout << "Wybor: ";
                std::cin >> sizeChoice;

                DynamicArray movies = reader.loadMoviesFromFile("data/projekt1_dane.csv");
                DynamicArray filteredMovies = filter.filterMoviesWithRating(movies);

                switch (sizeChoice) {
                    case 1:
                        dataSize = 50;
                        visualTest = true;
                        break;
                    case 2:
                        dataSize = 10000;
                        break;
                    case 3:
                        dataSize = 50000;
                        break;
                    case 4:
                        dataSize = 100000;
                        break;
                    case 5:
                        dataSize = 250000;
                        break;
                    case 6:
                        dataSize = 500000;
                        break;
                    case 7:
                        dataSize = 1000000;
                        break;
                    case 8:
                        dataSize = filteredMovies.getSize();
                        break;
                    default:
                        validChoice = false;
                        std::cout << "Nieprawidlowy wybor." << std::endl;
                        break;
                }

                if (!validChoice) {
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

                    double sortDuration = std::chrono::duration<double, std::milli>(sortEnd - sortStart).count();

                    double averageRating = filter.calculateAverageRating(dataSet);
                    double medianRating = filter.calculateMedianRating(dataSet);

                    std::cout << std::endl;
                    std::cout << "Rzeczywisty rozmiar zbioru: " << dataSet.getSize() << std::endl;
                    std::cout << "Czas sortowania quicksort: " << sortDuration << " ms" << std::endl;
                    std::cout << "Srednia rankingu: " << averageRating << std::endl;
                    std::cout << "Mediana rankingu: " << medianRating << std::endl;
                    std::cout << "Weryfikacja poprawnosci sortowania:" << std::endl;

                    if (filter.isSortedByRating(dataSet)) {
                        std::cout << "Tablica jest posortowana poprawnie." << std::endl;
                    } else {
                        std::cout << "Tablica NIE jest posortowana poprawnie." << std::endl;
                    }
                }

                break;
            }

            case 4: {
                CsvReader reader;
                DataFilter filter;
                BucketSort sorter;

                int sizeChoice;
                int dataSize = 0;
                bool visualTest = false;
                bool validChoice = true;

                std::cout << std::endl;
                std::cout << "===== BUCKET SORT =====" << std::endl;
                std::cout << "1. 50 (test wizualny)" << std::endl;
                std::cout << "2. 10000" << std::endl;
                std::cout << "3. 50000" << std::endl;
                std::cout << "4. 100000" << std::endl;
                std::cout << "5. 250000" << std::endl;
                std::cout << "6. 500000" << std::endl;
                std::cout << "7. 1000000" << std::endl;
                std::cout << "8. max" << std::endl;
                std::cout << "Wybor: ";
                std::cin >> sizeChoice;

                DynamicArray movies = reader.loadMoviesFromFile("data/projekt1_dane.csv");
                DynamicArray filteredMovies = filter.filterMoviesWithRating(movies);

                switch (sizeChoice) {
                    case 1:
                        dataSize = 50;
                        visualTest = true;
                        break;
                    case 2:
                        dataSize = 10000;
                        break;
                    case 3:
                        dataSize = 50000;
                        break;
                    case 4:
                        dataSize = 100000;
                        break;
                    case 5:
                        dataSize = 250000;
                        break;
                    case 6:
                        dataSize = 500000;
                        break;
                    case 7:
                        dataSize = 1000000;
                        break;
                    case 8:
                        dataSize = filteredMovies.getSize();
                        break;
                    default:
                        validChoice = false;
                        std::cout << "Nieprawidlowy wybor." << std::endl;
                        break;
                }

                if (!validChoice) {
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

                    double sortDuration = std::chrono::duration<double, std::milli>(sortEnd - sortStart).count();

                    double averageRating = filter.calculateAverageRating(dataSet);
                    double medianRating = filter.calculateMedianRating(dataSet);

                    std::cout << std::endl;
                    std::cout << "Rzeczywisty rozmiar zbioru: " << dataSet.getSize() << std::endl;
                    std::cout << "Czas sortowania bucket sort: " << sortDuration << " ms" << std::endl;
                    std::cout << "Srednia rankingu: " << averageRating << std::endl;
                    std::cout << "Mediana rankingu: " << medianRating << std::endl;
                    std::cout << "Weryfikacja poprawnosci sortowania:" << std::endl;

                    if (filter.isSortedByRating(dataSet)) {
                        std::cout << "Tablica jest posortowana poprawnie." << std::endl;
                    } else {
                        std::cout << "Tablica NIE jest posortowana poprawnie." << std::endl;
                    }
                }

                break;
            }

            case 0:
                std::cout << "Koniec programu." << std::endl;
                break;

            default:
                std::cout << "Nieprawidlowy wybor." << std::endl;
        }

    } while (choice != 0);

    return 0;
}
