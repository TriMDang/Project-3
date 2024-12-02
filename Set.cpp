#include "Set.hpp"
#include <iostream>
#include "customexceptions.hpp"
#include <cstddef>



//==============================================================
// Default Constructor
// Author: Tri Dang
// Description: Initializes an empty Red-Black Tree.
//==============================================================
template <typename K, typename V>
Set<K, V>::Set(size_t size) : hash_set(size) {
}


//==============================================================
// Copy Constructor
// Author: Tri Dang
// Description: Initializes an empty Red-Black Tree.
//==============================================================
template <typename K, typename V>
Set<K, V>::Set(const Set<K, V>& otherSet){
    hash_set = otherSet.hash_set;
}

//==============================================================
// Destructor
// Author: Tri Dang
// Description: Initializes an empty Red-Black Tree.
//==============================================================
template <typename K, typename V>
Set<K, V>::~Set(){
}

//==============================================================
// Operator=
// Author: Tri Dang
// Description: Initializes an empty Red-Black Tree.
//==============================================================
template <typename K, typename V>
Set<K, V>& Set<K, V>::operator=(const Set<K, V>& otherSet){
    hash_set = otherSet.hash_set;
    return *this;
}

//==============================================================
// Search
// Author: Tri Dang
// Description: Searches through the hash table to find the value. Return true if value do exist
//==============================================================
template <typename K, typename V>
bool Set<K, V>::setSearch(const K& value) const{
    if (hash_set.search(value) != nullptr){
        return true;
    } else{
        return false;
    }
}

//==============================================================
// Insert
// Author: Tri Dang
// Description: Throw error if value existed. Otherwise, insert it into hash_set
//==============================================================
template <typename K, typename V>
void Set<K, V>::insert(const K& value){
    if (setSearch(value) == true){ // if value DOES exist
        throw ValueExisted();
    } else{
        hash_set.insert(value, value); // Since a value in a set is UNIQUE, the value can also be its key 
    }
}
//==============================================================
// Remove
// Author: Tri Dang
// Description: Throw error if value does not exist. Otherwise, delete it.
//==============================================================
template <typename K, typename V>
void Set<K, V>::remove(const K& value){
    if (setSearch(value) == true){ // if value does exist
        hash_set.remove(value);
    } else{
        throw ValueNotInTreeException();
    }
}
