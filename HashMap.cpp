//==============================================================
// Names: Aisha Barry
// Class: CS 271-01
// Date: 11/21/2024
// About: HashMap.cpp contains the implementations for the
// HashMap class, handling insertion, deletion, searching, and
// retrieval using chaining for conflict resolution.
//==============================================================

#include "HashMap.hpp"

//==============================================================
// HashMap (constructor)
// Constructs a hash map with a specified number of buckets.
// PARAMETERS: size - the number of buckets in the hash table
//==============================================================
template <typename K, typename V>
HashMap<K, V>::HashMap(size_t size) : table_size(size), table(size) {}

//==============================================================
// ~HashMap (destructor)
// Destructor that clears the hash table.
//==============================================================
template <typename K, typename V>
HashMap<K, V>::~HashMap() {
    for (auto& bucket : table) {
        bucket.clear();
    }
}

//==============================================================
// hashFunction
// Computes the hash index for a given key using std::hash.
// PARAMETERS: key - the key to hash
// Return value: the computed hash index
//==============================================================
template <typename K, typename V>
size_t HashMap<K, V>::hashFunction(const K& key) const {
    return std::hash<K>()(key) % table_size;
}

//==============================================================
// insert
// Inserts a key-value pair into the hash map. If the key
// already exists, its value is updated.
// PARAMETERS: key - the key to insert
//             value - the value to associate with the key
//==============================================================
template <typename K, typename V>
void HashMap<K, V>::insert(const K& key, const V& value) {
    size_t index = hashFunction(key);
    for (auto& pair : table[index]) {
        if (pair.first == key) {
            pair.second = value;  // Overwrite if the key already exists
            return;
        }
    }
    table[index].emplace_back(key, value);  // Add new key-value pair
}

//==============================================================
// remove
// Removes a key-value pair from the hash map.
// PARAMETERS: key - the key to remove
//==============================================================
template <typename K, typename V>
void HashMap<K, V>::remove(const K& key) {
    size_t index = hashFunction(key);
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if (it->first == key) {
            table[index].erase(it);  // Remove the pair from the list
            return;
        }
    }
    throw std::runtime_error("Key not found");
}

//==============================================================
// operator[]
// Retrieves or modifies the value associated with a key. If
// the key does not exist, a new entry is created.
// PARAMETERS: key - the key to retrieve or modify
// Return value: a reference to the associated value
//==============================================================
template <typename K, typename V>
V& HashMap<K, V>::operator[](const K& key) {
    size_t index = hashFunction(key);
    for (auto& pair : table[index]) {
        if (pair.first == key) {
            return pair.second;  // Return the existing value
        }
    }
    // Key does not exist, so insert with default value
    table[index].emplace_back(key, V());
    return table[index].back().second;
}

//==============================================================
// search
// Searches for a key-value pair in the hash map.
// PARAMETERS: key - the key to search for
// Return value: a pointer to the key-value pair, or nullptr if
//               the key is not found
//==============================================================
template <typename K, typename V>
std::pair<K, V>* HashMap<K, V>::search(const K& key) {
    size_t index = hashFunction(key);
    for (auto& pair : table[index]) {
        if (pair.first == key) {
            return &pair;  // Return a pointer to the pair
        }
    }
    return nullptr;  // Key not found
}
