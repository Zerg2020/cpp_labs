#include "functions.h"
#include "string.h"

char *get_line() {
  char *str{};
  int symbol;

  while ((symbol = std::cin.get()) != '\n') {
    int length = find_length(str);
    auto temp = new char[length + 2];
    for (int i = 0; i < length; i++) {
      temp[i] = str[i];
    }
    temp[length] = (char)symbol;
    temp[length + 1] = '\0';

    delete[] str;
    str = temp;
  }
  return str;
}

int find_length(const char *str_) {
  if (str_ == nullptr)
    return 0;
  int size = 0;
  while (str_[size] != '\0') {
    size++;
  }
  return size;
}

int get_digit() {
  int check = 0;

  while (true) {
    check = std::cin.get();

    if (check != '\n' && check != EOF) {
      if (isdigit(check) == 1 && std::cin.get() == '\n') {
        return check - '0';
      }

      while (std::cin.get() != '\n' && !std::cin.eof());
    }

    std::cout << C_RED
              << "\nError, invalid input. Please try again: " << C_WHITE;
  }
}
