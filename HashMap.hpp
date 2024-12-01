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
using namespace std;

template <typename K, typename V>
struct Node {
    K key;
    V value;
    Node* next;
};

template <typename K, typename V>
class HashMap {
private:
    size_t table_size;  // Number of buckets
    Node<K, V>** table;  // Array of pointers to linked lists
    MyHashFunction<K> hash_function;  // Hash function instance

public:
    HashMap(size_t size);  // Constructor
    ~HashMap();  // Destructor
    HashMap(const HashMap<K, V>& otherMap);
    HashMap<K, V>& operator=(const HashMap<K, V>& otherMap);


    void insert(const K& key, const V& value);  // Insert a key-value pair
    void remove(const K& key);  // Remove a key-value pair
    V& operator[](const K& key);  // Access value by key
    Node<K, V>* search(const K& key);  // Search for a key-value pair
    void clear();
};

#endif // HASHMAP_HPP
