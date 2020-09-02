#include <iostream>
#include "newSet.h"

// Default constructor: initializes an empty set
Set::Set()
{
	m_array = new ItemType[DEFAULT_MAX_ITEMS]; // Dynamically allocate array
	m_maxsize = DEFAULT_MAX_ITEMS;
	m_index = 0;
	m_size = 0;
}

// Nondefault constructor: initializes a set with specified size
Set::Set(int size)
{
	// If the argument is valid, make the appropriately sized set, otherwise exit
	if (size >= 0)
	{
		m_index = 0;
		m_maxsize = size;
		m_size = 0;
		m_array = new ItemType[m_maxsize]; // Dynamically allocate array
	}
	else
	{
		std::cout << "You did not input a correct argument!" << std::endl;
		exit(1);
	}
}

// Destructor implementation
Set::~Set()
{
	delete[] m_array; // Deletes the entire dynamically allocated array
}

// Copy constructor implementation
Set::Set(const Set& other)
	: m_size(other.m_size), m_maxsize(other.m_maxsize), m_index(other.m_index)
{
	m_array = new ItemType[m_maxsize]; // Dynamically allocate array

	// For loop will initialize the array contents
	for (int i = 0; i < m_maxsize; i++)
	{
		m_array[i] = other.m_array[i];
	}
}

// Assignment operator implementation
Set& Set::operator=(const Set& other)
{
	// Checks for dangerous self assignment
	if (this != &other)
	{
		/// Modern method below:
		Set temp(other);
		swap(temp);
	}
	
	/// Non-modern method below:
	//// Set trivial parameters first
	//m_size = other.m_size;
	//m_maxsize = other.m_maxsize;
	//m_index = other.m_index;
	//
	//// Ensure resources are available, then delete and copy
	//ItemType* temp_array = new ItemType[m_maxsize];
	//delete[] m_array;
	//m_array = temp_array;
	//
	//// For loop will initialize the array contents
	//for (int i = 0; i < m_maxsize; i++)
	//{
	//	m_array[i] = other.m_array[i];
	//}

	return(*this); // Returns Set object
}

// Accessor function: checks for an empty set
bool Set::empty() const
{
	bool is_empty;

	// If the set is empty (size of 0 elements), return true
	if (m_size == 0)
	{
		is_empty = true;
	}
	else
	{
		is_empty = false;
	}

	return(is_empty);
}

// Accessor function: checks the set size
int Set::size() const
{
	return(m_size);
}

// Mutator function: attempts element insertion
bool Set::insert(const ItemType& value)
{
	bool is_inserted;

	// If we have reached maximum capacity, we cannot insert the value, thus return false
	if (m_size >= m_maxsize)
	{
		is_inserted = false;
		return(is_inserted);
	}

	// Check if element is in set, otherwise insert the value
	if (contains(value))
	{
		// If the element is already within our set, set is_inserted to be false
		is_inserted = false;
	}
	else
	{
		// If the element is not within our set, set is_inserted to be true
		is_inserted = true;
		
		// Set the array element to the argument value
		m_array[m_index] = value;

		/// Sort m_array every time we successfully insert a value
		ItemType placeholder = m_array[0]; // Placeholder value for array sorting

		// For loop will reorder the array
		for (int i = 1; i <= m_size; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (m_array[j] > m_array[i])
				{
					placeholder = m_array[j]; // Sets placeholder
					m_array[j] = m_array[i]; // Sets < item in front
					m_array[i] = placeholder; // Sets > item in back
				}
			}
		}

		m_index++; // Increment the insertion index counter
		m_size++; // Increment the set size counter
	}

	return(is_inserted);
}

// Mutator function: attempts element deletion
bool Set::erase(const ItemType& value)
{
	bool is_removed;

	// Check if element is in set, in which case we remove the value, otherwise do nothing
	if (contains(value))
	{
		// Set is_removed to be true, and subsequently erase the element
		is_removed = true;

		// Loops for the matching value's index
		for (int i = 0; i < m_size; i++)
		{
			if (m_array[i] == value)
			{
				// Shifts over remaining elements
				for (int j = i; j < m_size - 1; j++)
				{
					m_array[j] = m_array[j + 1];
				}
				break;
			}
		}

		m_size--; // Decrement the set size counter
		m_index--; // Decrement the insertion index counter
	}
	else
	{
		// If the element is not within our set, do nothing and return false
		is_removed = false;
	}

	return(is_removed);
}

// Accessor function: checks for specific value
bool Set::contains(const ItemType& value) const
{
	bool is_contained = false; // Set default value to be false, i.e. not contained

	// Checks entire set for matching elements
	for (int i = 0; i < m_size; i++)
	{
		// If the element is contained in our set, switch is_contained to be true
		if (m_array[i] == value)
		{
			is_contained = true;
		}
	}

	return(is_contained);
}

// Accessor function: copies into value a specific element
bool Set::get(int i, ItemType& value) const
{
	bool is_gettable;

	// If the integer argument is invalid, return false, otherwise copy into value
	if ((i < 0) || (i >= m_size))
	{
		is_gettable = false;
	}
	else
	{
		// Copy into value the item in the set greater than i items
		value = m_array[i];

		is_gettable = true;
	}

	return(is_gettable);
}

// Switcher function: swaps two Set objects with each other
void Set::swap(Set& other)
{
	ItemType* h_array = m_array; // Placeholder pointer
	int h_size, h_maxsize, h_index; // Placeholder containers for integer data members

	// Set placeholder integer containers equal to the current Set object
	h_size = m_size;
	h_maxsize = m_maxsize;
	h_index = m_index;

	// Set current Set object's data members equal to the argument Set's data members
	m_array = other.m_array;
	m_size = other.m_size;
	m_maxsize = other.m_maxsize;
	m_index = other.m_index;

	// Last step: set the argument Set's data members equal to the placeholder values
	other.m_array = h_array;
	other.m_size = h_size;
	other.m_maxsize = h_maxsize;
	other.m_index = h_index;
}