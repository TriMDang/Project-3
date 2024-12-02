#include <iostream>
using namespace std;

#ifndef RBTREE_OPERATIONS_HPP
#define RBTREE_OPERATIONS_HPP

template<typename T>
class RBTreeNode {
public:
    T data;                         
    RBTreeNode* parent;       
    RBTreeNode* left;              
    RBTreeNode* right;              
    bool color;                     

    // The 4 default methods
    RBTreeNode<T> (void);
    RBTreeNode<T> (const RBTreeNode<T> &RBTreeNode);
    ~RBTreeNode<T> (void);
    RBTreeNode<T>& operator=(const RBTreeNode<T> &RBTreeNode);


    RBTreeNode<T>*      treeMin();
    RBTreeNode<T>*      treeMax();
    void                printPreOrderTraversal()    const;
    void                printInOrderTraversal()     const;
    void                printPostOrderTraversal()   const;
};

#endif
