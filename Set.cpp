#include "Set.hpp"

//==============================================================
// Constructor
// Constructs a set with a specified number of buckets.
// PARAMETERS: size - the number of buckets in the hash table
//==============================================================
template <typename T>
Set<T>::Set(size_t size) : table_size(size), table(size) {}

//==============================================================
// Destructor
// Destructor that clears the hash table.
//==============================================================
template <typename T>
Set<T>::~Set() {
    for (auto& bucket : table) {
        bucket.clear();
    }
}

//==============================================================
// hashFunction
// Computes the hash index for a given value using std::hash.
// PARAMETERS: value - the value to hash
// Return value: the computed hash index
//==============================================================
template <typename T>
size_t Set<T>::hashFunction(const T& value) const {
    return std::hash<T>()(value) % table_size;
}

//==============================================================
// insert
// Inserts a value into the set. If the value is already in the
// set, no action is taken.
// PARAMETERS: value - the value to insert
//==============================================================
template <typename T>
void Set<T>::insert(const T& value) {
    size_t index = hashFunction(value);
    for (const auto& element : table[index]) {
        if (element == value) {
            return;  // Value already exists, do nothing
        }
    }
    table[index].push_back(value);  // Add the value to the bucket
}

//==============================================================
// remove
// Removes a value from the set. If the value does not exist,
// throws an exception.
// PARAMETERS: value - the value to remove
//==============================================================
template <typename T>
void Set<T>::remove(const T& value) {
    size_t index = hashFunction(value);
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if (*it == value) {
            table[index].erase(it);  // Remove the value from the bucket
            return;
        }
    }
    throw std::runtime_error("Key not found in set");
}

//==============================================================
// search
// Checks if a value is in the set.
// PARAMETERS: value - the value to search for
// Return value: true if the value is in the set, false otherwise
//==============================================================
template <typename T>
bool Set<T>::search(const T& value) const {
    size_t index = hashFunction(value);
    for (const auto& element : table[index]) {
        if (element == value) {
            return true;  // Value found
        }
    }
    return false;  // Value not found
}

//==============================================================
// size
// Returns the number of elements in the set.
// PARAMETERS: None
// Return value: the number of elements in the set
//==============================================================
template <typename T>
size_t Set<T>::size() const {
    size_t count = 0;
    for (const auto& bucket : table) {
        count += bucket.size();
    }
    return count;
}

//==============================================================
// isEmpty
// Checks if the set is empty.
// PARAMETERS: None
// Return value: true if the set is empty, false otherwise
//==============================================================
template <typename T>
bool Set<T>::isEmpty() const {
    return size() == 0;
}

