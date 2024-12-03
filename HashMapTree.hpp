//==============================================================
// Names: Andrew Nguyen, Tri Dang
// Class: CS 271-01
// Date: 11/21/2024
// About: 
//==============================================================
#ifndef HASHMAPTREE_HPP
#define HASHMAPTREE_HPP

#include "RBTree.cpp"
#include "RBTreeNode.cpp"
#include "MyHashFunction.hpp"
using namespace std;


template <typename K, typename V>
class HashMapTree {
    private:
        size_t table_size;
        size_t num_elements;
        RBTree<pair<K, V> >** table;
        MyHashFunction<K> hash_function;

    public:
        // Constructors and Destructor
                                HashMapTree(size_t table_size);
                                HashMapTree(const HashMapTree<K, V>& other);
                                ~HashMapTree();

        // Operator Overloads
        HashMapTree<K, V>&      operator=       (const HashMapTree<K, V>& other);

        // Core Methods
        void                    insert          (const K& key, const V& value);
        void                    remove          (RBTreeNode<pair<K, V> >* element);
        V&                      operator[]      (const K& key);
        RBTreeNode<pair<K, V> >*        search          (const K& key);
   
    };


#endif // HASHMAPTREE_HPP