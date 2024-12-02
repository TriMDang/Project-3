//==============================================================
// Names: Aisha Barry
// Class: CS 271-01
// Date: 11/21/2024
// About: HashMap.hpp contains the declarations for the
// HashMap class, which implements a hash table using chaining
// and the multiplication method for hashing keys.
//==============================================================

#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include "MyHashFunction.cpp"
#include <cstddef>  // For size_t
#include <utility>  // For std::pair

template <typename K, typename V>
struct Node {
    std::pair<K, V> data;  // Key-value pair
    Node* next;            // Pointer to the next node
    Node* prev;            // Pointer to the previous node
};

template <typename K, typename V>
class HashMap {
private:
    size_t table_size;        // Number of buckets
    Node<K, V>** table;       // Array of pointers to doubly linked lists
    MyHashFunction<K> hash_function;  // Hash function instance

public:
    // Constructor and Destructor
    HashMap(std::size_t size);  // Constructor
    ~HashMap();                 // Destructor

    // Core Methods
    void insert(const K& key, const V& value);  // Insert a key-value pair
    void remove(const K& key);                 // Remove a key-value pair
    V& operator[](const K& key);               // Access value by key
    Node<K, V>* search(const K& key);          // Search for a key-value pair
};

#endif // HASHMAP_HPP

