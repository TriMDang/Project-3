//==============================================================
// Names: Aisha Barry
// Class: CS 271-01
// Date: 11/21/2024
// About: HashMap.hpp contains the declarations for the
// HashMap class, which implements a hash table with chaining
// for conflict resolution.
//==============================================================

#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include <vector>
#include <list>
#include <utility>
#include <stdexcept>

template <typename K, typename V>
class HashMap {
private:
    size_t table_size;  // Number of buckets in the hash table
    std::vector<std::list<std::pair<K, V>>> table;  // Hash table as a vector of lists

    size_t hashFunction(const K& key) const;  // Computes the hash index for a given key

public:
    HashMap(size_t size = 100);  // Constructor
    ~HashMap();  // Destructor

    void insert(const K& key, const V& value);  // Inserts a key-value pair
    void remove(const K& key);  // Removes a key-value pair
    V& operator[](const K& key);  // Retrieves or modifies a value by key
    std::pair<K, V>* search(const K& key);  // Searches for a key-value pair
};

#include "HashMap.cpp"

#endif // HASHMAP_HPP
