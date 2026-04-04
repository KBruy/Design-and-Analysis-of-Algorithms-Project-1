#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>
#include "DynamicArray.h"

class CsvReader{
    private:
        Movie parseLine(const std::string& line);

    public:
        DynamicArray loadMoviesFromFile(const std::string& fileName);
};

#endif