#include"../include/DynamicArray.h"

DynamicArray::DynamicArray() {
    capacity = 10;
    size = 0;
    data = new Movie[capacity];
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    capacity = other.capacity;
    size = other.size;
    data = new Movie[capacity];

    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    if (this == &other) {
        return *this;
    }

    Movie* newData = new Movie[other.capacity];

    for (int i = 0; i < other.size; i++) {
        newData[i] = other.data[i];
    }

    delete[] data;
    data = newData;
    size = other.size;
    capacity = other.capacity;

    return *this;
}

DynamicArray::DynamicArray(DynamicArray&& other) noexcept {
    data = other.data;
    size = other.size;
    capacity = other.capacity;

    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

DynamicArray& DynamicArray::operator=(DynamicArray&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    delete[] data;

    data = other.data;
    size = other.size;
    capacity = other.capacity;

    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;

    return *this;
}

DynamicArray::~DynamicArray(){
    delete[] data;
}

void DynamicArray::resize() {
    capacity = capacity * 2;
    Movie* newData = new Movie[capacity];

    for (int i = 0; i < size; i++){
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
}

void DynamicArray::pushBack(const Movie& movie) {
    if (size >= capacity){
        resize();
    }

    data[size] = movie;
    size++;
}

Movie& DynamicArray::get(int index){
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

void DynamicArray::clear(){
    size = 0;
}
