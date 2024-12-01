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
//==============================================================
template <typename K, typename V>
RBTree<K, V>::RBTree() {
    TNULL = new RBTreeNode<K, V>();
    TNULL->color = false;  // Black
    TNULL->left = nullptr;
    TNULL->right = nullptr;
    root = TNULL;
    nodeCount = 0;
}

//==============================================================
// Copy Constructor
// Author: Andrew Nguyen
// Description: Creates a deep copy of another RBTree instance.
//==============================================================
template <typename K, typename V>
RBTree<K, V>::RBTree(const RBTree<K, V>& RBTree) {
    TNULL = new RBTreeNode<K, V>();
    TNULL->color = false;  // Black
    root = TNULL;
    nodeCount = 0;

    if (RBTree.root != RBTree.TNULL) {
        root = new RBTreeNode<K, V>();
        *root = *(RBTree.root);      
        nodeCount = RBTree.nodeCount;
    }
}

//==============================================================
// deleteSubTree
// Author: Tri Dang
// Description: Recursively deletes a subtree starting from the given node.
//==============================================================
template <typename K, typename V>
void RBTree<K, V>::deleteSubTree(RBTreeNode<K, V>* node) {
    if (node == TNULL) {
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
//==============================================================
template <typename K, typename V>
RBTree<K, V>::~RBTree() {
    deleteSubTree(root); 
    delete TNULL;
}

//==============================================================
// operator= (Assignment Operator)
// Author: Tri Dang
// Description: Assigns one RBTree to another, creating a deep copy.
//==============================================================
template <typename K, typename V>
RBTree<K, V>& RBTree<K, V>::operator=(const RBTree<K, V>& RBTree) {
    if (this == &RBTree){
        return *this;
    }
    deleteSubTree(root);
    nodeCount = 0;
    root = TNULL;

    if (RBTree.root != RBTree.TNULL) {
        root = new RBTreeNode<K, V>();
        *root = *(RBTree.root);      
        nodeCount = RBTree.nodeCount;
    }

    return *this;
}

//==============================================================
// insert
// Author: Tri Dang
// Description: Inserts a new key-value pair into the RBTree.
//==============================================================
template <typename K, typename V>
RBTreeNode<K, V>* RBTree<K, V>::insert(const K& key, const V& value) {
    // Create a new node with the specified key-value pair
    RBTreeNode<K, V>* newNode = new RBTreeNode<K, V>(make_pair(key, value), true);

    RBTreeNode<K, V>* parentNode = nullptr;
    RBTreeNode<K, V>* comparedNode = root;

    // Traverse the tree to find the insertion point
    while (comparedNode != TNULL) {
        parentNode = comparedNode;
        if (key < comparedNode->data.first) {
            comparedNode = comparedNode->left;
        } else if (key > comparedNode->data.first) {
            comparedNode = comparedNode->right;
        } else {
            // Key exists, update value
            comparedNode->data.second = value;
            delete newNode;  // New node is not needed
            return comparedNode;
        }
    }

    // Set the parent of the new node and update pointers
    newNode->parent = parentNode;
    if (parentNode == nullptr) {
        root = newNode;  // Tree was empty; new node becomes root
    } else if (key < parentNode->data.first) {
        parentNode->left = newNode;
    } else {
        parentNode->right = newNode;
    }

    // Initialize children pointers
    newNode->left = TNULL;
    newNode->right = TNULL;

    // Fix red-black properties after insertion
    insertFixup(newNode);
    nodeCount++;  // Increment node count
    return newNode;
}

//==============================================================
// search
// Author: Andrew
// Description: Searches for a node with the specified key in the RBTree.
//==============================================================
template <typename K, typename V>
RBTreeNode<K, V>* RBTree<K, V>::search(const K& key) const {
    RBTreeNode<K, V>* node = root;
    while (node != TNULL) {
        if (key == node->data.first) {
            return node;
        } else if (key < node->data.first) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    throw ValueNotInTreeException();
}

//==============================================================
// remove
// Author: Andrew Nguyen
// Description: Removes a node with the specified key from the RBTree.
//==============================================================
template <typename K, typename V>
void RBTree<K, V>::remove(const K& key) {
    RBTreeNode<K, V>* z = nullptr;
    RBTreeNode<K, V>* y = nullptr;
    RBTreeNode<K, V>* x = nullptr;

    try {
        z = search(key);
    } catch (const ValueNotInTreeException& e) {
        cout << e.what() << endl;
        return;
    }

    y = z;
    bool yOriginalColor = y->color;
    if (z->left == TNULL) {
        x = z->right;
        transplant(z, z->right);
    } else if (z->right == TNULL) {
        x = z->left;
        transplant(z, z->left);
    } else {
        y = z->right->treeMin();
        yOriginalColor = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        } else {
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
// transplant
// Author: Andrew Nguyen
// Description: Replaces one subtree with another subtree.
// Parameters: RBTreeNode<K, V>* oldNode - The node to be replaced.
//             RBTreeNode<K, V>* newNode - The node to replace oldNode with.
//==============================================================
template <typename K, typename V>
void RBTree<K, V>::transplant(RBTreeNode<K, V>* oldNode, RBTreeNode<K, V>* newNode) {
    if (oldNode->parent == nullptr) {
        root = newNode;
    } else if (oldNode == oldNode->parent->left) {
        oldNode->parent->left = newNode;
    } else {
        oldNode->parent->right = newNode;
    }
    newNode->parent = oldNode->parent;
}

//==============================================================
// leftRotation
// Author: Tri Dang
// Description: Performs a left rotation around a given node.
//==============================================================
template <typename K, typename V>
void RBTree<K, V>::leftRotation(RBTreeNode<K, V>* centerNode) {
    RBTreeNode<K, V>* sideNode = centerNode->right;
    centerNode->right = sideNode->left;
    if (sideNode->left != TNULL) {
        sideNode->left->parent = centerNode;
    }
    sideNode->parent = centerNode->parent;
    if (centerNode->parent == nullptr) {
        root = sideNode;
    } else if (centerNode == centerNode->parent->left) {
        centerNode->parent->left = sideNode;
    } else {
        centerNode->parent->right = sideNode;
    }
    sideNode->left = centerNode;
    centerNode->parent = sideNode;
}

//==============================================================
// rightRotation
// Author: Tri Dang
// Description: Performs a right rotation around a given node.
//==============================================================
template <typename K, typename V>
void RBTree<K, V>::rightRotation(RBTreeNode<K, V>* centerNode) {
    RBTreeNode<K, V>* sideNode = centerNode->left;
    centerNode->left = sideNode->right;
    if (sideNode->right != TNULL) {
        sideNode->right->parent = centerNode;
    }
    sideNode->parent = centerNode->parent;
    if (centerNode->parent == nullptr) {
        root = sideNode;
    } else if (centerNode == centerNode->parent->right) {
        centerNode->parent->right = sideNode;
    } else {
        centerNode->parent->left = sideNode;
    }
    sideNode->right = centerNode;
    centerNode->parent = sideNode;
}

//==============================================================
// removeFixup
// Author: Andrew Nguyen
// Description: Fixes red-black properties after a deletion.
//==============================================================
template <typename K, typename V>
void RBTree<K, V>::removeFixup(RBTreeNode<K, V>* node) {
    while (node != root && node->color == false) {  // Node is black
        if (node == node->parent->left) {
            RBTreeNode<K, V>* sibling = node->parent->right;
            if (sibling->color == true) {  // Case 1: Sibling is red
                sibling->color = false;
                node->parent->color = true;
                leftRotation(node->parent);
                sibling = node->parent->right;
            }
            if (sibling->left->color == false && sibling->right->color == false) {  // Case 2
                sibling->color = true;
                node = node->parent;
            } else {
                if (sibling->right->color == false) {  // Case 3
                    sibling->left->color = false;
                    sibling->color = true;
                    rightRotation(sibling);
                    sibling = node->parent->right;
                }
                sibling->color = node->parent->color;  // Case 4
                node->parent->color = false;
                sibling->right->color = false;
                leftRotation(node->parent);
                node = root;
            }
        } else {  // Symmetric cases
            RBTreeNode<K, V>* sibling = node->parent->left;
            if (sibling->color == true) {
                sibling->color = false;
                node->parent->color = true;
                rightRotation(node->parent);
                sibling = node->parent->left;
            }
            if (sibling->right->color == false && sibling->left->color == false) {
                sibling->color = true;
                node = node->parent;
            } else {
                if (sibling->left->color == false) {
                    sibling->right->color = false;
                    sibling->color = true;
                    leftRotation(sibling);
                    sibling = node->parent->left;
                }
                sibling->color = node->parent->color;
                node->parent->color = false;
                sibling->left->color = false;
                rightRotation(node->parent);
                node = root;
            }
        }
    }
    node->color = false;  // Ensure the root is black
}

//==============================================================
// printInOrderTraversal
// Author: Andrew Nguyen
// Description: Prints the in-order traversal of the tree.
// Parameters: None
// Return Value: None
//==============================================================
template <typename K, typename V>
void RBTree<K, V>::printInOrderTraversal() const {
    if (root != TNULL) {
        root->printInOrderTraversal();
    } else {
        throw EmptyTreeException();
    }
    cout << endl;
}

