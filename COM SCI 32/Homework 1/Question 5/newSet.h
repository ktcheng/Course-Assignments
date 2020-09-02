#ifndef SET_H
#define SET_H

#include <string>

using ItemType = std::string;
// using ItemType = unsigned long;

const int DEFAULT_MAX_ITEMS = 240;

class Set
{
public:
    // Create an empty set (i.e., one with no items).
    Set();

    // Create a set with a specified size
    Set(int size);

    // Destructor declaration
    ~Set();

    // Copy constructor declaration
    Set(const Set& other); 

    // Assignment operator declaration
    Set& operator=(const Set& assignSet);

    // Return true if the set is empty, otherwise false.
    bool empty() const; // Const member function: checks state

    // Return the number of items in the set.
    int size() const; // Const member function: checks state

    // Insert value into the set if it is not already present.  Return
    // true if the value is actually inserted.  Leave the set unchanged
    // and return false if the value was not inserted (perhaps because it
    // was already in the set or because the set has a fixed capacity and
    // is full).
    bool insert(const ItemType& value);

    // Remove the value from the set if it is present.  Return true if the
    // value was removed; otherwise, leave the set unchanged and
    // return false.
    bool erase(const ItemType& value);

    // Return true if the value is in the set, otherwise false.
    bool contains(const ItemType& value) const; // Const member function: checks state

    // If 0 <= i < size(), copy into value the item in the set that is
    // strictly greater than exactly i items in the set and return true.
    // Otherwise, leave value unchanged and return false.
    bool get(int i, ItemType& value) const; // Const member function: checks state

    // Exchange the contents of this set with the other one.
    void swap(Set& other);

private:
    int m_size; // Number that keeps track of non-empty elements in the set
    int m_maxsize; // Number that keeps track of set capacity
    int m_index; // Index that tracks set element insertion

    // Problem 5: Implementation via dynamically allocated array
    ItemType* m_array;
};

#endif