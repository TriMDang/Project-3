//==============================================================
// Names: Huy Phan, Andrew Nguyen, Tri Dang
// Class: CS 271
// Project: 2
// Date: 11/5/2024
// This file contains the implementation of the RBTreeNode class,
// including the default and copy constructors, assignment operator,
// destructor, and tree traversal methods (preorder, inorder, postorder).
// It also includes functions to find the minimum and maximum nodes in the tree.
// The class supports efficient insertions, deletions, and searches in a Red-Black Tree.
//==============================================================

#include "RBTreeNode.hpp"
#include <iostream>

using namespace std;

//==============================================================
// Default constructor
// Author: Tri Dang
// Description: create a new node for the RBT
// Parameters: None
// Return Value: None
//==============================================================
template <typename T>
RBTreeNode<T>::RBTreeNode(void){
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    color = true; // new inserted nodes must be red
    data = T();
}

//==============================================================
// Copy constructor
// Author: Tri Dang
// Description: deep copy of the RBT at specified node
// Parameters: None
// Return Value: None
//==============================================================
template <typename T>
RBTreeNode<T>::RBTreeNode(const RBTreeNode<T> &copiedNode){
    data = copiedNode.data;
    parent = nullptr;
    color = copiedNode.color;
    // Deep copy of the left subtree recursively
    if (copiedNode.left != nullptr) {
        left = new RBTreeNode<T>(*copiedNode.left);
        left->parent = this;
    } else {
        left = nullptr;
    }
    // Deep copy of the right child recursively
    if (copiedNode.right != nullptr) {
        right = new RBTreeNode<T>(*copiedNode.right);
        right->parent = this;
    } else {
        right = nullptr;
    }
}

//==============================================================
// Destructor
// Author: Tri Dang
// Description: delete a node
// Parameters: None
// Return Value: None
//==============================================================
template <typename T>
RBTreeNode<T>::~RBTreeNode(void){
}

//==============================================================
// Operator =
// Author: Tri Dang
// Description: assignment operator
// Parameters: None
// Return Value: None
//==============================================================
template <typename T>
RBTreeNode<T>& RBTreeNode<T>::operator=(const RBTreeNode<T> &copiedNode){
    if (this == &copiedNode) {
        return *this;
    }   
    delete left;
    delete right;
    data = copiedNode.data;
    color = copiedNode.color;
    // Deep copy of the left subtree recursively
    if (copiedNode.left != nullptr) {
        left = new RBTreeNode<T>(*copiedNode.left);
        left->parent = this;
    } else {
        left = nullptr;
    }
    // Deep copy of the right child recursively
    if (copiedNode.right != nullptr) {
        right = new RBTreeNode<T>(*copiedNode.right);
        right->parent = this;
    } else {
        right = nullptr;
    }
    return *this;
}

//==============================================================
// treeMin
// Author: Andrew Nguyen
// Description: locate the node with the smallest value by moving
//              to the left-most node on the left subtree of the
//.             current node.
// Parameters: None
// Return Value: node which value is the smallest in the tree
//==============================================================
template <typename T>
RBTreeNode<T>* RBTreeNode<T>::treeMin() {
    RBTreeNode<T>* current = this;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

//==============================================================
// treeMax
// Author: Andrew Nguyen
// Description: locate the node with the largest value by moving
//              to the right-most node on the right subtree of the
//.             current node.
// Parameters: None
// Return Value: node which value is the largest in the tree
//==============================================================
template <typename T>
RBTreeNode<T>* RBTreeNode<T>::treeMax() {
    RBTreeNode<T>* current = this;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current;
}

//==============================================================
// printPreOrderTraversal()
// Author: Andrew Nguyen
// Description: helper function to print the pre order traversal
//              of the nodes' value.
// Parameters: None
// Return Value: None
//==============================================================
template <typename T>
void RBTreeNode<T>::printPreOrderTraversal() const {
    cout << data << " "; // Visit the root node
    if (left != nullptr) {
        left->printPreOrderTraversal(); // Traverse left subtree
    }
    if (right != nullptr) {
        right->printPreOrderTraversal(); // Traverse right subtree
    }
}

//==============================================================
// printInOrderTraversal()
// Author: Andrew Nguyen
// Description: helper function to print the in order traversal
//              of the nodes' value.
// Parameters: None
// Return Value: None
//==============================================================
template <typename T>
void RBTreeNode<T>::printInOrderTraversal() const {
    if (left != nullptr) {
        left->printInOrderTraversal(); // Traverse left subtree
    }
    cout << data << " "; // Visit the root node
    if (right != nullptr) {
        right->printInOrderTraversal(); // Traverse right subtree
    }
}

//==============================================================
// printPostOrderTraversal()
// Author: Andrew Nguyen
// Description: helper function to print the post order traversal
//              of the nodes' value.
// Parameters: None
// Return Value: None
//==============================================================
template <typename T>
void RBTreeNode<T>::printPostOrderTraversal() const {
    if (left != nullptr) {
        left->printPostOrderTraversal(); // Traverse left subtree
    }
    if (right != nullptr) {
        right->printPostOrderTraversal(); // Traverse right subtree
    }
    cout << data << " "; // Visit the root node
}
