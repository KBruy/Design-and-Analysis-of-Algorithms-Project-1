#include <iostream>
#include <iomanip>
#include "../include/Movie.h"
#include "../include/DynamicArray.h"
#include "../include/MergeSort.h"

int main() {
    DynamicArray movies;

    movies.pushBack(Movie("Film A", 8.7, true));
    movies.pushBack(Movie("Film B", 6.2, true));
    movies.pushBack(Movie("Film C", 9.1, true));
    movies.pushBack(Movie("Film D", 7.5, true));
    movies.pushBack(Movie("Film E", 8.0, true));

    std::cout << "Przed sortowaniem:" << std::endl;
    std::cout << std::fixed << std::setprecision(1);

    for (int i = 0; i < movies.getSize(); i++) {
        std::cout << movies.get(i).getTitle() << " - " << movies.get(i).getRanking() << std::endl;
    }

    MergeSort sorter;
    sorter.sort(movies);

    std::cout << std::endl;
    std::cout << "Po sortowaniu:" << std::endl;

    for (int i = 0; i < movies.getSize(); i++) {
        std::cout << movies.get(i).getTitle() << " - " << movies.get(i).getRanking() << std::endl;
    }

    return 0;
}