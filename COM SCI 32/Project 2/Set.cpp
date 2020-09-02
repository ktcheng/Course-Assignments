#include <iostream>
#include "Set.h"

// Constructor Implementation: creates empty Set
Set::Set()
{
	m_head = nullptr;
	m_size = 0; // Initially, Set contains no nodes
}

// Attempts node insertion, and sorts linked list upon insertion
bool Set::insert(const ItemType& value)
{
	bool is_inserted;

	// If value not in Set, insert accordingly
	if (contains(value))
	{
		is_inserted = false;
	}
	else
	{
		is_inserted = true;

		// Checks for insertion type (inserting into empty/non-empty Set)
		if (m_size == 0)
		{
			m_head = new Node(); // Make head point to new node
			m_head->data = value; 
			m_head->previous = nullptr; 
			m_head->next = nullptr;
		}
		else
		{
			Node* ptr_i = new Node(); // Create new node
			ptr_i->data = value;
			ptr_i->next = m_head; // Places new node at front of list
			ptr_i->previous = nullptr;

			m_head->previous = ptr_i; // Set previous to new first node
			m_head = ptr_i; // Shift head to point at new first node
		}
			
		Node* sort_i = m_head->next; // Temporary pointer to traverse Set and sort nodes

		// Sort Set each time we insert
		while (sort_i != nullptr)
		{
			Node* compare = m_head; // Local pointer to compare Set node values

			// Compares all preceding node values up to current node
			while (compare != sort_i)
			{
				// Performs node value comparison
				if (compare->data > sort_i->data)
				{
					// Swaps node values upon comparison
					ItemType placeholder = sort_i->data;
					sort_i->data = compare->data;
					compare->data = placeholder;
				}

				compare = compare->next; // Shift compare pointer to next node
			}

			sort_i = sort_i->next; // Shift sort pointer to next node
		}

		m_size++; // Increment the number of nodes in Set
	}

	return(is_inserted);
}

// Attempts node removal from Set
bool Set::erase(const ItemType& value)
{
	bool is_erased;

	// If value is in Set, erase accordingly
	if (contains(value))
	{
		is_erased = true;

		Node* ptr_e = m_head; // Temporary pointer to remove relevant node

		// Checks if our Set contains multiple nodes v. a singular node
		if (m_size == 1)
		{
			m_head = nullptr; // Reset head to point at nullptr
			delete ptr_e;
			ptr_e = m_head; // Don't leave a dangling pointer
		}
		else
		{
			// While loop shifts ptr to point at the relevant node
			while (ptr_e->data != value)
			{
				ptr_e = ptr_e->next;
			}

			// Checks for erasing the first element, s.t. don't follow nullptr
			if (ptr_e->previous != nullptr)
			{
				ptr_e->previous->next = ptr_e->next; // Sets previous node to point to current node's next node
			}

			// Checks for erasing the last element, s.t. don't follow nullptr
			if (ptr_e->next != nullptr)
			{
				ptr_e->next->previous = ptr_e->previous;
			}

			// If deleting first node, ensure head pointer is shifted before erasing
			if (ptr_e == m_head)
			{
				m_head = m_head->next;
			}

			delete ptr_e;
			ptr_e = m_head; // Don't leave a dangling pointer
		}

		m_size--; // Decrement the number of nodes in Set
	}
	else
	{
		is_erased = false;
	}

	return(is_erased);
}

// Checks Set for the argument value
bool Set::contains(const ItemType& value) const
{
	bool is_contained = false; // By default, assume value isn't in Set

	Node* ptr_c = m_head; // Temporary pointer to traverse Set and evaluate data

	// Traverse Set, comparing node values from the front
	while (ptr_c != nullptr)
	{
		// If node's data is equal to value, break and return true
		if (ptr_c->data == value)
		{
			is_contained = true;
			break;
		}

		ptr_c = ptr_c->next; // Shift ptr onto next node
	}

	return(is_contained);
}

// For valid parameters, will write into value the appropriate node's data
bool Set::get(int pos, ItemType& value) const
{
	bool is_gettable;

	Node* ptr_g = m_head; // Temporary pointer to get relevant node

	// If our position parameter is valid, write relevant data into value
	if (pos >= 0 && pos < m_size)
	{
		is_gettable = true;
		
		// For loop shifts ptr to relevant node
		for (int i = 0; i < pos; i++)
		{
			ptr_g = ptr_g->next;
		}

		value = ptr_g->data;
	}
	else
	{
		is_gettable = false;
	}

	return(is_gettable);
}

// Swaps two Sets with each other
void Set::swap(Set& other)
{
	Node* ptr_sw = nullptr; // Temporary pointer for swapping purposes
	int placeholder; // Temporary integer for swapping Set sizes

	// Swap the Sets' size data member
	placeholder = m_size;
	m_size = other.m_size;
	other.m_size = placeholder;
	
	// Swap the Sets' head pointers
	ptr_sw = m_head;
	m_head = other.m_head;
	other.m_head = ptr_sw;
}

// Destructor Implementation
Set::~Set()
{
	Node* ptr_destruct = m_head; // Temporary pointer to traverse Set and delete
	
	// Traverse Set, deleting nodes from the front
	while (ptr_destruct != nullptr)
	{
		m_head = m_head->next;
		delete ptr_destruct;
		ptr_destruct = m_head;
	}
}

// Copy Constructor Implementation
Set::Set(const Set& other)
	: m_head(nullptr), m_size(0)
{
	Node* ptr_cc = other.m_head; // Temporary pointer to traverse other and copy its nodes

	// Traverse other, copying nodes into this
	for (int i = 0; i < other.m_size; i++)
	{
		insert(ptr_cc->data); // Insert copied node, and updates m_size appropriately
		ptr_cc = ptr_cc->next; // Shift ptr onto other's next node
	}
}

// Assignment Operator Implementation
Set& Set::operator=(const Set& rhs)
{
	// Checks for dangerous self-assignment
	if (this != &rhs)
	{	
		Set temp(rhs); // Initialize a temporary Set copied from other
		swap(temp); // Swaps the temporary Set with current Set
	}

	return(*this);
}

// Personal Testing Purposes
void Set::dump() const
{
	Node* ptr_d = m_head;

	for (int i = 0; i < m_size; i++)
	{
		std::cerr << "This is the node's data value: " << ptr_d->data << std::endl;
		ptr_d = ptr_d->next;
	}
}

////////////////////////////////////
// Additional Non-member Functions
////////////////////////////////////

// Unite Implementation
void unite(const Set& s1, const Set& s2, Set& result)
{
	int size1 = s1.size(); // Obtains the size of s1
	int size2 = s2.size(); // Obtains the size of s2

	// Checks to ensure that result is unique from s1 and s2
	if (&result != &s1 && &result != &s2)
	{
		// Reset result if it is nonempty
		if (result.size() != 0)
		{
			Set temp; // Create an empty Set
			result.swap(temp); // Swap the empty Set with result
		}

		// Attempts insertion from s1 nodes
		for (int i = 0; i < size1; i++)
		{
			ItemType dummy; // Dummy variable to compare Set elements
			s1.get(i, dummy); // Writes s1's data into dummy
			result.insert(dummy);
		}

		// Attempts insertion from s2 nodes
		for (int i = 0; i < size2; i++)
		{
			ItemType dummy; // Dummy variable to compare Set elements;
			s2.get(i, dummy); // Writes s2's data into dummy
			result.insert(dummy); // Insert method already calls the contains function
		}
	}
	else // If aliasing present, store result in placeholder Set, then swap with result reference
	{
		Set temp; // Placeholder result Set

		// Attempts insertion from s1 nodes
		for (int i = 0; i < size1; i++)
		{
			ItemType dummy; // Dummy variable to compare Set elements
			s1.get(i, dummy); // Writes s1's data into dummy
			temp.insert(dummy); // Insert into placeholder Set
		}

		// Attempts insertion from s2 nodes
		for (int i = 0; i < size2; i++)
		{
			ItemType dummy; // Dummy variable to compare Set elements;
			s2.get(i, dummy); // Writes s2's data into dummy
			temp.insert(dummy); // Insert method already calls the contains function
		}

		result.swap(temp); // Replaces old referenced Set with the "result" Set
	}
}

// Subtract Implementation
void subtract(const Set& s1, const Set& s2, Set& result)
{
	int size1 = s1.size(); // Obtains the size of s1

	// Checks to ensure that result is unique from s1 and s2
	if (&result != &s1 && &result != &s2)
	{
		// Reset result if it is nonempty
		if (result.size() != 0)
		{
			Set temp; // Create an empty Set
			result.swap(temp); // Swap the empty Set with result
		}

		// Loop will only insert unique s1 elements into result
		for (int i = 0; i < size1; i++)
		{
			ItemType dummy; // Dummy variable to extract s1's elements
			s1.get(i, dummy); // Writes s1's data into dummy

			// If data is not in s2, insert into result Set
			if (!(s2.contains(dummy)))
			{
				result.insert(dummy);
			}
		}
	}
	else // If aliasing present, store result in placeholder Set, then swap with result reference
	{
		Set temp; // Placeholder result Set

		// Loop will only insert unique s1 elements into placeholder
		for (int i = 0; i < size1; i++)
		{
			ItemType dummy; // Dummy variable to extract s1's elements
			s1.get(i, dummy); // Writes s1's data into dummy

			// If data is not in s2, insert into result Set
			if (!(s2.contains(dummy)))
			{
				temp.insert(dummy);
			}
		}

		result.swap(temp); // Replaces old referenced Set with the "result" Set
	}
}