//==============================================================
// Names: Aisha Barry
// Class: CS 271-01
// Date: 11/21/2024
// About: HashFunction.hpp contains the declaration for the
// HashFunction class, which implements the multiplication
// method for hashing keys using simple coding techniques.
//==============================================================

#ifndef HASHFUNCTION_HPP
#define HASHFUNCTION_HPP

class HashFunction {
private:
    long k;  // The constant k for the multiplication method
    long m;  // The number of buckets in the hash table

public:
    HashFunction(long constant_k, long table_size);  // Constructor
    ~HashFunction();  // Destructor
    HashFunction(const HashFunction& other);  // Copy constructor
    HashFunction& operator=(const HashFunction& other);  // Assignment operator

    int hash(long key) const;  // Compute hash index for a key
};

#endif // HASHFUNCTION_HPP
