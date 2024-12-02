//==============================================================
// Names: Aisha Barry
// Class: CS 271-01
// Date: 11/21/2024
// About: HashMap.cpp contains the implementations for the
// HashMap class, handling insertion, deletion, searching, and
// retrieval using chaining and the multiplication method for hashing keys.
//==============================================================

#include "HashMap.hpp"
#include <stdexcept>
#include "customexceptions.hpp"
using namespace std;

//==============================================================
// Constructor
// Constructs a hash map with a specified number of buckets.
// PARAMETERS: size - the number of buckets in the hash table
//==============================================================
template <typename K, typename V>
HashMap<K, V>::HashMap(size_t size) : table_size(size), hash_function(26544, size) {
    table = new Node<K, V>*[table_size];
    for (size_t i = 0; i < table_size; i++) {
        table[i] = nullptr;  // Initialize all buckets to null
    }
}

//==============================================================
// Destructor
// Destructor that clears and deallocates the hash table.
//==============================================================
template <typename K, typename V>
HashMap<K, V>::~HashMap() {
    clear();
    delete[] table;
}


//==============================================================
// Copy Constructor
// Author: Tri Dang
// Creates a new hash table and deep copies another another table.
//==============================================================
template <typename K, typename V>
HashMap<K, V>::HashMap(const HashMap<K, V>& otherMap){
    hash_function = otherMap.hash_function;
    for (size_t i = 0; i < otherMap.table_size; ++i) {
        Node<K, V>* current = otherMap.table[i];
        while (current != nullptr) {
            insert(current->key, current->value);
            current = current->next;
        }
    }
}

//==============================================================
// Operator = 
// Author: Tri Dang
// Deep copies another hash table.
//==============================================================
template <typename K, typename V>
HashMap<K, V>& HashMap<K, V>::operator=(const HashMap<K, V>& otherMap){
    if (this == &otherMap) {
        return *this;  // prevent self reassignment
    }
    clear(); 
    hash_function = otherMap.hash_function;

    for (size_t i = 0; i < otherMap.table_size; ++i) {
        Node<K, V>* current = otherMap.table[i];
        while (current != nullptr) {
            insert(current->key, current->value);
            current = current->next;
        }
    }
    return *this;
}


//==============================================================
// insert
// Inserts a key-value pair into the hash map. If the key
// already exists, its value is updated.
// PARAMETERS: key - the key to insert
//             value - the value to associate with the key
//==============================================================
template <typename K, typename V>
void HashMap<K, V>::insert(const K& key, const V& value) {
    int index = hash_function.getHash(key);  // Use the hash function instance
    Node<K, V>* current = table[index];

    while (current != nullptr) {
        if (current->key == key) {  // Key already exists
            current->value = value;  // Update value
            return;
        }
        current = current->next;
    }

    // Key not found; insert at the beginning of the list
    Node<K, V>* newNode = new Node<K, V>();
    newNode->key = key;
    newNode->value = value;
    newNode->next = table[index];
    table[index] = newNode;
}

//==============================================================
// remove
// Removes a key-value pair from the hash map.
// PARAMETERS: key - the key to remove
//==============================================================
template <typename K, typename V>
void HashMap<K, V>::remove(const K& key) {
    int index = hash_function.getHash(key);  // Use the hash function instance
    Node<K, V>* current = table[index];
    Node<K, V>* prev = nullptr;

    while (current != nullptr) {
        if (current->key == key) {
            if (prev == nullptr) {  // Node to remove is the head
                table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }

    throw ValueNotInTreeException();
}

//==============================================================
// operator[]
// Retrieves or modifies the value associated with a key. If
// the key does not exist, a new entry is created.
// PARAMETERS: key - the key to retrieve or modify
// Return value: a reference to the associated value
//==============================================================
template <typename K, typename V>
V& HashMap<K, V>::operator[](const K& key) {
    int index = hash_function.getHash(key);  // Use the hash function instance
    Node<K, V>* current = table[index];

    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }

    // Key not found; insert with default value
    Node<K, V>* newNode = new Node<K, V>();
    newNode->key = key;
    newNode->value = V();  // Default value
    newNode->next = table[index];
    table[index] = newNode;
    return table[index]->value;
}

//==============================================================
// search
// Searches for a key-value pair in the hash map.
// PARAMETERS: key - the key to search for
// Return value: a pointer to the key-value pair, or nullptr if
//               the key is not found
//==============================================================
template <typename K, typename V>
Node<K, V>* HashMap<K, V>::search(const K& key) const {
    int index = hash_function.getHash(key);  // Use the hash function instance
    Node<K, V>* current = table[index];

    while (current != nullptr) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }

    return nullptr;  // Key not found
}

//==============================================================
// clear
// Deletes everything in this table
// Parameter: none in parenthesis, but the table itself calls it
// Return: none
//==============================================================
template <typename K, typename V>
void HashMap<K, V>::clear(){
    for (size_t i = 0; i < table_size; i++) {
        Node<K, V>* current = table[i];
        while (current != nullptr) {
            Node<K, V>* temp = current;
            current = current->next;
            delete temp;
        }
        table[i] = nullptr;
    }
    table_size = 0;
}