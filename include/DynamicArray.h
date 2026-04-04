#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include "Movie.h"

class DynamicArray {

private:
    Movie* data;
    int size;
    int capacity;

    void resize();

public: 
    DynamicArray();
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);
    DynamicArray(DynamicArray&& other) noexcept;
    DynamicArray& operator=(DynamicArray&& other) noexcept;
    ~DynamicArray();

    void pushBack(const Movie& movie);
    
    Movie& get(int index);
    const Movie& get(int index) const;

    int getSize() const;
    bool isEmpty() const;

    void clear();
    
};

#endif
