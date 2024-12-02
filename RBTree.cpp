//==============================================================
// Names: Huy Phan, Andrew Nguyen, Tri Dang
// Class: CS 271
// Project: 2
// Date: 11/5/2024
// About: This file is the implementation file for the RBTree class. It includes
// definitions for red-black tree operations such as insertion, deletion, and
// balancing. It also defines functions for finding the minimum and maximum nodes,
// performing tree rotations (left and right), and managing memory with
// default, copy constructors, destructors, and an assignment operator.
//==============================================================
#include "RBTree.hpp"
#include "RBTreeNode.hpp"
#include "customexceptions.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

//==============================================================
// Default Constructor
// Author: Tri Dang
// Description: Initializes an empty Red-Black Tree.
// Parameters: None
// Return Value: None
//==============================================================
template <typename T>
RBTree<T>::RBTree(){
    root = nullptr;
    nodeCount = 0;
}

//==============================================================
// Copy Constructor
// Author: Andrew Nguyen
// Description: Creates a deep copy of another RBTree instance.
// Parameters: const RBTree<T>& RBTree - The RBTree instance to copy.
// Return Value: None
//==============================================================
template <typename T>
RBTree<T>::RBTree( const RBTree<T> &RBTree )
{
    nodeCount = RBTree.nodeCount;
    root = nullptr;
    
    if (RBTree.root != nullptr) {
        root = new RBTreeNode<T>();
        *root = *(RBTree.root);      
        nodeCount = RBTree.nodeCount;
    }
}

//==============================================================
// deleteSubTree
// Author: Tri Dang
// Description: Recursively deletes a subtree starting from the given node.
// Parameters: RBTreeNode<T>* node - The starting node of the subtree.
// Return Value: None
//==============================================================
template <typename T>
void RBTree<T>::deleteSubTree(RBTreeNode<T>* node) {
    if (node == nullptr) {
        return; // Base case: If the node is null, do nothing.
    }

    // First, delete the left and right children.
    deleteSubTree(node->left);
    deleteSubTree(node->right);

    // Then, delete the current node.
    delete node;
}

//==============================================================
// Destructor
// Author: Andrew Nguyen
// Description: Destructor that deletes all nodes in the RBTree.
// Parameters: None
// Return Value: None
//==============================================================
template <typename T>
RBTree<T>::~RBTree() {
    deleteSubTree(root); 
}

//==============================================================
// operator= (Assignment Operator)
// Author: Tri Dang
// Description: Assigns one RBTree to another, creating a deep copy.
// Parameters: const RBTree<T>& RBTree - The RBTree instance to copy from.
// Return Value: RBTree<T>& - Reference to the modified RBTree.
//==============================================================
template <typename T>
RBTree<T>& RBTree<T>::operator=(const RBTree<T>& RBTree) {
    if (this == &RBTree){
        return *this;
    }
    deleteSubTree (root);
    nodeCount = 0;
    root = nullptr;
    
    if (RBTree.root != nullptr) {
        root = new RBTreeNode<T>();
        *root = *(RBTree.root);      
        nodeCount = RBTree.nodeCount;
    }

    return *this;
}

//==============================================================
// isEmpty
// Author: Tri Dang
// Description: Checks if the RBTree is empty.
// Parameters: None
// Return Value: bool - Returns true if the tree is empty, false otherwise.
//==============================================================
template <typename T>
bool RBTree<T>::isEmpty() const {
    return root == nullptr;
}

//==============================================================
// transplant
// Author: Andrew Nguyen
// Description: Replaces one subtree with another subtree.
// Parameters: RBTreeNode<T>* oldNode - The node to be replaced.
//             RBTreeNode<T>* newNode - The node to replace oldNode with.
// Return Value: None
//==============================================================
template <typename T>
void RBTree<T>::transplant(RBTreeNode<T>* oldNode, RBTreeNode<T>* newNode) {
    if (oldNode->parent == nullptr)
            root = newNode;
        else if (oldNode == oldNode->parent->left)
            oldNode->parent->left = newNode;
        else
            oldNode->parent->right = newNode;
        if (newNode != nullptr)
            newNode->parent = oldNode->parent;
}


//==============================================================
// leftRotation
// Author: Tri Dang
// Description: Performs a left rotation around a given node.
// Parameters: RBTreeNode<T>* centerNode - The node around which the rotation occurs.
// Return Value: None
//==============================================================
template <typename T>
void RBTree<T>::leftRotation(RBTreeNode<T>* centerNode) {
    RBTreeNode<T>* sideNode = centerNode->right;
    centerNode->right = sideNode->left;
    if (sideNode->left != nullptr){
        sideNode->left->parent = centerNode;
    }
    sideNode->parent = centerNode->parent;
    if (centerNode->parent == nullptr){
        root = sideNode; // remember to fix this
    } else if(centerNode == centerNode->parent->left){
        centerNode->parent->left = sideNode;
    } else{
        centerNode->parent->right = sideNode;
    }
    sideNode->left = centerNode;
    centerNode->parent = sideNode;
}

//==============================================================
// rightRotation
// Author: Tri Dang
// Description: Performs a right rotation around a given node.
// Parameters: RBTreeNode<T>* centerNode - The node around which the rotation occurs.
// Return Value: None
//==============================================================
template<typename T>
void RBTree<T>::rightRotation(RBTreeNode<T>* centerNode) {
    RBTreeNode<T>* sideNode = centerNode->left;
    centerNode->left = sideNode->right;
    if (sideNode->right != nullptr){
        sideNode->right->parent = centerNode;
    }
    sideNode->parent = centerNode->parent;
    if (centerNode->parent == nullptr){
        root = sideNode; // remember to fix this
    } else if(centerNode == centerNode->parent->right){
        centerNode->parent->right = sideNode;
    } else{
        centerNode->parent->left = sideNode;
    }
    sideNode->right = centerNode;
    centerNode->parent = sideNode;
}

//==============================================================
// insert
// Author: Tri Dang
// Description: Inserts a new value into the RBTree, maintaining red-black properties.
// Parameters: T value - The value to insert.
// Return Value: RBTreeNode<T>* - Pointer to the inserted node.
//==============================================================
template<typename T>
RBTreeNode<T>* RBTree<T>::insert(T value) {
    // Create a new node with the specified value
    RBTreeNode<T>* newNode = new RBTreeNode<T>();
    newNode->data = value;
    newNode->color = true;  // New nodes are red by default

    RBTreeNode<T>* parentNode = nullptr;
    RBTreeNode<T>* comparedNode = root;

    // Traverse the tree to find the insertion point
    while (comparedNode != nullptr) {
        parentNode = comparedNode;
        if (newNode->data < comparedNode->data) {
            comparedNode = comparedNode->left;
        } else {
            comparedNode = comparedNode->right;
        }
    }

    // Set the parent of the new node and update pointers
    newNode->parent = parentNode;
    if (parentNode == nullptr) {
        root = newNode;  // Tree was empty; new node becomes root
    } else if (newNode->data < parentNode->data) {
        parentNode->left = newNode;
    } else {
        parentNode->right = newNode;
    }

    // Initialize children pointers
    newNode->left = nullptr;
    newNode->right = nullptr;

    // Fix red-black properties after insertion
    insertFixup(newNode);
    nodeCount++;  // Increment node count
    return(newNode);
}

//==============================================================
// insertFixup
// Author: Tri Dang
// Description: Fixes red-black properties after insertion.
// Parameters: RBTreeNode<T>* newNode - The newly inserted node that may violate properties.
// Return Value: None
//==============================================================
template<typename T>
void RBTree<T>::insertFixup(RBTreeNode<T>* newNode) {
    while (newNode != root && newNode->parent->color == true) {
        if (newNode->parent == newNode->parent->parent->left) {  // Parent is left child of grandparent
            RBTreeNode<T>* uncle = newNode->parent->parent->right;

            // Case 1
            if (uncle != nullptr && uncle->color == true) {
                newNode->parent->color = false;
                uncle->color = false;
                newNode->parent->parent->color = true;
                newNode = newNode->parent->parent;
            } else {
                // Case 2
                if (newNode == newNode->parent->right) {
                    newNode = newNode->parent;
                    leftRotation(newNode);
                }
                // Case 3
                newNode->parent->color = false;
                newNode->parent->parent->color = true;
                rightRotation(newNode->parent->parent);
            }
        } else {  // Parent is right child of grandparent
            RBTreeNode<T>* uncle = newNode->parent->parent->left;

            // Case 1
            if (uncle != nullptr && uncle->color == true) {
                newNode->parent->color = false;
                uncle->color = false;
                newNode->parent->parent->color = true;
                newNode = newNode->parent->parent;
            } else {
                // Case 2
                if (newNode == newNode->parent->left) {
                    newNode = newNode->parent;
                    rightRotation(newNode);
                }
                // Case 3
                newNode->parent->color = false;
                newNode->parent->parent->color = true;
                leftRotation(newNode->parent->parent);
            }
        }
    }
    root->color = false;  // Ensure root is always black
}

//==============================================================
// treeMin
// Author: Andrew Nguyen
// Description: Finds the minimum value in the tree.
// Parameters: None
// Return Value: RBTreeNode<T>* - Pointer to the node with the minimum value.
//==============================================================
template <typename T>
RBTreeNode<T>* RBTree<T>::treeMin() const {
    if (root == nullptr) {
        return nullptr;
    }

    RBTreeNode<T>* ptr = root;

    while (ptr->left != nullptr) {
        ptr = ptr->left;
    }

    return ptr;
}   

//==============================================================
// treeMax
// Author: Andrew Nguyen
// Description: Finds the maximum value in the tree.
// Parameters: None
// Return Value: RBTreeNode<T>* - Pointer to the node with the maximum value.
//==============================================================
template <typename T>
RBTreeNode<T>* RBTree<T>::treeMax() const {
     if (root == nullptr) {
        return nullptr;
    }

    RBTreeNode<T>* ptr = root;

    while (ptr->right != nullptr) {
        ptr = ptr->right;
    }

    return ptr;
}

//==============================================================
// search
// Author: Andrew
// Description: Searches for a node with the specified value in the RBTree.
// Parameters: T value - The value to search for.
// Return Value: RBTreeNode<T>* - Pointer to the node with the specified value, or nullptr if not found.
//==============================================================
template <typename T>
RBTreeNode<T>* RBTree<T>::search(T value) const {
    RBTreeNode<T>* node = root;
    while (node != nullptr) {
        if (node->data == value) {
            return node;
        } if (node->data <= value) {
            node = node->right;
        } else {
            node = node->left;
        }
    }
    throw ValueNotInTreeException();
}

//==============================================================
// size
// Author: Tri Dang
// Description: Returns the number of nodes in the RBTree.
// Parameters: None
// Return Value: long - The total number of nodes in the tree.
//==============================================================
template <typename T>
long RBTree<T>::size() const{
    return (nodeCount);
}

//==============================================================
// remove
// Author:
// Description: Removes a node with the specified value from the RBTree.
// Parameters: T value - The value of the node to remove.
// Return Value: None
//==============================================================
template <typename T>
void RBTree<T>::remove(T value) {
    RBTreeNode<T>* z = nullptr;
    RBTreeNode<T>* y = nullptr;
    RBTreeNode<T>* x = nullptr;

    try {
        z = search(value);
    } catch (const ValueNotInTreeException& e) {
        cout << e.what() << endl;
        return;
    }

    y = z;
    bool yOriginalColor = y->color;
    if (z->left == nullptr) {
        x = z->right;
        transplant(z, z->right);
    } else if ( z->right == nullptr) {
        x = z->left;
        transplant(z, z->left);
    } else {
        y = z->right->treeMin();
        yOriginalColor = y->color;
        x = y->right;
        if (y->parent == z) {
                if (x != nullptr)
                    x->parent = y;
            }
            else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
    delete z;
    if (yOriginalColor == false) {
        removeFixup(x);
    }
    nodeCount--;
}


//==============================================================
// removeFixup
// Author: Andrew Nguyen
// Description: Fixes red-black properties after a deletion.
// Parameters: RBTreeNode<T>* node - The node that may violate properties after deletion.
// Return Value: None
//==============================================================
template <typename T>
void RBTree<T>::removeFixup(RBTreeNode<T>* node){
    while (node != root && node->color == false) {
            if (node == node->parent->left) {
                RBTreeNode<T>* sibling = node->parent->right;
                if (sibling->color == true) {
                    sibling->color = false;
                    node->parent->color = true;
                    leftRotation(node->parent);
                    sibling = node->parent->right;
                }
                if ((sibling->left == nullptr || sibling->left->color == false)
                    && (sibling->right == nullptr || sibling->right->color == false)) {
                    sibling->color = true;
                    node = node->parent;
                }
                else {
                    if (sibling->right == nullptr || sibling->right->color == false) {
                        if (sibling->left != nullptr) {
                            sibling->left->color = false;
                        }
                        sibling->color = true;
                        rightRotation(sibling);
                        sibling = node->parent->right;
                    }
                    sibling->color = node->parent->color;
                    node->parent->color = false;
                    if (sibling->right != nullptr) {
                        sibling->right->color = false;
                    }
                    leftRotation(node->parent);
                    node = root;
                }
            }
            else {
                RBTreeNode<T>* sibling = node->parent->left;
                if (sibling->color == true) {
                    sibling->color = false;
                    node->parent->color = true;
                    rightRotation(node->parent);
                    sibling = node->parent->left;
                }
                if ((sibling->left == nullptr || sibling->left->color == false)
                    && (sibling->right == nullptr || sibling->right->color == false)) {
                    sibling->color = true;
                    node = node->parent;
                }
                else {
                    if (sibling->left == nullptr || sibling->left->color == false) {
                        if (sibling->right != nullptr) {
                            sibling->right->color = false;
                        }
                        sibling->color = true;
                        leftRotation(sibling);
                        sibling = node->parent->left;
                    }
                    sibling->color = node->parent->color;
                    node->parent->color = false;
                    if (sibling->left != nullptr)
                        sibling->left->color = false;
                    rightRotation(node->parent);
                    node = root;
                }
            }
        }
    node->color = false;
}

//==============================================================
// printPreOrderTraversal
// Author: Andrew Nguyen
// Description: Print the pre order traversal of the tree
// Parameters: None
// Return Value: None
//==============================================================
template <typename T>
void RBTree<T>::printPreOrderTraversal() const
{
    if(root != nullptr){
        root -> printPreOrderTraversal();
    }
    else{
        throw EmptyTreeException();
    }
}

//==============================================================
// printInOrderTraversal
// Author: Andrew Nguyen
// Description: Print the in order traversal of the tree
// Parameters: None
// Return Value: None
//==============================================================
template <typename T>
void RBTree<T>::printInOrderTraversal() const
{
    if(root != nullptr){
        root -> printInOrderTraversal();
    }
    else{
        throw EmptyTreeException();
    }
}

//==============================================================
// printPostOrderTraversal
// Author: Andrew Nguyen
// Description: Print the post order traversal of the tree
// Parameters: None
// Return Value: None
//==============================================================
template <typename T>
void RBTree<T>::printPostOrderTraversal() const
{
    if(root != nullptr){
        root -> printPostOrderTraversal();
    }
    else{
        throw EmptyTreeException();
    }
}