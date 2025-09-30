#pragma once
#include <iostream>

class String 
{
  private : 

  char *data;
  int lenght;
  int capacity;

  public:
  String();
  explicit String(const char *str);

  int get_lenght() const {return lenght;}
  char get_symbol(int index) const {return data[index];}

  void show() const;
  void fill();
  void concatenate_strs(const String* str);
};