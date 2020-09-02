#ifndef LINKLIST_H
#define LINKLIST_H

#include <string>
using ItemType = std::string;

class Set
{
public:
	/// Original Public Interface
	Set(); // Set constructor: initializes an empty Set

	inline bool empty() const // Accessor: returns true if Set is empty
	{
		return(m_size == 0); // Returns true if Set contains no nodes, false otherwise
	}

	inline int size() const // Accessor: returns the number of elements in Set
	{
		return(m_size);
	}

	bool insert(const ItemType& value); // Mutator: attempts element insertion into the Set
	bool erase(const ItemType& value); // Mutator: attempts element deletion from the Set
	bool contains(const ItemType& value) const; // Accessor: returns true if value in Set
	bool get(int pos, ItemType& value) const; // Accessor: attempts to copy into value
	void swap(Set& other); // Mutator: swaps two Sets

	// Additional Member Functions
	~Set(); // Set destructor: destroys Set object
	Set(const Set& other); // Set copy constructor: copies other into Set
	Set& operator=(const Set& rhs); // Set assignment operator: assigns rhs into Set

	// Personal Testing Purposes
	void dump() const;

private:
	struct Node // Details node structure of linked list
	{
		ItemType data; // Actual data that is stored in Set
		Node* next; // Pointer to the next node
		Node* previous; // Pointer to the previous node
	};
	Node* m_head; // Pointer to first node in Set
	int m_size; // Stores number of nodes in Set
};

////////////////////////////////////
// Additional Non-member Functions
////////////////////////////////////

void unite(const Set& s1, const Set& s2, Set& result);

void subtract(const Set& s1, const Set& s2, Set& result);

#endif // LINKLIST_H