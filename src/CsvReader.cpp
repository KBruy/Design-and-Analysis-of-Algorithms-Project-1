#include "../include/CsvReader.h"
#include <fstream>
#include <iostream>

DynamicArray CsvReader::loadMoviesFromFile(const std::string& fileName){
    DynamicArray movies;
    std::ifstream file(fileName);

    if (!file.is_open()){
        std::cout << "Nie udalo sie otworzyc pliku " << fileName << std::endl;
        return movies;

    }

    std::cout<<"Plik zostal otwarty poprawnie" << std::endl;

    file.close();
    return movies;
}