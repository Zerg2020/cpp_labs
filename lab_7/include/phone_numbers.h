#pragma once

#include "phone_number.h"

class PhoneNumbers {
    PhoneNumber* phoneNumbers = nullptr;
    int size = 0;
    int cap = 1;

   public:
    PhoneNumbers();

    PhoneNumbers(const PhoneNumbers& other);
    PhoneNumbers& operator=(const PhoneNumbers& other);

    PhoneNumbers(PhoneNumbers&& other) noexcept;
    PhoneNumbers& operator=(PhoneNumbers&& other) noexcept;

    ~PhoneNumbers();

    void add(const PhoneNumber& number);
    void show() const;
    bool isEmpty() const;
};
