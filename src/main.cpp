#include <iostream>
#include <iomanip>
#include "../include/CsvReader.h"

int main() {
    CsvReader reader;
    DynamicArray movies = reader.loadMoviesFromFile("data/projekt1_dane.csv");

    std::cout << "Liczba wczytanych filmow: " << movies.getSize() << std::endl;
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(1);

    int limit = 5;
    if (movies.getSize() < limit) {
        limit = movies.getSize();
    }

    for (int i = 0; i < limit; i++) {
        std::cout << "Tytul: " << movies.get(i).getTitle() << std::endl;
        std::cout << "Ranking: " << movies.get(i).getRanking() << std::endl;
        std::cout << std::endl;
    }

    return 0;
}