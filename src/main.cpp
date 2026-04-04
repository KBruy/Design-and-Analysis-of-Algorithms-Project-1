#include <iostream>
#include "../include/Movie.h"
#include "../include/DynamicArray.h"

int main() {
    DynamicArray movies;
    movies.pushBack(Movie("Film 1", 8.0, true));
    movies.pushBack(Movie("Film 2", 7.5, true));
    movies.pushBack(Movie("Film 3", 9.1, true));
    movies.pushBack(Movie("Film 4", 6.8, true));

    DynamicArray smallSet = movies.getFirstN(2);

    std::cout << "Pelna tablica:" << std::endl;
    for (int i = 0; i < movies.getSize(); i++) {
        std::cout << movies.get(i).getTitle() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Pierwsze 2 elementy:" << std::endl;
    for (int i = 0; i < smallSet.getSize(); i++) {
        std::cout << smallSet.get(i).getTitle() << std::endl;
    }

    return 0;
}