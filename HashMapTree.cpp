//==============================================================
// Names: Andrew Nguyen, Tri Dang
// Class: CS 271-01
// Date: 11/21/2024
// About: 
//==============================================================
#include "HashMapTree.hpp"
#include <stdexcept>
#include "customexceptions.hpp"
using namespace std;

// Constructor
template <typename K, typename V>
HashMapTree<K, V>::HashMapTree(size_t table_size) 
    : table_size(table_size), num_elements(0), hash_function(table_size) {
    table = new RBTree<pair<K, V> >*[table_size];
    for (size_t i = 0; i < table_size; ++i) {
        table[i] = new RBTree<pair<K, V> >();
    }
}

// Copy Constructor
template <typename K, typename V>
    HashMapTree<K, V>::HashMapTree(const HashMapTree<K, V>& other) {
        table = new RBTree<pair<K, V> >*[table_size];
        for (size_t i = 0; i < table_size; ++i) {
            table[i] = new RBTree<pair<K, V> >(*other.table[i]);
        }
    }

// Destructor
template <typename K, typename V>
    HashMapTree<K, V>::~HashMapTree() {
    for (size_t i = 0; i < table_size; ++i) {
        delete table[i];
    }
    delete[] table;
}

// Assignment Operator
template <typename K, typename V>
HashMapTree<K, V>& HashMapTree<K, V>::operator=(const HashMapTree<K, V>& other) {
    if (this != &other) {
        for (size_t i = 0; i < table_size; ++i) {
            delete table[i];
        }
        delete[] table;

        table_size = other.table_size;
        num_elements = other.num_elements;
        hash_function = other.hash_function;

        table = new RBTree<pair<K, V> >*[table_size];
        for (size_t i = 0; i < table_size; ++i) {
            table[i] = new RBTree<pair<K, V> >(*other.table[i]);
        }
    }
    return *this;
}

// Insert Method
template <typename K, typename V>
void HashMapTree<K, V>::insert(const K& key, const V& value) {
    uint64_t index = hash_function.getHash(key);
    RBTreeNode<pair<K, V> >* element = search(key);
    if (element != nullptr && element->data.first == key) {
        element->data.second = value; 
        return;
    } else {
        table[index]->insert(make_pair(key, value));
        ++num_elements;
    }

}

// Remove Method
template <typename K, typename V>
void HashMapTree<K, V>::remove(RBTreeNode<pair<K, V> >* element) {
    if (element != nullptr) {
        uint64_t index = hash_function.getHash(element->data.first);
        table[index]->remove(element->data);
        --num_elements;
    }
}

// Operator[] Method
template <typename K, typename V>
    V& HashMapTree<K, V>::operator[](const K& key) {
    RBTreeNode<pair<K, V> >* element = search(key);
    if (element == nullptr) {
        throw key_exception();
    }
        else {
            return element->data.second;
        }
    }

// Search Method
template <typename K, typename V>
    RBTreeNode<pair<K, V> >* HashMapTree<K, V>::search(const K& key) {
        uint64_t index = hash_function.getHash(key);
        RBTreeNode< pair<K, V> >* current = table[index]->root;
        
        while (current != nullptr) {
            if (current->data.first == key) {
                return current;
            }
            else if (current->data.first < key) {
                current = current->right;
            }
            else { 
                current = current->left;
            }
        }
        return nullptr;
    }
