#include "menus.h"

#include <iostream>

void showTask() {
    std::cout << "\t\t\t\tTASK" << std::endl;
    std::cout << "Create a parameterized class of a binary tree." << std::endl;
    std::cout << "Implement methods to:" << std::endl;
    std::cout << "- Add an element to the tree." << std::endl;
    std::cout << "- Traverse the tree in top-down (pre-order) order."
              << std::endl;
    std::cout << "- Traverse the tree in down-top (post-order) order."
              << std::endl;
    std::cout << "- Search for an element in the tree." << std::endl;
}

void showBinaryTreeTypeMenu() {
    std::cout << "\nSelect binary tree type:\n";
    std::cout << "1. int\n";
    std::cout << "2. long\n";
    std::cout << "3. float\n";
    std::cout << "4. double\n";
    std::cout << "5. char\n";
    std::cout << "6. string\n";
}

void showMenu() {
    std::cout << "\n\t\t\t\tMENU" << std::endl;
    std::cout << "1. Add an element to the tree." << std::endl;
    std::cout << "2. Traverse tree (top-down)." << std::endl;
    std::cout << "3. Traverse tree (down-top)." << std::endl;
    std::cout << "4. Search for an element." << std::endl;
    std::cout << "5. Exit program." << std::endl;
}
