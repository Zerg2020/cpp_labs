#include "string.h"
#include "functions.h"

String::String() : data(nullptr), lenght(0), capacity(0) {}

String::String(const char *input_str)
    : lenght(find_lenght(input_str)), capacity(lenght + 1) {
  data = new char[capacity];
  for (int index = 0; index < find_lenght(input_str); index++) {
    data[index] = input_str[index];
  }
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
  lenght = find_lenght(data);
  capacity = lenght + 1;
}

void String::concatenate_strs(const String *str) {
  capacity += str->get_lenght();
  auto temp = new char[capacity];
  int index = 0;

  for (; index < lenght; index++) {
    temp[index] = data[index];
  }
  delete[] data;
  data = temp;

  for (int i = 0; i < str->get_lenght(); i++) {
    data[index] = str->get_symbol(i);
    index++;
  }
  data[index] = '\0';
}
