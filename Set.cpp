#include "Set.hpp"
#include <iostream>
#include "customexceptions.hpp"



//==============================================================
// Default Constructor
// Author: Tri Dang
// Description: Initializes an empty Red-Black Tree.
//==============================================================


//==============================================================
// Copy Constructor
// Author: Tri Dang
// Description: Initializes an empty Red-Black Tree.
//==============================================================


//==============================================================
// Destructor
// Author: Tri Dang
// Description: Initializes an empty Red-Black Tree.
//==============================================================


//==============================================================
// Operator=
// Author: Tri Dang
// Description: Initializes an empty Red-Black Tree.
//==============================================================


//==============================================================
// Search
// Author: Tri Dang
// Description: Searches through the hash table to find the value. Return true if value do exist
//==============================================================
template <typename K, typename V>
bool Set<K, V>::search(const K& key){
    if (hash_set.search(key) != nullptr){
        return (true);
    } else{
        return (false);
    }
}

//==============================================================
// Insert
// Author: Tri Dang
// Description: Throw error if value existed. Otherwise, insert it into hash_set
//==============================================================
template <typename K, typename V>
void Set<K, V>::insert(const K& key){
    if (hash_set.search(key) != nullptr){
        throw ValueExisted();
    } else{
        hash_set.insert(key);
    }
}
//==============================================================
// Remove
// Author: Tri Dang
// Description: Throw error if value does not exist. Otherwise, delete it.
//==============================================================
template <typename K, typename V>
void Set<K, V>::remove(const K& key){
    if (hash_set.search(key) != nullptr){
        hash_set.remove(key);
    } else{
        throw ValueNotInTreeException();
    }
}
