#include <iostream>
#include <iomanip>
#include "../include/CsvReader.h"

int main() {
    CsvReader reader;
    DynamicArray movies = reader.loadMoviesFromFile("data/projekt1_dane.csv");

    int missingRatings = 0;

    for (int i = 0; i < movies.getSize(); i++) {
        if (!movies.get(i).getHasRating()) {
            missingRatings++;
        }
    }

    std::cout << "Liczba wczytanych filmow: " << movies.getSize() << std::endl;
    std::cout << "Liczba filmow bez rankingu: " << missingRatings << std::endl;
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(1);

    int shown = 0;
    for (int i = 0; i < movies.getSize() && shown < 5; i++) {
        if (movies.get(i).getHasRating()) {
            std::cout << "Tytul: " << movies.get(i).getTitle() << std::endl;
            std::cout << "Ranking: " << movies.get(i).getRanking() << std::endl;
            std::cout << std::endl;
            shown++;
        }
    }

    return 0;
}