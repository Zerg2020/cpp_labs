#pragma once

#include <typeinfo>

#include "tree_node.h"
#include "utils.h"

template <typename T>
TreeNode<T> *copyNodes(const TreeNode<T> *node);

template <typename T>
TreeNode<T> *createNode(T value);

template <typename T>

class BinaryTree {
    TreeNode<T> *root;

    friend TreeNode<T> *copyNodes<T>(const TreeNode<T> *other);
    void destroyNodes(TreeNode<T> *node);

   public:
    BinaryTree();
    explicit BinaryTree(T value);
    BinaryTree(const BinaryTree &other);
    BinaryTree(BinaryTree &&move) noexcept;
    ~BinaryTree();

    BinaryTree &operator=(const BinaryTree &other);
    BinaryTree &operator=(BinaryTree &&move) noexcept;

    friend TreeNode<T> *createNode<T>(T value);
    void addNode(T value);
    TreeNode<T> *findNodeByValue(T value) const;
    void traverseTopDown() const;
    void traverseDownTop() const;
};

template <typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

template <typename T>
BinaryTree<T>::BinaryTree(T value) : root(createNode(value)) {}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree &other)
    : root(copyNodes(other.root)) {}

template <typename T>
BinaryTree<T>::BinaryTree(BinaryTree &&move) noexcept : root(move.root) {
    move.root = nullptr;
}

template <typename T>
BinaryTree<T> &BinaryTree<T>::operator=(const BinaryTree &other) {
    if (this != &other) {
        destroyNodes(root);
        root = copyNodes(other.root);
    }

    return *this;
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
    destroyNodes(root);
    root = nullptr;
}

template <typename T>
BinaryTree<T> &BinaryTree<T>::operator=(BinaryTree &&move) noexcept {
    if (this != &move) {
        destroyNodes(root);
        root = move.root;
        move.root = nullptr;
    }

    return *this;
}

template <typename T>
TreeNode<T> *copyNodes(const TreeNode<T> *node) {
    if (node == nullptr) {
        return nullptr;
    }

    auto *newNode = new TreeNode<T>(node->data);

    newNode->left = copyNodes(node->left);
    newNode->right = copyNodes(node->right);

    return newNode;
}

template <typename T>
void BinaryTree<T>::destroyNodes(TreeNode<T> *node) {
    if (node == nullptr) {
        return;
    }

    destroyNodes(node->left);
    destroyNodes(node->right);

    delete node;
}

template <typename T>
TreeNode<T> *createNode(T value) {
    auto *node = new TreeNode<T>(value);

    node->left = nullptr;
    node->right = nullptr;

    return node;
}

template <typename T>
void BinaryTree<T>::addNode(T value) {
    if (root == nullptr) {
        root = createNode(value);
        return;
    }

    TreeNode<T> *curr = root;
    TreeNode<T> *prev = nullptr;

    while (curr != nullptr) {
        prev = curr;
        if (value < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    if (value < prev->data) {
        prev->left = createNode(value);
    } else {
        prev->right = createNode(value);
    }
}

template <typename T>
TreeNode<T> *BinaryTree<T>::findNodeByValue(T value) const {
    return root->findNodeByValue(root, value);
}

template <typename T>
void BinaryTree<T>::traverseTopDown() const {
    root->traverseTopDown(root);
}

template <typename T>
void BinaryTree<T>::traverseDownTop() const {
    root->traverseDownTop(root);
}