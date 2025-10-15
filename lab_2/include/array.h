#pragma once
#include <iostream>

class Array {
  int *data;
  int size;

public:
  Array();
  explicit Array(int arr_size);
  ~Array();
  Array(const Array &other);
  Array(Array &&move) noexcept;
  Array &operator=(const Array &other);
  Array &operator=(Array &&move) noexcept;
  Array &operator++();
  Array operator++(int value);

  bool is_empty() const;
  friend void input(Array &arr, const std::string &msg);
  //void input(const std::string &msg);
  friend void show(Array arr, const std::string &msg);
};