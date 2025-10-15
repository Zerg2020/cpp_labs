#pragma once
#include <iostream>

class String 
{
  private : 

  char *data;
  int length;
  int capacity;

  public:
  String();
  explicit String(const char *str);

  int get_length() const {return length;}
  char get_symbol(int index) const {return data[index];}

  void show() const;
  void fill();
  void concatenate_strs(const String* str);
};