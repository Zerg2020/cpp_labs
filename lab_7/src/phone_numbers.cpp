#include "phone_numbers.h"

PhoneNumbers::PhoneNumbers()
{
    phone_numbers = new PhoneNumber[cap];
}

PhoneNumbers::PhoneNumbers(const PhoneNumbers &other) :
    phone_numbers(new PhoneNumber[other.cap]), size(other.size), cap(other.cap)
{
    for (int i = 0; i < size; ++i)
    {
        phone_numbers[i] = other.phone_numbers[i];
    }
}

PhoneNumbers &PhoneNumbers::operator=(const PhoneNumbers &other)
{
    if (this != &other)
    {
        delete[] phone_numbers;
        cap = other.cap;
        size = other.size;
        phone_numbers = new PhoneNumber[cap];
        for (int i = 0; i < size; ++i)
        {
            phone_numbers[i] = other.phone_numbers[i];
        }
    }
    return *this;
}

PhoneNumbers::PhoneNumbers(PhoneNumbers &&other) noexcept :
    phone_numbers(other.phone_numbers), size(other.size), cap(other.cap)
{
    other.phone_numbers = nullptr;
    other.size = 0;
    other.cap = 0;
}

PhoneNumbers &PhoneNumbers::operator=(PhoneNumbers &&other) noexcept
{
    if (this != &other)
    {
        delete[] phone_numbers;

        phone_numbers = other.phone_numbers;
        size = other.size;
        cap = other.cap;

        other.phone_numbers = nullptr;
        other.size = 0;
        other.cap = 0;
    }
    return *this;
}

PhoneNumbers::~PhoneNumbers()
{
    delete[] phone_numbers;
}

void PhoneNumbers::add(const PhoneNumber &number)
{
    if (size >= cap)
    {
        cap *= 2;

        auto *new_phone_numbers = new PhoneNumber[cap];

        for (int i = 0; i < size; ++i)
        {
            new_phone_numbers[i] = phone_numbers[i];
        }

        delete[] phone_numbers;

        phone_numbers = new_phone_numbers;
    }

    phone_numbers[size] = number;
    size++;
}

void PhoneNumbers::show() const
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << phone_numbers[i] << " ";
    }
}

bool PhoneNumbers::is_empty() const
{
    return (phone_numbers == nullptr && size == 0 && cap == 1);
}