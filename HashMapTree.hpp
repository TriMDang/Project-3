//==============================================================
// Names: Andrew Nguyen, Tri Dang
// Class: CS 271-01
// Date: 11/21/2024
// About: 
//==============================================================
#ifndef HASHMAPTREE_HPP
#define HASHMAPTREE_HPP

#include <vector>
#include <functional>
#include <stdexcept>
#include <utility>
#include "RBTree.hpp" // Include your RBTree header

template <typename K, typename V>
class HashMapTree {
private:
    size_t table_size;  // Number of buckets in the hash table
    size_t num_elements;  // Total number of key-value pairs
    std::vector<RBTree<K, V> > table;  // Hash table as a vector of RBTs

    size_t hashFunction(const K& key) const;  // Computes the hash index for a given key

public:
    HashMapTree(size_t size = 100);  // Constructor
    HashMapTree(const HashMapTree<K, V>& other);  // Copy constructor
    HashMapTree& operator=(const HashMapTree<K, V>& other);  // Assignment operator
    ~HashMapTree();  // Destructor

    void insert(const K& key, const V& value);  // Inserts a key-value pair
    void remove(const K& key);  // Removes a key-value pair
    V& operator[](const K& key);  // Retrieves or modifies a value by key
    std::pair<K, V>* search(const K& key);  // Searches for a key-value pair
    size_t size() const;  // Returns the number of elements
    bool empty() const;  // Checks if the table is empty
};

#endif // HASHMAPTREE_HPP