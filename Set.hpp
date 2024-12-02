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
    Set();
    ~Set();
    Set(const Set<K, V>& otherSet);
    Set<K, V>& operator= (const Set<K, V>& otherSet);

    void insert(const K& key);                   // Inserts a value into the set
    void remove(const K& key);                   // Removes a value from the set
    bool search(const K& key) const;             // Checks if a value is in the set
};
#endif
