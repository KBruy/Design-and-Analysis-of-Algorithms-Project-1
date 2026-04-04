#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>
#include "DynamicArray.h"

class CsvReader{
    public:
        DynamicArray loadMoviesFromFile(const std::string& fileName);
};

#endif