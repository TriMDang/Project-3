#include "MyHashFunction.hpp"

//==============================================================
// Constructor
// Initializes the hash function with a constant k and table size m.
// PARAMETERS:
// - constant_k: the constant k for the multiplication method
// - table_size: the number of buckets (m)
//==============================================================
template <typename K>
MyHashFunction<K>::MyHashFunction(long constant_k, size_t table_size)
    : k(constant_k), m(table_size) {}

//==============================================================
// Destructor
// Cleans up the hash function by resetting k and m.
//==============================================================
template <typename K>
MyHashFunction<K>::~MyHashFunction() {
    k = 0;
    m = 0;
}

//==============================================================
// Copy Constructor
// Copies the values of k and m from another hash function.
// PARAMETERS:
// - other: the MyHashFunction to copy
//==============================================================
template <typename K>
MyHashFunction<K>::MyHashFunction(const MyHashFunction<K>& other)
    : k(other.k), m(other.m) {}

//==============================================================
// Assignment Operator
// Copies the values of k and m from another hash function.
// PARAMETERS:
// - other: the MyHashFunction to copy
//==============================================================
template <typename K>
MyHashFunction<K>& MyHashFunction<K>::operator=(const MyHashFunction<K>& other) {
    if (this != &other) {
        k = other.k;
        m = other.m;
    }
    return *this;
}

//==============================================================
// Hash
// Computes the hash index for a given key using the multiplication method.
// PARAMETERS:
// - key: the key to hash
// Return value:
// - the computed hash index
//==============================================================
template <typename K>
int MyHashFunction<K>::getHash(const K& key) const {
    static_assert(std::is_arithmetic<K>::value, "Key type must be numeric");
    double product = key * (k / 100000.0);  // Scale k to simulate a constant < 1
    double fractional_part = product - static_cast<long>(product);  // Extract fractional part
    return static_cast<int>(m * fractional_part);  // Multiply by m and truncate
}