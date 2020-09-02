#include <iostream>
#include <cassert>
#include "newSet.h"

int main()
{
	std::cout << "It builds!" << std::endl;
	std::cout.setf(std::ios::boolalpha);

	/////////////////////////////////////
	// Test Cases (Given)
	/////////////////////////////////////

	Set a(1000);   // a can hold at most 1000 distinct items
	Set b(5);      // b can hold at most 5 distinct items
	Set c;         // c can hold at most DEFAULT_MAX_ITEMS distinct items
	ItemType v[6] = {"abc", "def", "ghi", "jkl", "mno" , "pqr" };

	// No failures inserting 5 distinct items into b
	for (int k = 0; k < 5; k++)
		assert(b.insert(v[k]));

	// Failure if we try to insert a sixth distinct item into b
	assert(!b.insert(v[5]));

	// When two Sets' contents are swapped, their capacities are swapped
	// as well:
	a.swap(b);
	assert(!a.insert(v[5]) && b.insert(v[5]));

	/////////////////////////////////////
	// Test Cases (strings)
	/////////////////////////////////////

	Set sss(7); // sss can hold at most 10 distinct items
	Set bbb; // Default constructor in effect
	assert(sss.empty()); // sss is currently empty
	assert(sss.size() == 0); // sss thus has size 0
	Set aaa = sss; // Copy constructor in effect
	assert(aaa.empty()); // aaa should also be empty
	assert(aaa.size() == 0); // aaa should also have size 0

	// Inserted sss to be maximum capacity with 7 distinct items
	sss.insert("Hello");
	sss.insert("Ni Hao");
	sss.insert("Konnichiwa");
	sss.insert("Bonjour");
	sss.insert("Como estas");
	sss.insert("Hallo");
	sss.insert("Anyung Haseyo");
	assert(!sss.insert("Hallo")); // Hallo already exists
	assert(sss.erase("Hallo")); // Now let's erase Hallo
	assert(sss.insert("Hallo")); // Now let's try insertion again
	assert(sss.size() == 7); // At max capacity, sss should be of size 7
	aaa = sss; // Assignment operator in effect
	assert(aaa.size() == 7); // aaa now also has 7 elements
	assert(!aaa.insert("Hello!")); // Even though argument is unique, we are at capacity
	bbb = aaa; // Assignment operator in effect
	assert(bbb.size() == 7); // bbb is now also of size 7
	assert(bbb.contains("Hallo")); // Since bbb is assigned from aaa, and aaa contains Hallo

	std::string str;
	assert(bbb.get(2, str)); // Copies at index 2 of sorted elements, i.e. Como estas
	std::cout << str << std::endl; // Outputs "Como estas"

	Set tester(0);
	Set another;
	another.swap(tester);
	std::cout << another.size();
	std::cout << tester.size();
	assert(!another.insert("test"));

	/////////////////////////////////////
	// Test Cases (Given)
	/////////////////////////////////////

	//Set a(1000);   // a can hold at most 1000 distinct items
	//Set b(5);      // b can hold at most 5 distinct items
	//Set c;         // c can hold at most DEFAULT_MAX_ITEMS distinct items
	//ItemType v[6] = { 1, 2, 3, 4, 5, 6 };

	//// No failures inserting 5 distinct items into b
	//for (int k = 0; k < 5; k++)
	//	assert(b.insert(v[k]));

	//// Failure if we try to insert a sixth distinct item into b
	//assert(!b.insert(v[5]));

	//// When two Sets' contents are swapped, their capacities are swapped
	//// as well:
	//a.swap(b);
	//assert(!a.insert(v[5]) && b.insert(v[5]));

	/////////////////////////////////////
	// Test Cases (Given)
	/////////////////////////////////////

	//Set l(4), m; // Constructs two empty sets
	//assert(l.empty()); // Set l should be empty
	//assert(l.size() == 0); // Thus, it has size 0
	//assert(l.insert(12345)); 
	//assert(l.size() == 1); // Now l contains 1 element
	//assert(l.insert(67890));
	//assert(!l.insert(67890)); // 67890 is already in l
	//assert(l.size() == 2); // l contains 2 elements now

	//assert(m.empty()); // Set m should be empty
	//assert(m.size() == 0); // Thus, it has size 0
	//assert(m.insert(13579)); 
	//assert(m.insert(24680));
	//assert(m.insert(99999));
	//assert(m.size() == 3); // m contains 3 elements
	//assert(!m.empty()); // m is no longer an empty Set
	//l.swap(m); // Sets m and l have been swapped!
	//assert(l.size() == 3); // Now, Set l is of size 3
	//assert(m.size() == 2); // Now, Set l is of size 2
	//assert(l.insert(67890)); // Because l and m were swapped, now we can insert 67890

	//unsigned long lng;
	//assert(l.get(0, lng));
	//assert(lng == 13579); // It is now the first element in l
	//l.swap(m); // Now let's swap these sets back
	//assert(!l.insert(12345)); // 12345 is now back in Set l!
	//assert(l.insert(11111));
	//assert(l.insert(222222));
	//assert(!l.insert(33333)); // Even though it's unique, we are at capacity!
}