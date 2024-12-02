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

template <typename T>
class RBTree {
public:
    RBTreeNode<T>* root;
    long nodeCount;

    void        transplant(RBTreeNode<T>* oldNode, RBTreeNode<T>* newNode);
    void        leftRotation(RBTreeNode<T>* centerNode); // NOT part of assignment (helper function)
    void        rightRotation(RBTreeNode<T>* centerNode); // NOT part of assignment (helper function)
    void        insertFixup(RBTreeNode<T>* node);
    void        removeFixup(RBTreeNode<T>* node);
    // The 4 default functions:
    // default constructor
    RBTree<T>           (void);
    // copy constructor
    RBTree<T>           ( const RBTree<T> &RBTree );
    // destructor
    void deleteSubTree(RBTreeNode<T>* node);
    ~RBTree<T>          ();
    // operator = 
    RBTree<T>&          operator=(const RBTree<T>& RBTree);

    // Public methods
    bool                isEmpty()       const;
    long                size()          const;
    RBTreeNode<T>*      insert(T value);
    void remove(T value);
    RBTreeNode<T>*      search(T value) const;
    RBTreeNode<T>*      treeMin()       const;
    RBTreeNode<T>*      treeMax()       const;
    void        printPreOrderTraversal() const;
    void        printInOrderTraversal() const;
    void        printPostOrderTraversal() const;

};

#endif
