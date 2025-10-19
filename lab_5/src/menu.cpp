#include "menu.h"

void print_choose_type_array()
{
  std::cout << "\nType of array" << std::endl;
  std::cout << "1.Integer " << std::endl;
  std::cout << "2.Double" << std::endl;
  std::cout << "3.Char" << std::endl;
  std::cout << "4.String" << std::endl;
  std::cout << "5.exit" << std::endl;
}

void menu()
{
  while (true)
  {
    print_choose_type_array();
    int choose = get_int("Enter number of type ", 1, 5);

    switch (choose)
    {
    case 1:
      process_array<int>();
      break;
    case 2:
      process_array<double>();
      break;
    case 3:
      process_array<char>();
      break;
    case 4:
      process_array<std::string>();
      break;
    case 5:
      return;
    default:
      break;
    }
  }
}
