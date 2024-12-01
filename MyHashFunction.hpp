//==============================================================
// Names: Aisha Barry, Tri Dang, Andre Nguyen
// Class: CS 271-01
// Date: 11/21/2024
// About: HashMap.hpp contains the declarations for the
// MyHashFunction
//==============================================================

#ifndef MyHashFunction_HPP
#define MyHashFunction_HPP

#include <type_traits>  // For type traits

template <typename K>
class MyHashFunction {
private:
    long k;  // The constant k for the multiplication method
    long m;  // The number of buckets in the hash table

    // Static assertion to ensure K is numeric
    static_assert(std::is_arithmetic<K>::value, "Key type must be numeric");

public:
    // Constructor
    MyHashFunction(long constant_k, long table_size);

    // Destructor
    ~MyHashFunction();

    // Copy constructor
    MyHashFunction(const MyHashFunction<K>& other);

    // Assignment operator
    MyHashFunction<K>& operator=(const MyHashFunction<K>& other);

    // Compute hash index for a key
    int getHash(const K& key) const;
};

// Include the implementation

#endif

