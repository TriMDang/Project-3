#ifndef RBTREENODE_HPP
#define RBTREENODE_HPP

#include <utility>
#include <iostream>

template <typename K, typename V>
class RBTreeNode {
public:
    std::pair<K, V> data;          // Key-value pair stored in the node
    RBTreeNode* parent;            // Pointer to parent
    RBTreeNode* left;              // Pointer to left child
    RBTreeNode* right;             // Pointer to right child
    bool color;                    // Node color: true for red, false for black

    // Constructors and Destructor
    RBTreeNode();
    RBTreeNode(const std::pair<K, V>& value, bool nodeColor = true);
    RBTreeNode(const RBTreeNode<K, V>& other);
    ~RBTreeNode();

    RBTreeNode<K, V>& operator=(const RBTreeNode<K, V>& copiedNode);

    RBTreeNode<K, V>* treeMin();
    RBTreeNode<K, V>* treeMax();
    void printInOrderTraversal() const;
};

#endif
