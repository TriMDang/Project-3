//==================================================================================
// Names: Tri Dang, Huy Phan (Project 2 teammate)
// CS 271
// Project 2
// Date: 11/29/2024
// About: Implementation for custom exceptions error/
//==================================================================================

#include <iostream>
#include <exception>
#pragma once

using namespace std;

//==================================================================================
// Empty Tree Exception
// Author: Huy Phan (taken from project 2)
// Description: Throws an error for when the tree is empty
//==================================================================================

class EmptyTreeException: public exception{
    public:
        const char* what() const noexcept override{
            return "Operation failed: Tree is empty.";
        }
};

//==================================================================================
// Nonexistent value
// Author: Huy Phan (taken from project 2)
// Description: Designed for search. Throws an error if searched value is not in tree
//==================================================================================

class ValueNotInTreeException: public exception{
    public:
        const char* what() const noexcept override{
            return "Operation failed: Specified value was not found.";
        }
};

//==================================================================================
// Empty Hash table
// Author: Tri Dang
// Description: Throws error if accessing an empty hash table
//==================================================================================

class EmptyHashTable: public exception{
    public:
        const char* what() const noexcept override{
            return "Operation failed: The table is empty.";
        }
};

//==================================================================================
// Empty Hash table
// Author: Tri Dang
// Description: Made for set. Throws error if value exited.
//==================================================================================

class ValueExisted: public exception{
    public:
        const char* what() const noexcept override{
            return "Operation failed: The value already exist.";
        }
};