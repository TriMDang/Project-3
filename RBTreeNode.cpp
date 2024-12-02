//==============================================================
//==============================================================

#include "RBTreeNode.hpp"
#include <iostream>

using namespace std;

//==============================================================
// Default constructor
// Description: Creates a new node for the RBT
//==============================================================
template <typename K, typename V>
RBTreeNode<K, V>::RBTreeNode() {
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    color = true;  // New inserted nodes must be red
    data = std::pair<K, V>();
}

//==============================================================
// Parameterized Constructor
// Description: Creates a new node with a given key-value pair
//==============================================================
template <typename K, typename V>
RBTreeNode<K, V>::RBTreeNode(const std::pair<K, V>& value, bool nodeColor)
    : data(value), parent(nullptr), left(nullptr), right(nullptr), color(nodeColor) {}

//==============================================================
// Copy Constructor
// Description: Performs a deep copy of the RBT at specified node
//==============================================================
template <typename K, typename V>
RBTreeNode<K, V>::RBTreeNode(const RBTreeNode<K, V>& copiedNode)
    : data(copiedNode.data), parent(nullptr), color(copiedNode.color) {
    if (copiedNode.left != nullptr) {
        left = new RBTreeNode<K, V>(*copiedNode.left);
        left->parent = this;
    } else {
        left = nullptr;
    }

    if (copiedNode.right != nullptr) {
        right = new RBTreeNode<K, V>(*copiedNode.right);
        right->parent = this;
    } else {
        right = nullptr;
    }
}

//==============================================================
// Destructor
// Description: Deletes a node and its children recursively
//==============================================================
template <typename K, typename V>
RBTreeNode<K, V>::~RBTreeNode() {
    delete left;
    delete right;
}

//==============================================================
// Assignment Operator
// Description: Performs deep copy assignment
//==============================================================
template <typename K, typename V>
RBTreeNode<K, V>& RBTreeNode<K, V>::operator=(const RBTreeNode<K, V>& copiedNode) {
    if (this == &copiedNode) {
        return *this;
    }

    delete left;
    delete right;

    data = copiedNode.data;
    color = copiedNode.color;

    if (copiedNode.left != nullptr) {
        left = new RBTreeNode<K, V>(*copiedNode.left);
        left->parent = this;
    } else {
        left = nullptr;
    }

    if (copiedNode.right != nullptr) {
        right = new RBTreeNode<K, V>(*copiedNode.right);
        right->parent = this;
    } else {
        right = nullptr;
    }

    return *this;
}

//==============================================================
// treeMin
// Description: Locates the node with the smallest key
//==============================================================
template <typename K, typename V>
RBTreeNode<K, V>* RBTreeNode<K, V>::treeMin() {
    RBTreeNode<K, V>* current = this;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

//==============================================================
// treeMax
// Description: Locates the node with the largest key
//==============================================================
template <typename K, typename V>
RBTreeNode<K, V>* RBTreeNode<K, V>::treeMax() {
    RBTreeNode<K, V>* current = this;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current;
}

//==============================================================
// printInOrderTraversal
// Description: Prints the in-order traversal of the tree
//==============================================================
template <typename K, typename V>
void RBTreeNode<K, V>::printInOrderTraversal() const {
    if (left != nullptr) {
        left->printInOrderTraversal();  // Traverse left subtree
    }
    cout << "(" << data.first << ", " << data.second << ") ";  // Visit the root node
    if (right != nullptr) {
        right->printInOrderTraversal();  // Traverse right subtree
    }
}

