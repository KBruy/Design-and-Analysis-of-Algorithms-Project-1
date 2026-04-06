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
    DynamicArray(const DynamicArray& other); //konstruktor kopiujący do tworzenia nowych obiektów jako kopii starego
    DynamicArray& operator=(const DynamicArray& other); //operator przypisania kiedy jeden obiekt ma dostać zawartość drugiego
    ~DynamicArray();

    void pushBack(const Movie& movie);
    
    Movie& get(int index);
    const Movie& get(int index) const;

    int getSize() const;
    bool isEmpty() const;

    void clear();

    DynamicArray getFirstN(int n) const; //zwraca nową tabilcę z pierwszych n elementów
    
};

#endif
