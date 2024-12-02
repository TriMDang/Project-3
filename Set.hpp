#ifndef SET_HPP
#define SET_HPP

#include <vector>
#include <list>
#include <stdexcept>
#include <functional>

template <typename T>
class Set {
private:
    size_t table_size;                              // Number of buckets in the hash table
    std::vector<std::list<T>> table;               // Hash table as a vector of lists
    size_t hashFunction(const T& value) const;     // Computes the hash index for a given value

public:
    Set(size_t size = 100);                        // Constructor
    ~Set();                                        // Destructor

    void insert(const T& value);                   // Inserts a value into the set
    void remove(const T& value);                   // Removes a value from the set
    bool search(const T& value) const;             // Checks if a value is in the set

    size_t size() const;                           // Returns the number of elements in the set
    bool isEmpty() const;                          // Checks if the set is empty
};

#include "Set.cpp"
#endif
