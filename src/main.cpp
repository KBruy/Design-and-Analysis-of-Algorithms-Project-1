#include <iostream>
#include "../include/Movie.h"
#include "../include/DynamicArray.h"

int main() {
    DynamicArray movies;
    movies.pushBack(Movie("Film 1", 8.0, true));
    movies.pushBack(Movie("Film 2", 7.5, true));

    DynamicArray copy = movies;

    movies.get(0).setTitle("Zmieniony film");

    std::cout << "Oryginal:" << std::endl;
    std::cout << movies.get(0).getTitle() << std::endl;

    std::cout << "Kopia:" << std::endl;
    std::cout << copy.get(0).getTitle() << std::endl;

    return 0;
}