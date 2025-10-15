#include "string.h"
#include "functions.h"

String::String() : data(nullptr), length(0), capacity(0) {}

String::String(const char *input_str)
    : length(find_length(input_str)), capacity(length + 1) {
  data = new char[capacity];
  for (int index = 0; index < find_length(input_str); index++) {
    data[index] = input_str[index];
  }
  data[capacity - 1] = '\0';
}

void String::show()const {
  if (data == nullptr)
    return;
  for (int i = 0; data[i] != '\n' && data[i] != '\0'; i++)
    std::cout << data[i];
  std::cout << std::endl;
}

void String::fill() {
  data = get_line();
  length = find_length(data);
  capacity = length + 1;
}

void String::concatenate_strs(const String *str) {
  capacity += str->get_length();
  auto temp = new char[capacity];
  int index = 0;

  for (; index < length; index++) {
    temp[index] = data[index];
  }
  delete[] data;
  data = temp;

  for (int i = 0; i < str->get_length(); i++) {
    data[index] = str->get_symbol(i);
    index++;
  }
  data[index] = '\0';
}
