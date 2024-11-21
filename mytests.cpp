//==============================================================
// Names: Aisha Barry, Tri Dang, Andrew Nguyen
// Class: CS 271-01
// Date: 11/07/2024
// About: mytests.cpp contains test cases for our classes
//==============================================================

#include <iostream>
#include <stdexcept>
#include <cassert>
#include "HashMap.hpp"

//==============================================================
// Test inserting and searching keys
// Ensures that keys can be inserted and then found in the map.
//==============================================================
void test_insert_and_search() {
    HashMap<int, std::string> hashMap;

    hashMap.insert(1, "One");
    hashMap.insert(2, "Two");
    hashMap.insert(3, "Three");

    assert(hashMap.search(1)->second == "One");
    assert(hashMap.search(2)->second == "Two");
    assert(hashMap.search(3)->second == "Three");

    std::cout << "test_insert_and_search passed." << std::endl;
}

//==============================================================
// Test updating values
// Ensures that inserting an existing key updates its value.
//==============================================================
void test_update_value() {
    HashMap<int, std::string> hashMap;

    hashMap.insert(1, "One");
    hashMap.insert(1, "Updated One");

    assert(hashMap.search(1)->second == "Updated One");

    std::cout << "test_update_value passed." << std::endl;
}

//==============================================================
// Test removing keys
// Ensures that keys can be removed and are no longer searchable.
//==============================================================
void test_remove_key() {
    HashMap<int, std::string> hashMap;

    hashMap.insert(1, "One");
    hashMap.remove(1);

    assert(hashMap.search(1) == nullptr);

    std::cout << "test_remove_key passed." << std::endl;
}

//==============================================================
// Test removing a non-existent key
// Ensures that removing a key that doesn't exist throws an exception.
//==============================================================
void test_remove_non_existent_key() {
    HashMap<int, std::string> hashMap;

    try {
        hashMap.remove(999);  // This key doesn't exist
        assert(false);  // Fail the test if no exception is thrown
    } catch (const std::runtime_error&) {
        // Exception expected
    }

    std::cout << "test_remove_non_existent_key passed." << std::endl;
}

//==============================================================
// Test operator[]
// Ensures that operator[] retrieves and sets values correctly.
//==============================================================
void test_operator_brackets() {
    HashMap<int, std::string> hashMap;

    hashMap[1] = "One";
    hashMap[2] = "Two";

    assert(hashMap[1] == "One");
    assert(hashMap[2] == "Two");

    hashMap[1] = "Updated One";
    assert(hashMap[1] == "Updated One");

    std::cout << "test_operator_brackets passed." << std::endl;
}

//==============================================================
// Test searching in an empty hash map
// Ensures that searching in an empty hash map returns nullptr.
//==============================================================
void test_empty_hash_map_search() {
    HashMap<int, std::string> hashMap;

    assert(hashMap.search(1) == nullptr);

    std::cout << "test_empty_hash_map_search passed." << std::endl;
}

//==============================================================
// Test collision handling
// Ensures that the hash map handles collisions correctly.
//==============================================================
void test_collision_handling() {
    HashMap<int, std::string> hashMap(1);  // Force all keys to collide

    hashMap.insert(1, "One");
    hashMap.insert(2, "Two");

    assert(hashMap.search(1)->second == "One");
    assert(hashMap.search(2)->second == "Two");

    std::cout << "test_collision_handling passed." << std::endl;
}

//==============================================================
// Main function
// Runs all test cases
//==============================================================
int main() {
    test_insert_and_search();
    test_update_value();
    test_remove_key();
    test_remove_non_existent_key();
    test_operator_brackets();
    test_empty_hash_map_search();
    test_collision_handling();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
