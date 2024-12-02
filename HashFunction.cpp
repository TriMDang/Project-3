//==============================================================
// Names: Aisha Barry
// Class: CS 271-01
// Date: 11/21/2024
// About: HashFunction.cpp contains the implementation for the
// HashFunction class, which implements the multiplication
// method for hashing keys.
//==============================================================

#include "HashFunction.hpp"

//==============================================================
// Constructor
// Initializes the hash function with a constant k and table size m.
// PARAMETERS: constant_k - the constant k for the multiplication method
//             table_size - the number of buckets (m)
//==============================================================
HashFunction::HashFunction(long constant_k, long table_size)
    : k(constant_k), m(table_size) {}

//==============================================================
// Destructor
// Cleans up the hash function by resetting k and m.
//==============================================================
HashFunction::~HashFunction() {
    k = 0;
    m = 0;
}

//==============================================================
// Copy constructor
// Copies the values of k and m from another hash function.
// PARAMETERS: other - the HashFunction to copy
//==============================================================
HashFunction::HashFunction(const HashFunction& other)
    : k(other.k), m(other.m) {}

//==============================================================
// Operator=
// Copies the values of k and m from another hash function.
// PARAMETERS: other - the HashFunction to copy
//==============================================================
HashFunction& HashFunction::operator=(const HashFunction& other) {
    if (this != &other) {
        k = other.k;
        m = other.m;
    }
    return *this;
}

//==============================================================
// Hash
// Computes the hash index for a given key using the multiplication method.
// PARAMETERS: key - the key to hash
// Return value: the computed hash index
//==============================================================
int HashFunction::hash(long key) const {
    double product = key * (k / 100000.0);  // Scale k to simulate a constant < 1
    double fractional_part = product - static_cast<long>(product);  // kA mod 1
    return static_cast<int>(m * fractional_part);  // Multiply by m and truncate
}
