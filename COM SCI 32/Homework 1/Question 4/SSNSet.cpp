#include <iostream>
#include "SSNSet.h"

// Default constructor: initializes an empty SSNSet
SSNSet::SSNSet()
{

}

// Mutator function: attempts element insertion
bool SSNSet::add(unsigned long ssn)
{
	// Set the boolean value equal to the set's insert function
	bool is_added = m_set.insert(ssn);
	return(is_added);
}

// Accessor function: checks the set size
int SSNSet::size() const
{
	// Set the size of SSNSet equal to the set's size
	int size = m_set.size();
	return(size);
}

void SSNSet::print() const
{
	// Use the get function to print the SSN for each element in the set
	for (int i = 0; i < m_set.size(); i++)
	{
		unsigned long j;
		m_set.get(i, j);
		std::cout << j << std::endl;
	}
}