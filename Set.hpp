#ifndef SET_HPP
#define SET_HPP

#include "HashMap.cpp"

template <typename T>
class Set {
private:
        hashSet<T, T> hashSet;
        // unint64_t tableSize;

public:
        // Constructors & Destructor
        Set(size_t table_size = 10);                        
        Set(const Set<T> &other);          
        ~Set();                        

        // Assignment operator
        Set<T> operator=(const Set<T> &other);

        // Additional Method
        void insert(const T& value);
        void remove(const T& value);
        bool search(const T& value);
};
#endif