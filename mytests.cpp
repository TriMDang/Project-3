//==============================================================
// Names: Aisha Barry, Tri Dang, Andrew Nguyen
// Class: CS 271-01
// Date: 11/07/2024
// About: mytests.cpp contains test cases for our classes
//==============================================================

#include <iostream>
#include <stdexcept>
#include <cassert>
#include "HashMap.cpp"
using namespace std;

//==============================================================
// Test inserting and searching keys
// Ensures that keys can be inserted and then found in the map.
//==============================================================
void test_insert_and_search() {
    HashMap<int, std::string> hashMap(10);  // Provide the size argument

    cout << "Testing insert and search...\n";
    hashMap.insert(1, "One");
    hashMap.insert(2, "Two");
    hashMap.insert(3, "Three");

    cout << "Inserted values:\n";
    cout << "Key 1: " << hashMap.search(1)->value << "\n";
    cout << "Key 2: " << hashMap.search(2)->value << "\n";
    cout << "Key 3: " << hashMap.search(3)->value << "\n";

    assert(hashMap.search(1)->value == "One");
    assert(hashMap.search(2)->value == "Two");
    assert(hashMap.search(3)->value == "Three");

    cout << "test_insert_and_search passed.\n\n";
}

//==============================================================
// Test updating values
// Ensures that inserting an existing key updates its value.
//==============================================================
void test_update_value() {
    HashMap<int, std::string> hashMap(10);  // Provide the size argument

    cout << "Testing update values...\n";
    hashMap.insert(1, "One");
    cout << "Before update: Key 1 = " << hashMap.search(1)->value << "\n";

    hashMap.insert(1, "Updated One");
    cout << "After update: Key 1 = " << hashMap.search(1)->value << "\n";

    assert(hashMap.search(1)->value == "Updated One");

    cout << "test_update_value passed.\n\n";
}

//==============================================================
// Test removing keys
// Ensures that keys can be removed and are no longer searchable.
//==============================================================
void test_remove_key() {
    HashMap<int, std::string> hashMap(10);  // Provide the size argument

    cout << "Testing remove key...\n";
    hashMap.insert(1, "One");
    cout << "Before removal: Key 1 = " << hashMap.search(1)->value << "\n";

    hashMap.remove(1);
    cout << "After removal: Key 1 = " << (hashMap.search(1) == nullptr ? "nullptr" : hashMap.search(1)->value) << "\n";

    assert(hashMap.search(1) == nullptr);

    cout << "test_remove_key passed.\n\n";
}

//==============================================================
// Test removing a non-existent key
// Ensures that removing a key that doesn't exist throws an exception.
//==============================================================
void test_remove_non_existent_key() {
    HashMap<int, std::string> hashMap(10);  // Provide the size argument

    cout << "Testing remove non-existent key...\n";

    try {
        hashMap.remove(999);  // This key doesn't exist
        assert(false);  // Fail the test if no exception is thrown
    } catch (const std::runtime_error& e) {
        cout << "Caught expected exception: " << e.what() << "\n";
    }

    cout << "test_remove_non_existent_key passed.\n\n";
}

//==============================================================
// Test operator[]
// Ensures that operator[] retrieves and sets values correctly.
//==============================================================
void test_operator_brackets() {
    HashMap<int, std::string> hashMap(10);  // Provide the size argument

    cout << "Testing operator[]...\n";
    hashMap[1] = "One";
    hashMap[2] = "Two";

    cout << "Set values: \n";
    cout << "Key 1: " << hashMap[1] << "\n";
    cout << "Key 2: " << hashMap[2] << "\n";

    hashMap[1] = "Updated One";
    cout << "After update: Key 1 = " << hashMap[1] << "\n";

    assert(hashMap[1] == "Updated One");
    assert(hashMap[2] == "Two");

    cout << "test_operator_brackets passed.\n\n";
}

//==============================================================
// Test searching in an empty hash map
// Ensures that searching in an empty hash map returns nullptr.
//==============================================================
void test_empty_hash_map_search() {
    HashMap<int, std::string> hashMap(10);  // Provide the size argument

    cout << "Testing empty hash map search...\n";
    cout << "Search Key 1: " << (hashMap.search(1) == nullptr ? "nullptr" : hashMap.search(1)->value) << "\n";

    assert(hashMap.search(1) == nullptr);

    cout << "test_empty_hash_map_search passed.\n\n";
}

//==============================================================
// Test collision handling
// Ensures that the hash map handles collisions correctly.
//==============================================================
void test_collision_handling() {
    HashMap<int, std::string> hashMap(1);  // Force all keys to collide

    cout << "Testing collision handling...\n";
    hashMap.insert(1, "One");
    hashMap.insert(2, "Two");

    cout << "Colliding keys:\n";
    cout << "Key 1: " << hashMap.search(1)->value << "\n";
    cout << "Key 2: " << hashMap.search(2)->value << "\n";

    assert(hashMap.search(1)->value == "One");
    assert(hashMap.search(2)->value == "Two");

    cout << "test_collision_handling passed.\n\n";
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

    cout << "All Hash Map tests passed!\n";
    cout << "Initializing Set (HashMap) tests..." << endl;



    return 0;
}
