#ifndef SET_HPP
#define SET_HPP

#include <HashMap.hpp>
#include <iostream>


template <typename K, typename V>
class Set {
private:
    HashMap<K, V> hash_set;
public:
    
    void insert(const K& key);                   // Inserts a value into the set
    void remove(const K& key);                   // Removes a value from the set
    bool search(const K& key) const;             // Checks if a value is in the set
};
#endif
