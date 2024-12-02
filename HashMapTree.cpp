//==============================================================
// Names: Andrew Nguyen, Tri Dang
// Class: CS 271-01
// Date: 11/21/2024
// About: 
//==============================================================
#include "HashMapTree.hpp"
#include "customexceptions.hpp"

// Constructor
template <typename K, typename V>
HashMapTree<K, V>::HashMapTree(size_t size)
    : table_size(size), num_elements(0), table(size) {}

// Copy Constructor
template <typename K, typename V>
HashMapTree<K, V>::HashMapTree(const HashMapTree<K, V>& other)
    : table_size(other.table_size), num_elements(other.num_elements), table(other.table_size) {
    for (size_t i = 0; i < table_size; ++i) {
        table[i] = other.table[i];  // Use RBTree's copy constructor
    }
}

// Copy Assignment Operator
template <typename K, typename V>
HashMapTree<K, V>& HashMapTree<K, V>::operator=(const HashMapTree<K, V>& other) {
    if (this == &other) {
        return *this;  // Handle self-assignment
    }

    // Step 1: Copy simple fields
    table_size = other.table_size;
    num_elements = other.num_elements;

    // Step 2: Deep copy the vector of RBTs
    table = other.table;  // Each RBTree's copy constructor is called

    return *this;
}

// Destructor
template <typename K, typename V>
HashMapTree<K, V>::~HashMapTree() {
    // No dynamic memory to clean up; the destructors of vector and RBTree handle cleanup.
}

// Hash Function
template <typename K, typename V>
size_t HashMapTree<K, V>::hashFunction(const K& key) const {
    return std::hash<K>()(key) % table_size;  // Default hash function
}

// Insert Method
template <typename K, typename V>
void HashMapTree<K, V>::insert(const K& key, const V& value) {
    size_t index = hashFunction(key);
    if (!table[index].search(key)) {  // If the key doesn't already exist
        ++num_elements;  // Increment the number of elements
    }
    table[index].insert(key, value);  // Insert key-value pair into the corresponding RBT
}

// Remove Method
template <typename K, typename V>
void HashMapTree<K, V>::remove(const K& key) {
    size_t index = hashFunction(key);
    if (table[index].remove(key)) {  // Assume RBTree remove returns a boolean for success
        --num_elements;  // Decrement the number of elements
    } else {
        throw ValueNotInTreeException();
    }
}

// Operator[] Method
template <typename K, typename V>
V& HashMapTree<K, V>::operator[](const K& key) {
    size_t index = hashFunction(key);
    RBTreeNode<K, V>* node = table[index].search(key);  // Assume RBTree search returns a pointer to the node
    if (node != nullptr) {
        return node->data.second;  // Return reference to the value
    }
    throw ValueNotInTreeException();
}

// Search Method
template <typename K, typename V>
std::pair<K, V>* HashMapTree<K, V>::search(const K& key) {
    size_t index = hashFunction(key);
    RBTreeNode<K, V>* node = table[index].search(key);  // Assume RBTree search returns a pointer to the node
    if (node != nullptr) {
        return new std::pair<K, V>(node->data.first, node->data.second);  // Dynamically allocate pair
    }
    return nullptr;  // Key not found
}

// Size Method
template <typename K, typename V>
size_t HashMapTree<K, V>::size() const {
    return num_elements;
}

// Empty Method
template <typename K, typename V>
bool HashMapTree<K, V>::empty() const {
    return num_elements == 0;
}
