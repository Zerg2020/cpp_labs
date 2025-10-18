#pragma once

#include <iostream>

#include "binary_tree.h"
#include "consts.h"
#include "menus.h"
#include "utils.h"

template <typename T>

class Program {
    BinaryTree<T> tree;

    void addBinaryTreeNode();
    void traverseTopDownBinaryTree();
    void traverseDownTopBinaryTree();
    void findBinaryTreeNodeByValue();

   public:
    Program();
    void run();
};

template <typename T>
Program<T>::Program() {
    std::cout
        << "\nPlease create binary tree.\nEnter the binary tree node data: ";

    T value = getValue<T>();

    tree.addNode(value);
    std::cout << kGreenColor << "\nYou successfully created binary tree!"
              << kWhiteColor << std::endl;
}

template <typename T>
void Program<T>::addBinaryTreeNode() {
    std::cout << "\nPlease enter the value which you want to add to the binary "
                 "tree: ";
    T value = getValue<T>();

    if (tree.findNodeByValue(value) != nullptr) {
        std::cout << kRedColor
                  << "\nError, this value already exists in the binary tree."
                  << kWhiteColor << std::endl;
        return;
    }

    tree.addNode(value);

    std::cout << kGreenColor << "\nYou successfully added node to binary tree!"
              << kWhiteColor << std::endl;
}

template <typename T>
void Program<T>::traverseTopDownBinaryTree() {
    std ::cout << "\nBinary tree traverse from top to down:";

    tree.traverseTopDown();

    std::cout << kGreenColor
              << "\nYou have successfully traversed the tree from top to down!"
              << kWhiteColor << std::endl;
}

template <typename T>
void Program<T>::traverseDownTopBinaryTree() {
    std ::cout << "\nBinary tree traverse from down to top:";

    tree.traverseDownTop();

    std::cout << kGreenColor
              << "\nYou have successfully traversed the tree from down to top!"
              << kWhiteColor << std::endl;
}

template <typename T>
void Program<T>::findBinaryTreeNodeByValue() {
    std::cout << "\nPlease enter the value which you want to find: ";
    T value = getValue<T>();

    if (tree.findNodeByValue(value) != nullptr) {
        std::cout << kGreenColor
                  << "\nYou have successfully finded node by value!"
                  << kWhiteColor << std::endl;
    } else {
        std::cout << kRedColor << "\nNode with this value was not found!"
                  << kWhiteColor << std::endl;
    }
}

template <typename T>
void Program<T>::run() {
    showMenu();

    int opt = 0;

    while (true) {
        std::cout << "\nPlease enter menu option: ";

        opt = getValue<int>();

        switch (opt) {
            case 1:
                addBinaryTreeNode();
                break;
            case 2:
                traverseTopDownBinaryTree();
                break;
            case 3:
                traverseDownTopBinaryTree();
                break;
            case 4:
                findBinaryTreeNodeByValue();
                break;
            case 5:
                std::cout << kGreenColor
                          << "\nYou have successfully exited the program."
                          << kWhiteColor << std::endl;
                return;
            default:
                std::cout << kRedColor
                          << "\nError, you picked is an incorrect menu option. "
                             "Please try again."
                          << kWhiteColor << std::endl;
        }
    }
}