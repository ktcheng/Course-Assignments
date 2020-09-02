#include <iostream>
#include <cassert>
#include "SSNSet.h"

int main()
{
	std::cout << "It builds!" << std::endl;
	std::cout.setf(std::ios::boolalpha);

	SSNSet s1;
	assert(s1.size() == 0); // s1 is empty and thus has size 0
	s1.add(905155544);
	assert(s1.size() == 1); // Now s1 has 1 element
	assert(!s1.add(905155544)); // Cannot add a non-unique element
	assert(s1.size() == 1); // s1's size shouldn't have changed
	assert(s1.add(4074094268)); 
	assert(s1.add(90024)); 
	assert(s1.size() == 3); // Now s1 has 3 elements
	s1.print();

	std::cout << "Passed all cases!" << std::endl;
}