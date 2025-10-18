#pragma once

#include <iostream>

template <typename T>

struct TreeNode {
    T data;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    explicit TreeNode(T value);
    void traverseTopDown(TreeNode<T>* node) const;
    void traverseDownTop(TreeNode<T>* node) const;
    TreeNode* findNodeByValue(TreeNode<T>* root, T value) const;
};

template <typename T>
TreeNode<T>::TreeNode(T value) : data(std::move(value)) {}

template <typename T>
void TreeNode<T>::traverseTopDown(TreeNode<T>* node) const {
    if (node == nullptr) {
        return;
    }

    std::cout << " -> " << node->data;

    traverseTopDown(node->left);
    traverseTopDown(node->right);
}

template <typename T>
void TreeNode<T>::traverseDownTop(TreeNode<T>* node) const {
    if (node == nullptr) {
        return;
    }

    traverseDownTop(node->left);
    traverseDownTop(node->right);

    std::cout << " -> " << node->data;
}

template <typename T>
TreeNode<T>* TreeNode<T>::findNodeByValue(TreeNode<T>* root, T value) const {
    if (root == nullptr) return nullptr;
    if (root->data == value) return root;

    if (auto* node = findNodeByValue(root->left, value)) {
        return node;
    }
    if (auto* node = findNodeByValue(root->right, value)) {
        return node;
    }

    return nullptr;
}