#include "../include/CsvReader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

Movie CsvReader::parseLine(const std::string& line) {
    size_t firstComma = line.find(',');
    size_t lastComma = line.rfind(',');

    std::string title = "";
    std::string ratingText = "";

    if (firstComma != std::string::npos && lastComma != std::string::npos && firstComma != lastComma) {
        title = line.substr(firstComma + 1, lastComma - firstComma - 1);
        ratingText = line.substr(lastComma + 1);
    }

    if (!title.empty() && title[0] == '"') {
        title = title.substr(1);
    }

    if (!title.empty() && title[title.length() - 1] == '"') {
        title = title.substr(0, title.length() - 1);
    }

    if (ratingText.empty()) {
        return Movie(title, 0.0, false);
    }

    double rating = std::stod(ratingText);
    return Movie(title, rating, true);
}

DynamicArray CsvReader::loadMoviesFromFile(const std::string& fileName) {
    DynamicArray movies;
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cout << "Nie udalo sie otworzyc pliku: " << fileName << std::endl;
        return movies;
    }

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line)) {
        Movie movie = parseLine(line);
        movies.pushBack(movie);
    }

    file.close();
    return movies;
}