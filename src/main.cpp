#include <iostream>
#include "../include/Movie.h"
#include "../include/DynamicArray.h"
#include "../include/CsvReader.h"

int main(){
   
    CsvReader reader;
    DynamicArray movies = reader.loadMoviesFromFile("data/projekt1_dane.csv");

    std::cout << "Liczba wczytanych filmow: " << movies.getSize() << std::endl;

    return 0;
}
