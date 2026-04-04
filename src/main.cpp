#include <iostream>
#include "../include/Movie.h"
#include "../include/DynamicArray.h"

int main(){
    DynamicArray movies;

    movies.pushBack(Movie("Inception", 8.8));
    movies.pushBack(Movie("b", 10.0));
    movies.pushBack(Movie("c", 2.9));

    for (int i = 0; i < movies.getSize(); i++){
        std::cout << "Tytul: "<< movies.get(i).getTitle() << std::endl;
        std::cout << "Ranking:" << movies.get(i).getRanking() << std::endl;
        std::cout << std::endl;
    }

    return 0;
}