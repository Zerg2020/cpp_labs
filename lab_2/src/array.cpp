#include "array.h"

#include "consts.h"
#include "utils.h"

Array::Array() : data(nullptr), size(0) {}

Array::Array(int arr_size) : size(arr_size) {
    data = new int[size];

    std ::cout << "Please enter array elements.\n";

    for (int i = 0; i < size; i++) {
        std ::cout << "Element " << i + 1 << ">> ";
        data[i] = get_number("", MIN_INT, MAX_INT);
    }
}

Array::~Array() {
    delete[] data;
    data = nullptr;
    size = 0;
}

Array::Array(const Array &other) : data(nullptr), size(other.size) {
    if (size > 0) {
        data = new int[size];

        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
}

Array::Array(Array &&move) noexcept : data(move.data), size(move.size) {
    move.data = nullptr;
    move.size = 0;
}

Array &Array::operator=(const Array &other) {
    if (this != &other) {
        size = other.size;

        delete[] data;
        data = nullptr;

        if (size > 0) {
            data = new int[size];

            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
    }

    return *this;
}

Array &Array::operator=(Array &&move) noexcept {
    if (this != &move) {
        size = move.size; 

        delete[] data;
        data = move.data;

        move.data = nullptr;
        move.size = 0;
    }

    return *this;
}

Array &Array::operator++() {
    for (int i = 0; i < size; i++) {
        data[i]++;
    }

    return *this;
}

Array Array::operator++(int value) {
    Array tmp = *this;

    for (int i = 0; i < size; i++) {
        data[i]++;
    }

    return tmp;
}

bool Array::is_empty() const 
{
     return (data == nullptr && size == 0); 
}

//void Array::input(const std::string &msg) 
void input(Array &arr, const std::string &msg) 
{
    arr.size = get_number("Please enter array size: ", 1, MAX_INT);

    std::cout << msg;

    arr.data = new int[arr.size];

    for (int i = 0; i < arr.size; i++) {
        std ::cout << "Element " << i + 1 << ">> ";
        arr.data[i] = get_number("", MIN_INT, MAX_INT);
    }
}

void show(Array arr, const std::string &msg) {
    std::cout << msg;

    for (int i = 0; i < arr.size; i++) {
        std::cout << arr.data[i] << " ";
    }

    std::cout << std::endl;
}