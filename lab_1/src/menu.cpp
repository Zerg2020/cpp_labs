#include "menu.h"

void print_message_menu() {
  std::cout << "\n\tMENU" << std::endl;
  std::cout << "1.Creat string" << std::endl;
  std::cout << "2.Fill string" << std::endl;
  std::cout << "3.Show string " << std::endl;
  std::cout << "4.Strings concatenate" << std::endl;
  std::cout << "5.Exit" << std::endl;
}

void print_message_create_menu() {
  std::cout << "\nChoose which constructor to use to create strings"
            << std::endl;
  std::cout << "1.Creat a default string" << std::endl;
  std::cout << "2.Creat a string with beginer's values" << std::endl;
  std::cout << "3.Return to the main menu" << std::endl;
}

void menu() {
  String *str_first = nullptr;
  String *str_second = nullptr;

  while (true) {
    print_message_menu();
    std::cout << "\o{33}[33mEnter number of operation \o{33}[0m" << std::endl;
    int choose = get_digit();

    switch (choose) {
    case 1:
      menu_create_string(&str_first, &str_second);
      break;

    case 2:
      if (str_first != nullptr) {
        std::cout << "The first string" << std::endl;
        str_first->fill();
        std::cout << "The second string" << std::endl;
        str_second->fill();
      } else {
        std::cout << C_RED << "Error: strings not filled." << C_WHITE
                  << std::endl;
      }
      break;

    case 3:
      if (str_first != nullptr) {
        std::cout << "The first string" << std::endl;
        str_first->show();
        std::cout << "The second string" << std::endl;
        str_second->show();
      } else {
        std::cout << C_RED << "Error: strings not filled." << C_WHITE
                  << std::endl;
      }
      break;

    case 4:
      if (str_first == nullptr) {
        std::cout << C_RED << "Error: strings not filled." << C_WHITE
                  << std::endl;
        break;
      }

      std::cout << "First string before concotanate" << std::endl;
      str_first->show();
      str_first->concatenate_strs(str_second);
      std::cout << "First string after concotanate" << std::endl;
      str_first->show();

      break;

    case 5:
      delete str_first;
      delete str_second;
      str_first = nullptr;
      str_second = nullptr;
      return;

    default:
      std::cout << C_RED << "Invalid choice, please try again." << C_WHITE
                << std::endl;
      break;
    }
  }
}

void menu_create_string(String **str_1, String **str_2) {
  delete *str_1;
  delete *str_2;
  *str_1 = nullptr;
  *str_2 = nullptr;
  print_message_create_menu();
  while (true) {
    std::cout << "Enter the operation number " << std::endl;
    int choose = get_digit();

    switch (choose) {
    case 1: {
      *str_1 = new String();
      *str_2 = new String();
      return;
    }
    case 2: {
      std::cout << "The first string" << std::endl;
      const char *input_user = nullptr;
      input_user = get_line();
      *str_1 = new String(input_user);

      std::cout << "The secound string" << std::endl;
      input_user = get_line();
      *str_2 = new String(input_user);
      return;
    }
    case 3:
      return;
    default:
      std::cout << C_RED << "You make mistake, try again" << C_WHITE
                << std::endl;
      break;
    }
  }
}
