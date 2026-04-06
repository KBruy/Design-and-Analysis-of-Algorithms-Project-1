#include "../include/DynamicArray.h"

DynamicArray::DynamicArray() {
    capacity = 10;
    size = 0;
    data = new Movie[capacity];
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    size = other.size;
    capacity = other.capacity;
    data = new Movie[capacity];

    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    if (this != &other) {
        delete[] data;

        size = other.size;
        capacity = other.capacity;
        data = new Movie[capacity];

        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    return *this;
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

void DynamicArray::resize() {
    capacity = capacity * 2;
    Movie* newData = new Movie[capacity];

    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
}

void DynamicArray::pushBack(const Movie& movie) {
    if (size >= capacity) {
        resize();
    }

    data[size] = movie;
    size++;
}

Movie& DynamicArray::get(int index) {
    return data[index];
}

const Movie& DynamicArray::get(int index) const {
    return data[index];
}

int DynamicArray::getSize() const {
    return size;
}

bool DynamicArray::isEmpty() const {
    return size == 0;
}

void DynamicArray::clear() {
    size = 0;
}

DynamicArray DynamicArray::getFirstN(int n) const{
    DynamicArray result;

    if (n > size) {
        n = size;
    }

    for (int i = 0; i < n; i++) {
        result.pushBack(data[i]);
    }

    return result;
}