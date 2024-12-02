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
#include "HashMapTree.cpp"

//==============================================================
// Test inserting and searching keys
// Ensures that keys can be inserted and then found in the map.
//==============================================================
void test_insert_and_search() {
    HashMap<int, std::string> hashMap(10);  // Provide the size argument

    std::cout << "Testing insert and search...\n";
    hashMap.insert(1, "One");
    hashMap.insert(2, "Two");
    hashMap.insert(3, "Three");

    std::cout << "Inserted values:\n";
    std::cout << "Key 1: " << hashMap.search(1)->value << "\n";
    std::cout << "Key 2: " << hashMap.search(2)->value << "\n";
    std::cout << "Key 3: " << hashMap.search(3)->value << "\n";

    assert(hashMap.search(1)->value == "One");
    assert(hashMap.search(2)->value == "Two");
    assert(hashMap.search(3)->value == "Three");

    std::cout << "test_insert_and_search passed.\n\n";
}

//==============================================================
// Test updating values
// Ensures that inserting an existing key updates its value.
//==============================================================
void test_update_value() {
    HashMap<int, std::string> hashMap(10);  // Provide the size argument

    std::cout << "Testing update values...\n";
    hashMap.insert(1, "One");
    std::cout << "Before update: Key 1 = " << hashMap.search(1)->value << "\n";

    hashMap.insert(1, "Updated One");
    std::cout << "After update: Key 1 = " << hashMap.search(1)->value << "\n";

    assert(hashMap.search(1)->value == "Updated One");

    std::cout << "test_update_value passed.\n\n";
}

//==============================================================
// Test removing keys
// Ensures that keys can be removed and are no longer searchable.
//==============================================================
void test_remove_key() {
    HashMap<int, std::string> hashMap(10);  // Provide the size argument

    std::cout << "Testing remove key...\n";
    hashMap.insert(1, "One");
    std::cout << "Before removal: Key 1 = " << hashMap.search(1)->value << "\n";

    hashMap.remove(1);
    std::cout << "After removal: Key 1 = " << (hashMap.search(1) == nullptr ? "nullptr" : hashMap.search(1)->value) << "\n";

    assert(hashMap.search(1) == nullptr);

    std::cout << "test_remove_key passed.\n\n";
}

//==============================================================
// Test removing a non-existent key
// Ensures that removing a key that doesn't exist throws an exception.
//==============================================================
void test_remove_non_existent_key() {
    HashMap<int, std::string> hashMap(10);  // Provide the size argument

    std::cout << "Testing remove non-existent key...\n";

    try {
        hashMap.remove(999);  // This key doesn't exist
        assert(false);  // Fail the test if no exception is thrown
    } catch (const std::runtime_error& e) {
        std::cout << "Caught expected exception: " << e.what() << "\n";
    }

    std::cout << "test_remove_non_existent_key passed.\n\n";
}

//==============================================================
// Test operator[]
// Ensures that operator[] retrieves and sets values correctly.
//==============================================================
void test_operator_brackets() {
    HashMap<int, std::string> hashMap(10);  // Provide the size argument

    std::cout << "Testing operator[]...\n";
    hashMap[1] = "One";
    hashMap[2] = "Two";

    std::cout << "Set values: \n";
    std::cout << "Key 1: " << hashMap[1] << "\n";
    std::cout << "Key 2: " << hashMap[2] << "\n";

    hashMap[1] = "Updated One";
    std::cout << "After update: Key 1 = " << hashMap[1] << "\n";

    assert(hashMap[1] == "Updated One");
    assert(hashMap[2] == "Two");

    std::cout << "test_operator_brackets passed.\n\n";
}

//==============================================================
// Test searching in an empty hash map
// Ensures that searching in an empty hash map returns nullptr.
//==============================================================
void test_empty_hash_map_search() {
    HashMap<int, std::string> hashMap(10);  // Provide the size argument

    std::cout << "Testing empty hash map search...\n";
    std::cout << "Search Key 1: " << (hashMap.search(1) == nullptr ? "nullptr" : hashMap.search(1)->value) << "\n";

    assert(hashMap.search(1) == nullptr);

    std::cout << "test_empty_hash_map_search passed.\n\n";
}

//==============================================================
// Test collision handling
// Ensures that the hash map handles collisions correctly.
//==============================================================
void test_collision_handling() {
    HashMap<int, std::string> hashMap(1);  // Force all keys to collide

    std::cout << "Testing collision handling...\n";
    hashMap.insert(1, "One");
    hashMap.insert(2, "Two");

    std::cout << "Colliding keys:\n";
    std::cout << "Key 1: " << hashMap.search(1)->value << "\n";
    std::cout << "Key 2: " << hashMap.search(2)->value << "\n";

    assert(hashMap.search(1)->value == "One");
    assert(hashMap.search(2)->value == "Two");

    std::cout << "test_collision_handling passed.\n\n";
}

//==============================================================
// Test inserting and searching keys in HashMapTree
//==============================================================
void test_insert_and_search_HashMapTree() {
    HashMapTree<int, std::string> hashMapTree(10);

    std::cout << "Testing insert and search in HashMapTree...\n";
    hashMapTree.insert(1, "One");
    hashMapTree.insert(2, "Two");
    hashMapTree.insert(3, "Three");

    std::cout << "Inserted values:\n";
    std::cout << "Key 1: " << hashMapTree.search(1)->data.second << "\n";
    std::cout << "Key 2: " << hashMapTree.search(2)->data.second << "\n";
    std::cout << "Key 3: " << hashMapTree.search(3)->data.second << "\n";

    assert(hashMapTree.search(1)->data.second == "One");
    assert(hashMapTree.search(2)->data.second == "Two");
    assert(hashMapTree.search(3)->data.second == "Three");

    std::cout << "test_insert_and_search_HashMapTree passed.\n\n";
}


//==============================================================
// Test updating values in HashMapTree
//==============================================================
void test_update_value_HashMapTree() {
    HashMapTree<int, std::string> hashMapTree(10);

    std::cout << "Testing update values in HashMapTree...\n";
    hashMapTree.insert(1, "One");
    std::cout << "Before update: Key 1 = " << hashMapTree.search(1)->data.second << "\n";

    hashMapTree.insert(1, "Updated One");
    std::cout << "After update: Key 1 = " << hashMapTree.search(1)->data.second << "\n";

    assert(hashMapTree.search(1)->data.second == "Updated One");

    std::cout << "test_update_value_HashMapTree passed.\n\n";
}

//==============================================================
// Test removing keys in HashMapTree
//==============================================================
void test_remove_key_HashMapTree() {
    HashMapTree<int, std::string> hashMapTree(10);

    std::cout << "Testing remove key in HashMapTree...\n";
    hashMapTree.insert(1, "One");
    std::cout << "Before removal: Key 1 = " << hashMapTree.search(1)->data.second << "\n";

    hashMapTree.remove(hashMapTree.search(1));
    std::cout << "After removal: Key 1 = " << (hashMapTree.search(1) == nullptr ? "nullptr" : hashMapTree.search(1)->data.second) << "\n";

    assert(hashMapTree.search(1) == nullptr);

    std::cout << "test_remove_key_HashMapTree passed.\n\n";
}

//==============================================================
// Test removing a non-existent key in HashMapTree
//==============================================================
void test_remove_non_existent_key_HashMapTree() {
    HashMapTree<int, std::string> hashMapTree(10);

    std::cout << "Testing remove non-existent key in HashMapTree...\n";

    try {
        hashMapTree.remove(hashMapTree.search(999));  // This key doesn't exist
        assert(false);  // Fail the test if no exception is thrown
    } catch (const std::runtime_error& e) {
        std::cout << "Caught expected exception: " << e.what() << "\n";
    }

    std::cout << "test_remove_non_existent_key_HashMapTree passed.\n\n";
}

//==============================================================
// Test operator[] in HashMapTree
//==============================================================
void test_operator_brackets_HashMapTree() {
    HashMapTree<int, std::string> hashMapTree(10);

    std::cout << "Testing operator[] in HashMapTree...\n";
    hashMapTree[1] = "One";
    hashMapTree[2] = "Two";

    std::cout << "Set values:\n";
    std::cout << "Key 1: " << hashMapTree[1] << "\n";
    std::cout << "Key 2: " << hashMapTree[2] << "\n";

    hashMapTree[1] = "Updated One";
    std::cout << "After update: Key 1 = " << hashMapTree[1] << "\n";

    assert(hashMapTree[1] == "Updated One");
    assert(hashMapTree[2] == "Two");

    std::cout << "test_operator_brackets_HashMapTree passed.\n\n";
}

//==============================================================
// Test searching in an empty HashMapTree
//==============================================================
void test_empty_HashMapTree_search() {
    HashMapTree<int, std::string> hashMapTree(10);

    std::cout << "Testing empty HashMapTree search...\n";
    std::cout << "Search Key 1: " << (hashMapTree.search(1) == nullptr ? "nullptr" : hashMapTree.search(1)->data.second) << "\n";

    assert(hashMapTree.search(1) == nullptr);

    std::cout << "test_empty_HashMapTree_search passed.\n\n";
}

//==============================================================
// Test collision handling in HashMapTree
//==============================================================
void test_collision_handling_HashMapTree() {
    HashMapTree<int, std::string> hashMapTree(1);  // Force all keys to collide

    std::cout << "Testing collision handling in HashMapTree...\n";
    hashMapTree.insert(1, "One");
    hashMapTree.insert(2, "Two");

    std::cout << "Colliding keys:\n";
    std::cout << "Key 1: " << hashMapTree.search(1)->data.second << "\n";
    std::cout << "Key 2: " << hashMapTree.search(2)->data.second << "\n";

    assert(hashMapTree.search(1)->data.second == "One");
    assert(hashMapTree.search(2)->data.second == "Two");

    std::cout << "test_collision_handling_HashMapTree passed.\n\n";
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

    std::cout << "All tests passed!\n";

    test_insert_and_search_HashMapTree();
    test_update_value_HashMapTree();
    test_remove_key_HashMapTree();
    test_remove_non_existent_key_HashMapTree();
    test_operator_brackets_HashMapTree();
    test_empty_HashMapTree_search();
    test_collision_handling_HashMapTree();

    std::cout << "All tests for HashMapTree passed!\n";
    return 0;
}
