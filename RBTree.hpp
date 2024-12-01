//==============================================================
// Names: Huy Phan, Andrew Nguyen, Tri Dang
// Class: CS 271
// Project: 2
// Date: 11/5/2024
// About: This file contains the declarations for the RBTree class methods.
//==============================================================
#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "RBTreeNode.hpp"
#include <stdexcept>
#include <iostream>
#include <utility>

template <typename K, typename V>
class RBTree {
public:
    RBTreeNode<K, V>* root;
    RBTreeNode<K, V>* TNULL;      // Sentinel node
    long nodeCount;              // Total number of nodes in the tree

    // Constructor and Destructor
    RBTree();
    RBTree(const RBTree<K, V>& RBTree);
    ~RBTree();
    RBTree<K, V>& operator=(const RBTree<K, V>& RBTree);

    // Core Methods
    bool isEmpty() const;
    long size() const;
    RBTreeNode<K, V>* insert(const K& key, const V& value);
    void remove(const K& key);
    RBTreeNode<K, V>* search(const K& key) const;
    RBTreeNode<K, V>* treeMin() const;
    RBTreeNode<K, V>* treeMax() const;

    // Traversal Methods
    void printPreOrderTraversal() const;
    void printInOrderTraversal() const;
    void printPostOrderTraversal() const;

private:
    // Helper Methods
    void deleteSubTree(RBTreeNode<K, V>* node);
    void transplant(RBTreeNode<K, V>* oldNode, RBTreeNode<K, V>* newNode);
    void leftRotation(RBTreeNode<K, V>* centerNode);
    void rightRotation(RBTreeNode<K, V>* centerNode);
    void insertFixup(RBTreeNode<K, V>* node);
    void removeFixup(RBTreeNode<K, V>* node);
    void printInOrderHelper(RBTreeNode<K, V>* node) const;

};

#endif
