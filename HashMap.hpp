//==============================================================
// Names: Aisha Barry
// Class: CS 271-01
// Date: 11/21/2024
// About: HashMap.hpp contains the declarations for the
// HashMap class
//==============================================================

#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include <iostream>

template <typename K, typename V>
struct Node {
    K key;
    V value;
    Node* next;
};

template <typename K, typename V>
class HashMap {
private:
    size_t table_size;  // Number of buckets in the hash table
    Node<K, V>** table;  // Array of pointers to linked lists

    int hashFunction(const K& key) const;  // Computes hash index for a key

public:
    HashMap(size_t size);  // Constructor
    ~HashMap();  // Destructor

    void insert(const K& key, const V& value);  // Insert a key-value pair
    void remove(const K& key);  // Remove a key-value pair
    V& operator[](const K& key);  // Access value by key
    Node<K, V>* search(const K& key);  // Search for a key-value pair
};

#endif // HASHMAP_HPP
