#include "phone_numbers.h"

PhoneNumbers::PhoneNumbers() { phoneNumbers = new PhoneNumber[cap]; }

PhoneNumbers::PhoneNumbers(const PhoneNumbers& other)
    : phoneNumbers(new PhoneNumber[other.cap]),
      size(other.size),
      cap(other.cap) {
    for (int i = 0; i < size; ++i) {
        phoneNumbers[i] = other.phoneNumbers[i];
    }
}

PhoneNumbers& PhoneNumbers::operator=(const PhoneNumbers& other) {
    if (this != &other) {
        delete[] phoneNumbers;
        cap = other.cap;
        size = other.size;
        phoneNumbers = new PhoneNumber[cap];
        for (int i = 0; i < size; ++i) {
            phoneNumbers[i] = other.phoneNumbers[i];
        }
    }
    return *this;
}

PhoneNumbers::PhoneNumbers(PhoneNumbers&& other) noexcept
    : phoneNumbers(other.phoneNumbers), size(other.size), cap(other.cap) {
    other.phoneNumbers = nullptr;
    other.size = 0;
    other.cap = 0;
}

PhoneNumbers& PhoneNumbers::operator=(PhoneNumbers&& other) noexcept {
    if (this != &other) {
        delete[] phoneNumbers;

        phoneNumbers = other.phoneNumbers;
        size = other.size;
        cap = other.cap;

        other.phoneNumbers = nullptr;
        other.size = 0;
        other.cap = 0;
    }
    return *this;
}

PhoneNumbers::~PhoneNumbers() { delete[] phoneNumbers; }

void PhoneNumbers::add(const PhoneNumber& number) {
    if (size >= cap) {
        cap *= 2;

        auto* newPhoneNumbers = new PhoneNumber[cap];

        for (int i = 0; i < size; ++i) {
            newPhoneNumbers[i] = phoneNumbers[i];
        }

        delete[] phoneNumbers;

        phoneNumbers = newPhoneNumbers;
    }

    phoneNumbers[size] = number;
    size++;
}

void PhoneNumbers::show() const {
    for (int i = 0; i < size; ++i) {
        std::cout << phoneNumbers[i] << " ";
    }
}

bool PhoneNumbers::isEmpty() const {
    return (phoneNumbers == nullptr && size == 0 && cap == 1);
}