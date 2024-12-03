//==============================================================
// Names: Aisha Barry, Tri Dang, Andrew Nguyen
// Class: CS 271-01
// Date: 11/07/2024
// About: mytests.cpp contains test cases for our classes
//==============================================================

#include <iostream>
#include <stdexcept>
#include <cassert>
//#include "HashMap.cpp"
#include "HashMapTree.cpp"
#include "Set.cpp"
using namespace std;

//==============================================================
// Test inserting and searching keys
// Ensures that keys can be inserted and then found in the map.
//==============================================================
void test_insert_and_search() {
    HashMap<int, string> hashMap(10);  // Provide the size argument

    cout << "Testing insert and search...\n";
    hashMap.insert(1, "One");
    hashMap.insert(2, "Two");
    hashMap.insert(3, "Three");

    cout << "Inserted values:\n";
    cout << "Key 1: " << hashMap.search(1)->data.second << "\n";
    cout << "Key 2: " << hashMap.search(2)->data.second << "\n";
    cout << "Key 3: " << hashMap.search(3)->data.second << "\n";

    assert(hashMap.search(1)->data.second == "One");
    assert(hashMap.search(2)->data.second == "Two");
    assert(hashMap.search(3)->data.second == "Three");

    cout << "test_insert_and_search passed.\n\n";
}

//==============================================================
// Test updating values
// Ensures that inserting an existing key updates its value.
//==============================================================
void test_update_value() {
    HashMap<int, string> hashMap(10);  // Provide the size argument

    cout << "Testing update values...\n";
    hashMap.insert(1, "One");
    cout << "Before update: Key 1 = " << hashMap.search(1)->data.second << "\n";

    hashMap.insert(1, "Updated One");
    cout << "After update: Key 1 = " << hashMap.search(1)->data.second << "\n";

    assert(hashMap.search(1)->data.second == "Updated One");

    cout << "test_update_value passed.\n\n";
}

//==============================================================
// Test removing keys
// Ensures that keys can be removed and are no longer searchable.
//==============================================================
void test_remove_key() {
    HashMap<int, string> hashMap(10);  // Provide the size argument

    cout << "Testing remove key...\n";
    hashMap.insert(1, "One");
    cout << "Before removal: Key 1 = " << hashMap.search(1)->data.second << "\n";

    hashMap.remove(1);
    cout << "After removal: Key 1 = " 
              << (hashMap.search(1) == nullptr ? "nullptr" : hashMap.search(1)->data.second) << "\n";

    assert(hashMap.search(1) == nullptr);

    cout << "test_remove_key passed.\n\n";
}

//==============================================================
// Test removing a non-existent key
// Ensures that removing a key that doesn't exist throws an exception.
//==============================================================
void test_remove_non_existent_key() {
    HashMap<int, string> hashMap(10);  // Provide the size argument

    cout << "Testing remove non-existent key...\n";

    try {
        hashMap.remove(999);  // This key doesn't exist
        assert(false);  // Fail the test if no exception is thrown
    } catch (const runtime_error& e) {
        cout << "Caught expected exception: " << e.what() << "\n";
    }

    cout << "test_remove_non_existent_key passed.\n\n";
}

//==============================================================
// Test operator[]
// Ensures that operator[] retrieves and sets values correctly.
//==============================================================
void test_operator_brackets() {
    HashMap<int, string> hashMap(10);  // Provide the size argument

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
    HashMap<int, string> hashMap(10);  // Provide the size argument

    cout << "Testing empty hash map search...\n";
    cout << "Search Key 1: " 
              << (hashMap.search(1) == nullptr ? "nullptr" : hashMap.search(1)->data.second) << "\n";

    assert(hashMap.search(1) == nullptr);

    cout << "test_empty_hash_map_search passed.\n\n";
}

//==============================================================
// Test collision handling
// Ensures that the hash map handles collisions correctly.
//==============================================================
void test_collision_handling() {
    HashMap<int, string> hashMap(1);  // Force all keys to collide

    cout << "Testing collision handling...\n";
    hashMap.insert(1, "One");
    hashMap.insert(2, "Two");

    cout << "Colliding keys:\n";
    cout << "Key 1: " << hashMap.search(1)->data.second << "\n";
    cout << "Key 2: " << hashMap.search(2)->data.second << "\n";

    assert(hashMap.search(1)->data.second == "One");
    assert(hashMap.search(2)->data.second == "Two");

    cout << "test_collision_handling passed.\n\n";
}

//==============================================================
// Test inserting and searching keys in HashMapTree
//==============================================================
void test_insert_and_search_HashMapTree() {
    HashMapTree<int, string> hashMapTree(10);

    cout << "Testing insert and search in HashMapTree...\n";
    hashMapTree.insert(1, "One");
    hashMapTree.insert(2, "Two");
    hashMapTree.insert(3, "Three");

    cout << "Inserted values:\n";
    cout << "Key 1: " << hashMapTree.search(1)->data.second << "\n";
    cout << "Key 2: " << hashMapTree.search(2)->data.second << "\n";
    cout << "Key 3: " << hashMapTree.search(3)->data.second << "\n";

    assert(hashMapTree.search(1)->data.second == "One");
    assert(hashMapTree.search(2)->data.second == "Two");
    assert(hashMapTree.search(3)->data.second == "Three");

    cout << "test_insert_and_search_HashMapTree passed.\n\n";
}


//==============================================================
// Test updating values in HashMapTree
//==============================================================
void test_update_value_HashMapTree() {
    HashMapTree<int, string> hashMapTree(10);

    cout << "Testing update values in HashMapTree...\n";
    hashMapTree.insert(1, "One");
    cout << "Before update: Key 1 = " << hashMapTree.search(1)->data.second << "\n";

    hashMapTree.insert(1, "Updated One");
    cout << "After update: Key 1 = " << hashMapTree.search(1)->data.second << "\n";

    assert(hashMapTree.search(1)->data.second == "Updated One");

    cout << "test_update_value_HashMapTree passed.\n\n";
}

//==============================================================
// Test removing keys in HashMapTree
//==============================================================
void test_remove_key_HashMapTree() {
    HashMapTree<int, string> hashMapTree(10);

    cout << "Testing remove key in HashMapTree...\n";
    hashMapTree.insert(1, "One");
    cout << "Before removal: Key 1 = " << hashMapTree.search(1)->data.second << "\n";

    hashMapTree.remove(hashMapTree.search(1));
    cout << "After removal: Key 1 = " << (hashMapTree.search(1) == nullptr ? "nullptr" : hashMapTree.search(1)->data.second) << "\n";

    assert(hashMapTree.search(1) == nullptr);

    cout << "test_remove_key_HashMapTree passed.\n\n";
}

//==============================================================
// Test removing a non-existent key in HashMapTree
//==============================================================
void test_remove_non_existent_key_HashMapTree() {
    HashMapTree<int, string> hashMapTree(10);

    cout << "Testing remove non-existent key in HashMapTree...\n";

    try {
        hashMapTree.remove(hashMapTree.search(999));  // This key doesn't exist
        assert(false);  // Fail the test if no exception is thrown
    } catch (const runtime_error& e) {
        cout << "Caught expected exception: " << e.what() << "\n";
    }

    cout << "test_remove_non_existent_key_HashMapTree passed.\n\n";
}

//==============================================================
// Test operator[] in HashMapTree
//==============================================================
void test_operator_brackets_HashMapTree() {
    HashMapTree<int, string> hashMapTree(10);

    assert(hashMapTree[1] == "Two");

    cout << "test_operator_brackets_HashMapTree passed.\n\n";
}

//==============================================================
// Test searching in an empty HashMapTree
//==============================================================std::
void test_empty_HashMapTree_search() {
    HashMapTree<int, string> hashMapTree(10);

    cout << "Testing empty HashMapTree search...\n";
    cout << "Search Key 1: " << (hashMapTree.search(1) == nullptr ? "nullptr" : hashMapTree.search(1)->data.second) << "\n";

    assert(hashMapTree.search(1) == nullptr);

    cout << "test_empty_HashMapTree_search passed.\n\n";
}

//==============================================================
// Test collision handling in HashMapTree
//==============================================================
void test_collision_handling_HashMapTree() {
    HashMapTree<int, string> hashMapTree(1);  // Force all keys to collide

    cout << "Testing collision handling in HashMapTree...\n";
    hashMapTree.insert(1, "One");
    hashMapTree.insert(2, "Two");

    cout << "Colliding keys:\n";
    cout << "Key 1: " << hashMapTree.search(1)->data.second << "\n";
    cout << "Key 2: " << hashMapTree.search(2)->data.second << "\n";

    assert(hashMapTree.search(1)->data.second == "One");
    assert(hashMapTree.search(2)->data.second == "Two");

    cout << "test_collision_handling_HashMapTree passed.\n\n";
}


//==============================================================
// Set construction
// Inserting 5 and 10 and searching for 5, 10, and 21 for their outcomes
//==============================================================
void setConstruction(){
    Set<int> setter;
    cout << "constructing a set called 'setter' that has inserted 5 and 10" << endl;
    setter.insert(5);
    cout << "Is 5 in setter? "  << setter.search(5) << endl << "(expected outcome: True)" << endl;
    setter.insert(10);
    cout << "Is 10 in setter? " << setter.search(10) << endl << "(expected outcome: True)" << endl;
    cout << "Is 21 in setter? " << setter.search(21) << endl << "(expected outcome: False)" << endl;
    cout << "constructing setter completed!" << endl << endl;
}

//==============================================================
// Set construction
// EXPECTS an exception
//==============================================================
void setInsertException(){
    Set<int> setter;
    cout << "constructing a set called 'datastruct' that has inserted 5." << endl;
    setter.insert(5);
    cout << "Is 5 in setter? "  << setter.search(5) << endl << "(expected outcome: True)" << endl << endl << "re-inserting 5 to cause a custom exception" << endl;
    setter.insert(5);
}


//==============================================================
// Main function
// Runs all test cases
// certain test will be commented out for other test to run.These commented out test are expected to throw an exception.
//==============================================================
int main() {
    test_insert_and_search();
    test_update_value();
    test_remove_key();
    //test_remove_non_existent_key();
    //test_operator_brackets();
    test_empty_hash_map_search();
    test_collision_handling();

    cout << "All tests passed!\n";
    cout << "beginning Other test..." << endl << endl;

    test_insert_and_search_HashMapTree();
    test_update_value_HashMapTree();
    test_remove_key_HashMapTree();
    //test_remove_non_existent_key_HashMapTree();
    //test_operator_brackets_HashMapTree();
    test_empty_HashMapTree_search();
    test_collision_handling_HashMapTree();

    cout << "All tests for HashMapTree passed!\n";
    cout << endl << endl << "Beginning Set testing..." << endl << endl;
    setConstruction();
    //setInsertException();
    return 0;
}
