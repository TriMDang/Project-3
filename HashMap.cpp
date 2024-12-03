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
HashMap<K, V>::HashMap(size_t size) : table_size(size), num_elements(0), hash_function(size) {
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
    for (size_t i = 0; i < table_size; i++) {
        Node<K, V>* current = table[i];
        while (current != nullptr) {
            Node<K, V>* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] table;
}

//==============================================================
// HashMap
// Copy constructor for HashMap. Creates a deep copy of an existing
// HashMap, copying all nodes and their key-value pairs to the new
// HashMap instance.
// PARAMETERS:
// - other : const reference to the HashMap<K, V> to copy
// RETURN VALUE:
// - None
//==============================================================
template <typename K, typename V>
HashMap<K, V>::HashMap(const HashMap<K, V>& other)
    : table_size(other.table_size), num_elements(other.num_elements), hash_function(other.hash_function) {
    table = new Node<K, V>*[table_size]();
    for (size_t i = 0; i < table_size; ++i) {
        if (other.table[i] != nullptr) {
            Node<K, V>* other_current = other.table[i];
            Node<K, V>** this_current = &table[i];
            while (other_current != nullptr) {
                *this_current = new Node<K, V>(other_current->data.first, other_current->data.second);
                if (other_current->next) {
                    (*this_current)->next = nullptr;
                }
                this_current = &((*this_current)->next);
                other_current = other_current->next;
            }
        }
    }
}

//==============================================================
// operator=
// Overloaded assignment operator that creates a deep copy of the given
// HashMap, first destructing the current instance and then copying the
// data from the other HashMap.
// PARAMETERS:
// - other : const reference to the HashMap<K, V> to assign
// RETURN VALUE:
// - HashMap<K, V>& : Reference to the updated HashMap object
//==============================================================
template <typename K, typename V>
HashMap<K, V>& HashMap<K, V>::operator=(const HashMap<K, V>& other) {
    this->~HashMap(); //destruct

    table_size = other.table_size;
    num_elements = other.num_elements;
    hash_function = other.hash_function;

    table = new Node<K, V>*[table_size]();
    for (size_t i = 0; i < table_size; ++i) {
        if (other.table[i] != nullptr) {
            Node<K, V>* other_current = other.table[i];
            Node<K, V>** this_current = &table[i];
            while (other_current != nullptr) {
                *this_current = new Node<K, V>(other_current->data.first, other_current->data.second);
                if (other_current->next) {
                    (*this_current)->next = nullptr;
                }
                this_current = &((*this_current)->next);
                other_current = other_current->next;
            }
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

    // Check if the key already exists
    while (current != nullptr) {
        if (current->data.first == key) {  // Key found
            current->data.second = value;  // Update value
            return;
        }
        current = current->next;
    }

    // Key not found; insert at the beginning of the list
    Node<K, V>* newNode = new Node<K, V>();
    newNode->data = make_pair(key, value);
    newNode->next = table[index];
    newNode->prev = nullptr;

    if (table[index] != nullptr) {
        table[index]->prev = newNode;  // Update the previous head's prev pointer
    }
    table[index] = newNode;  // Set the new node as the head of the list
    ++num_elements;
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

    while (current != nullptr) {
        if (current->data.first == key) {  // Key found
            if (current->prev != nullptr) {
                current->prev->next = current->next;  // Update previous node's next
            } else {
                table[index] = current->next;  // Update head if needed
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;  // Update next node's prev
            }
            delete current;
            --num_elements;
            return;
        }
        current = current->next;
    }

    throw key_exception();
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
    int index = hash_function.getHash(key);
    Node<K, V>* current = table[index];

    while (current != nullptr) {
        if (current->data.first == key) {
            return current->data.second;  // Return the value if key exists
        }
        current = current->next;
    }
    throw key_exception();
}


//==============================================================
// search
// Searches for a key-value pair in the hash map.
// PARAMETERS: key - the key to search for
// Return value: a pointer to the key-value pair, or nullptr if
//               the key is not found
//==============================================================
template <typename K, typename V>
Node<K, V>* HashMap<K, V>::search(const K& key) {
    int index = hash_function.getHash(key);  // Use the hash function instance
    Node<K, V>* current = table[index];

    while (current != nullptr) {
        if (current->data.first == key) {  // Match the key part of the pair
            return current;
        }
        current = current->next;
    }

    return nullptr;  // Key not found
}
