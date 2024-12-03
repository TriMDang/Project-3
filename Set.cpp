#include <iostream>
#include "Set.hpp"
#include "customexceptions.hpp"
using namespace std;

// ============================================================
// Default Constructor.
// Creates a hashSet with table_size 0
// Parameter: None.
// Return: None.
// ============================================================
template <class T>
    Set<T>::Set(size_t table_size) : hashSet(table_size) {}

// ============================================================
// Copy Constructor.
// Creates a hashSet and deep copies the other hashSet
// Parameter:
//  - other: The Set object to copy from.
// Return: None.
// ============================================================
template <class T>
    Set<T>::Set(const Set<T> &other) {
        hashSet(other.hashSet);
    }

// ============================================================
// Destructor.
// Deallocate a set, deleting it
// Parameter: None.
// Return: None.
// ============================================================
template <class T>
    Set<T>::~Set() {
    }

// ============================================================
// operator=
// Assign hashSet to other's hashSet using hashSet.cpp operator=
// Parameter: the other set
// Return: the set being called
// ============================================================
template <class T>
    Set<T> Set<T>::operator=(const Set<T> &other) {
        if (this != &other) {
            hashSet = other.hashSet;
            // tableSize = other.tableSize;
        }
        return (*this);
    }

// ============================================================
// Insert Method.
// Inserts a value into the set, throw exception error if value existed
// Parameter: value - The value to insert.
// Return: None.
// ============================================================
template <class T>
    void Set<T>::insert(const T &value) {
        if (search(value) == true){
            throw valueExisted();
        } else{
            hashSet.insert(value, value); // key can be the value since value must be unique
        }
    }

// ============================================================
// Remove Method.
// Removes a value from the set, throw exception error if value is nonexistent
// Parameter: value - The value to remove.
// Return: None.
// ============================================================
template <class T>
    void Set<T>::remove(const T& value) {
        if (search(value) == true){
            hashSet.remove(value);
        } else{
            throw ValueNotInTreeException();
        }
    }

// ============================================================
// Search Method.
// Searches for a value in the set.
// Parameter: valueHashMap
// Return: True if value exist, oterwise false.
// ============================================================
template <class T>
    bool Set<T>::search(const T& value) {
        return hashSet.search(value) != nullptr;
    }