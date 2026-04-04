#include <iostream>
#include "../include/Movie.h"

int main(){
    Movie movie("Inception", 8.8);

    std::cout << "Tytul: "<< movie.getTitle() << std::endl;
    std::cout << "Ranking: " << movie.getRanking() << std::endl;

    return 0;
}