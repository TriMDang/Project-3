#ifndef SET_HPP
#define SET_HPP

#include "HashMap.hpp"
#include <iostream>
#include <cstddef>

template <typename K, typename V>
class Set {
private:
public:
    HashMap<K, V> hash_set;
    Set(size_t size);
    ~Set();
    Set(const Set<K, V>& otherSet);
    Set<K, V>& operator= (const Set<K, V>& otherSet);

    void insert(const K& value);                   // Inserts a value into the set
    void remove(const K& value);                   // Removes a value from the set
    bool setSearch(const K& value) const;             // Checks if a value is in the set
};
#endif
