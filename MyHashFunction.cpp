#include "MyHashFunction.hpp"
#include <random>
using namespace std;

//==============================================================
// Constructor
// Initializes the hash function with a constant k and table size m.
// PARAMETERS:
// - constant_k: the constant k for the multiplication method
// - table_size: the number of buckets (m)
//==============================================================
template <typename K>
MyHashFunction<K>::MyHashFunction(size_t table_size) {
    // Generate a random double in the range [0, 1)
    random_device rd;                                // Seed
    mt19937 generator(rd());                        // Random number engine
    uniform_real_distribution<double> dist(0.0, 1.0); // Distribution range [0, 1)
    k = dist(generator);                                 // Assign random k
}

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
    static_assert(is_arithmetic<K>::value, "Key type must be numeric");
    double product = key * k;                            // Multiply key by k
    double fractional_part = product - static_cast<long>(product); // Extract fractional part
    return static_cast<int>(m * fractional_part);        // Scale to table size
}
