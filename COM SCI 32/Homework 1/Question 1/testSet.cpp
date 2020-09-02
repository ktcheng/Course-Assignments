#include <iostream>
#include <cassert>
#include "Set.h"

//int main()
//{
//	std::cout << "It builds!" << std::endl;
//	std::cout.setf(std::ios::boolalpha);
//
//	/////////////////////////////////////
//	// Test Cases (Given)
//	/////////////////////////////////////
//
//	Set c;
//	assert(c.empty());
//	ItemType x = "arepa";
//	assert(!c.get(42, x) && x == "arepa"); // x unchanged by get failure
//	c.insert("chapati");
//	assert(c.size() == 1);
//	assert(c.get(0, x) && x == "chapati");
//	std::cout << "Passed all tests" << std::endl;
//
//	/////////////////////////////////////
//	// Test Cases (strings)
//	/////////////////////////////////////
//
//	Set s, a; // Constructs two empty sets
//	assert(s.empty()); // Set s should be empty
//	assert(s.size() == 0); // Thus, it has size 0
//	assert(s.insert("hello")); 
//	assert(s.size() == 1); // Now s contains 1 element
//	assert(s.insert("hi"));
//	assert(!s.insert("hi")); // "hi" is already in s
//	assert(s.size() == 2); // s contains "hello" and "hi"
//	
//	assert(a.empty()); // Set a should be empty
//	assert(a.size() == 0); // Thus, it has size 0
//	assert(a.insert("Goodbye"));
//	assert(a.insert("Arrivederci"));
//	assert(a.insert("Sayonara"));
//	assert(a.size() == 3); // a contains 3 elements
//	assert(!a.empty()); // a is no longer an empty Set
//	s.swap(a); // Sets a and s have been swapped!
//	assert(s.size() == 3); // Now, Set s is of size 3
//	assert(a.size() == 2); // Now, Set a is of size 2
//	assert(s.insert("hi")); // Because a and s were swapped, now we can insert "hi"
//	
//	std::string str;
//	assert(s.get(0, str));
//	assert(str == "Arrivederci"); // It is now the first element in s
//	s.swap(a); // Now let's swap these sets back
//	assert(!s.insert("hello")); // "hello" is now back in Set s!
//
//	/////////////////////////////////////
//	// Test Cases (Given)
//	/////////////////////////////////////
//
//	//Set d;
//	//assert(d.empty());
//	//ItemType x = 9876543;
//	//assert(!d.get(42, x) && x == 9876543); // x unchanged by get failure
//	//d.insert(123456789);
//	//assert(d.size() == 1);
//	//assert(d.get(0, x) && x == 123456789);
//	//std::cout << "Passed all tests" << std::endl;
//	
//	/////////////////////////////////////
//	// Test Cases (unsigned longs)
//	/////////////////////////////////////
//
//	//Set l, m; // Constructs two empty sets
//	//assert(l.empty()); // Set l should be empty
//	//assert(l.size() == 0); // Thus, it has size 0
//	//assert(l.insert(12345)); 
//	//assert(l.size() == 1); // Now l contains 1 element
//	//assert(l.insert(67890));
//	//assert(!l.insert(67890)); // 67890 is already in l
//	//assert(l.size() == 2); // l contains 2 elements now
//
//	//assert(m.empty()); // Set m should be empty
//	//assert(m.size() == 0); // Thus, it has size 0
//	//assert(m.insert(13579)); 
//	//assert(m.insert(24680));
//	//assert(m.insert(99999));
//	//assert(m.size() == 3); // m contains 3 elements
//	//assert(!m.empty()); // m is no longer an empty Set
//	//l.swap(m); // Sets m and l have been swapped!
//	//assert(l.size() == 3); // Now, Set l is of size 3
//	//assert(m.size() == 2); // Now, Set l is of size 2
//	//assert(l.insert(67890)); // Because l and m were swapped, now we can insert 67890
//
//	//unsigned long lng;
//	//assert(l.get(0, lng));
//	//assert(lng == 13579); // It is now the first element in l
//	//l.swap(m); // Now let's swap these sets back
//	//assert(!l.insert(12345)); // 12345 is now back in Set l!
//}

int main()
{
	const ItemType DEFAULT = 0;
	Set s;
	std::cout.setf(std::ios::boolalpha);

	std::cout << s.erase(DEFAULT);
}