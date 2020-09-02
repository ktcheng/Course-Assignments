#include <iostream>
#include <cassert>
#include "Set.h"

int main()
{
	std::cout << "It builds!" << std::endl;
	std::cout.setf(std::ios::boolalpha);

	/////////////////////////////////
	/////////////////////////////////
	// String Test Cases
	/////////////////////////////////
	/////////////////////////////////
	
	///////////////////////////////
	// Basic Test Cases
	///////////////////////////////
	Set t1, t2, t3; // Create 3 test Sets
	ItemType str1, str2, str3; // Create 3 test strings
	str1 = "test";
	str2 = "tester";
	str3 = "testing";

	assert(t1.empty()); // All test Sets should be empty with size 0
	assert(t2.empty());
	assert(t3.empty());
	assert(t1.size() == 0);
	assert(t2.size() == 0);
	assert(t3.size() == 0);

	t1.insert("Hello");
	t1.insert("hello");
	t1.insert("Hallo");
	assert(t1.size() == 3); // Set size should change accordingly
	t1.insert("hallo");
	t1.insert("bonjour");
	t1.insert("Bonjour");
	assert(t1.size() == 6);
	assert(!t1.empty()); // With 6 elements Set t1 is no longer empty

	assert(!t1.insert("hello")); // "hello" is already contained in t1
	assert(t1.size() == 6); // Failed insertion should not alter t1
	assert(!t1.erase("Ni Hao")); // Cannot erase an element not in t1
	assert(t1.size() == 6); // Failed erase should not alter t1
	t1.erase("hallo");
	t1.erase("Hallo");
	assert(t1.size() == 4); // Set size should change accordingly
	t1.erase("bonjour");
	t1.erase("Bonjour");
	t1.erase("Hello");
	t1.erase("hello");
	assert(t1.size() == 0); // Erasing everything should leave an empty Set of size 0
	assert(t1.empty());

	assert(!t1.contains("Hello")); // Due to erasing, these elements no longer exist in t1
	assert(!t1.contains("hello"));
	assert(!t1.contains("Bonjour"));
	assert(!t1.contains("bonjour"));
	assert(!t1.contains("Hallo"));
	assert(!t1.contains("hallo"));

	assert(!t1.get(0, str1)); // t1 is empty
	assert(!t1.get(3, str1)); // t1 is empty
	assert(!t1.get(-1, str1)); // Invalid index parameter
	assert(str1 == "test"); // Assert str1 is unchanged

	assert(t2.insert("Goodbye"));
	assert(t2.get(0, str2)); // Writes "Goodbye" into str2
	assert(str2 == "Goodbye"); // Assert str2 has been written over
	assert(t2.erase("Goodbye"));
	assert(t2.empty());

	///////////////////////////////
	// Advanced Test Cases
	///////////////////////////////

	// First, fill test Sets with elements
	t1.insert("Hello"); // Begin insertion for Set t1
	t1.insert("Ni Hao");
	t1.insert("Salve");
	t1.insert("Bonjour");
	t1.insert("Ciao");
	t1.insert("Konnichiwa");
	t2.insert("Goodbye"); // Begin insertion for Set t2
	t2.insert("Ciao");
	t2.insert("Sayonara");
	t3.insert("Junk"); // Begin insertion for Set t3
	t3.insert("Garbage");
	t3.insert("Filler");
	t3.insert("Trash");

	t1.swap(t3); // Swap t1 with t3
	assert(t1.size() == 4); // t1 now has t3's size of 4 elements
	assert(t1.get(0, str1)); // Affirm t1 now has t3's elements
	assert(str1 == "Filler");
	assert(t1.get(1, str1));
	assert(str1 == "Garbage");
	assert(t1.get(2, str1));
	assert(str1 == "Junk");
	assert(t1.get(3, str1));
	assert(str1 == "Trash");
	assert(t3.size() == 6); // t3 now has t1's size of 6 elements
	assert(t3.get(0, str3)); // Affirm t3 now has t1's elements
	assert(str3 == "Bonjour");
	assert(t3.get(1, str3));
	assert(str3 == "Ciao");
	assert(t3.get(2, str3));
	assert(str3 == "Hello");
	assert(t3.get(3, str3));
	assert(str3 == "Konnichiwa");
	assert(t3.get(4, str3));
	assert(str3 == "Ni Hao");
	assert(t3.get(5, str3));
	assert(str3 == "Salve");
	t1.swap(t3); // For testing purposes, swap t1 and t3 back to originals
	assert(t1.size() == 6); // Assert t1 and t3's original sizes again
	assert(t3.size() == 4);

	t2.swap(t2); // t2 should remain unchanged with aliasing
	assert(t2.size() == 3); // Affirm t2's elements remain unchanged
	assert(t2.get(0, str2));
	assert(str2 == "Ciao");
	assert(t2.get(1, str2));
	assert(str2 == "Goodbye");
	assert(t2.get(2, str2));
	assert(str2 == "Sayonara");

	Set t4 = t3; // Copy Constructor in effect
	assert(t4.size() == 4); // Assert t4 has copied t3's size

	// Essentially swap t3 & t1 via Assignment Operator; run above cases again
	t3 = t1; t1 = t4; 
	assert(t1.size() == 4); // t1 now has t3's size of 4 elements
	assert(t1.get(0, str1)); // Affirm t1 now has t3's elements
	assert(str1 == "Filler");
	assert(t1.get(1, str1));
	assert(str1 == "Garbage");
	assert(t1.get(2, str1));
	assert(str1 == "Junk");
	assert(t1.get(3, str1));
	assert(str1 == "Trash");
	assert(t3.size() == 6); // t3 now has t1's size of 6 elements
	assert(t3.get(0, str3)); // Affirm t3 now has t1's elements
	assert(str3 == "Bonjour");
	assert(t3.get(1, str3));
	assert(str3 == "Ciao");
	assert(t3.get(2, str3));
	assert(str3 == "Hello");
	assert(t3.get(3, str3));
	assert(str3 == "Konnichiwa");
	assert(t3.get(4, str3));
	assert(str3 == "Ni Hao");
	assert(t3.get(5, str3));
	assert(str3 == "Salve");
	t1.swap(t3); // For testing purposes, swap t1 and t3 back to originals
	assert(t1.size() == 6); // Assert t1 and t3's original sizes again
	assert(t3.size() == 4);

	///////////////////////////////
	// Unite/Subtract Test Cases
	///////////////////////////////

	Set test1, test2, test3, test4, test5; // test4 and test5 will be empty
	test1.insert("1"); // Begin insertion for Set test1
	test1.insert("4");
	test1.insert("5");
	test2.insert("2"); // Begin insertion for Set test2
	test2.insert("3");
	test2.insert("4");
	test3.insert("3"); // Begin insertion for Set test3
	test3.insert("6");
	test3.insert("7");

	unite(test1, test2, test3);
	assert(test3.size() == 5); // test3 should contain "1", "2", "3", "4", "5"
	assert(test3.get(0, str2));
	assert(str2 == "1");
	assert(test3.get(1, str2));
	assert(str2 == "2");
	assert(test3.get(2, str2));
	assert(str2 == "3");
	assert(test3.get(3, str2));
	assert(str2 == "4");
	assert(test3.get(4, str2));
	assert(str2 == "5");

	unite(test1, test2, test1);
	assert(test1.size() == 5); // test1 should contain "1", "2", "3", "4", "5"
	assert(test1.get(0, str2));
	assert(str2 == "1");
	assert(test1.get(1, str2));
	assert(str2 == "2");
	assert(test1.get(2, str2));
	assert(str2 == "3");
	assert(test1.get(3, str2));
	assert(str2 == "4");
	assert(test1.get(4, str2));
	assert(str2 == "5");

	unite(test1, test1, test1); // test1 should remain unchanged
	assert(test1.size() == 5);
	assert(test1.get(0, str2));
	assert(str2 == "1");
	assert(test1.get(1, str2));
	assert(str2 == "2");
	assert(test1.get(2, str2));
	assert(str2 == "3");
	assert(test1.get(3, str2));
	assert(str2 == "4");
	assert(test1.get(4, str2));
	assert(str2 == "5");

	unite(test1, test1, test3); // All three parameters contain the same elements here
	assert(test3.size() == 5);

	unite(test1, test4, test3); // test4 is empty, therefore test3 is unchanged from above
	assert(test3.size() == 5);
	
	unite(test4, test4, test4); // Union of two empty Sets is the empty Set
	assert(test4.empty());

	subtract(test1, test2, test3);
	assert(test3.size() == 2); // test3 should contain "1", "5"
	assert(test3.get(0, str2));
	assert(str2 == "1");
	assert(test3.get(1, str2));
	assert(str2 == "5");

	subtract(test1, test3, test2);
	assert(test2.size() == 3); // test2 should contain "2", "3", "4"
	assert(test2.get(0, str2));
	assert(str2 == "2");
	assert(test2.get(1, str2));
	assert(str2 == "3");
	assert(test2.get(2, str2));
	assert(str2 == "4");

	subtract(test2, test2, test3);
	assert(test3.empty()); // test2 subtracted with test2 results in the empty Set

	subtract(test1, test4, test3);
	assert(test3.size() == 5); // Since test4 is empty, result is test1

	subtract(test4, test4, test4); // An empty Set has no unique elements
	assert(test4.empty());

	/////////////////////////////////
	/////////////////////////////////
	// Unsigned Long Test Cases
	/////////////////////////////////
	/////////////////////////////////
	

	///////////////////////////////
	// Basic Test Cases
	///////////////////////////////
	/* Set t1, t2, t3; // Create 3 test Sets
	ItemType long1, long2, long3; // Create 3 test longs

	assert(t1.empty()); // All test Sets should be empty with size 0
	assert(t2.empty());
	assert(t3.empty());
	assert(t1.size() == 0);
	assert(t2.size() == 0);
	assert(t3.size() == 0);

	t1.insert(12345);
	t1.insert(23456);
	t1.insert(34567);
	assert(t1.size() == 3); // Set size should change accordingly
	t1.insert(45678);
	t1.insert(56789);
	t1.insert(67890);
	assert(t1.size() == 6);
	assert(!t1.empty()); // With 6 elements Set t1 is no longer empty

	assert(!t1.insert(12345)); // 12345 is already contained in t1
	assert(t1.size() == 6); // Failed insertion should not alter t1
	assert(!t1.erase(1234567890)); // Cannot erase an element not in t1
	assert(t1.size() == 6); // Failed erase should not alter t1
	t1.erase(67890); 
	t1.erase(56789);
	assert(t1.size() == 4); // Set size should change accordingly
	t1.erase(45678);
	t1.erase(34567);
	t1.erase(23456);
	t1.erase(12345);
	assert(t1.size() == 0); // Erasing everything should leave an empty Set of size 0
	assert(t1.empty());

	assert(!t1.contains(12345)); // Due to erasing, these elements no longer exist in t1
	assert(!t1.contains(23456));
	assert(!t1.contains(34567));
	assert(!t1.contains(45678));
	assert(!t1.contains(56789));
	assert(!t1.contains(67890));

	assert(!t1.get(0, long1)); // t1 is empty
	assert(!t1.get(3, long1)); // t1 is empty
	assert(!t1.get(-1, long1)); // Invalid index parameter

	assert(t2.insert(1234567890));
	assert(t2.get(0, long2)); // Writes 1234567890 into long2
	assert(long2 == 1234567890); // Assert long2 has been written over
	assert(t2.erase(1234567890));
	assert(t2.empty()); 

	///////////////////////////////
	// Advanced Test Cases
	///////////////////////////////
	// First, fill test Sets with elements
	t1.insert(123); // Begin insertion for Set t1
	t1.insert(1234); 
	t1.insert(12345);
	t1.insert(123456);
	t1.insert(1234567);
	t1.insert(12345678);
	t2.insert(1); // Begin insertion for Set t2
	t2.insert(2);
	t2.insert(3);
	t3.insert(11111); // Begin insertion for Set t3
	t3.insert(22222);
	t3.insert(33333);
	t3.insert(99999);

	t1.swap(t3); // Swap t1 with t3
	assert(t1.size() == 4); // t1 now has t3's size of 4 elements
	assert(t1.get(0, long1)); // Affirm t1 now has t3's elements
	assert(long1 == 11111);
	assert(t1.get(1, long1));
	assert(long1 == 22222);
	assert(t1.get(2, long1));
	assert(long1 == 33333);
	assert(t1.get(3, long1));
	assert(long1 == 99999);
	assert(t3.size() == 6); // t3 now has t1's size of 6 elements
	assert(t3.get(0, long3)); // Affirm t3 now has t1's elements
	assert(long3 == 123);
	assert(t3.get(1, long3));
	assert(long3 == 1234);
	assert(t3.get(2, long3));
	assert(long3 == 12345);
	assert(t3.get(3, long3));
	assert(long3 == 123456);
	assert(t3.get(4, long3));
	assert(long3 == 1234567);
	assert(t3.get(5, long3));
	assert(long3 == 12345678);
	t1.swap(t3); // For testing purposes, swap t1 and t3 back to originals
	assert(t1.size() == 6); // Assert t1 and t3's original sizes again
	assert(t3.size() == 4);

	t2.swap(t2); // t2 should remain unchanged with aliasing
	assert(t2.size() == 3); // Affirm t2's elements remain unchanged
	assert(t2.get(0, long2));
	assert(long2 == 1);
	assert(t2.get(1, long2));
	assert(long2 == 2);
	assert(t2.get(2, long2));
	assert(long2 == 3);

	Set t4 = t3; // Copy Constructor in effect
	assert(t4.size() == 4); // Assert t4 has copied t3's size
	
	// Essentially swap t3 & t1 via Assignment Operator; run above cases again
	t3 = t1; t1 = t4; 
	assert(t1.size() == 4); // t1 now has t3's size of 4 elements
	assert(t1.get(0, long1)); // Affirm t1 now has t3's elements
	assert(long1 == 11111);
	assert(t1.get(1, long1));
	assert(long1 == 22222);
	assert(t1.get(2, long1));
	assert(long1 == 33333);
	assert(t1.get(3, long1));
	assert(long1 == 99999);
	assert(t3.size() == 6); // t3 now has t1's size of 6 elements
	assert(t3.get(0, long3)); // Affirm t3 now has t1's elements
	assert(long3 == 123);
	assert(t3.get(1, long3));
	assert(long3 == 1234);
	assert(t3.get(2, long3));
	assert(long3 == 12345);
	assert(t3.get(3, long3));
	assert(long3 == 123456);
	assert(t3.get(4, long3));
	assert(long3 == 1234567);
	assert(t3.get(5, long3));
	assert(long3 == 12345678);
	t1.swap(t3); // For testing purposes, swap t1 and t3 back to originals
	assert(t1.size() == 6); // Assert t1 and t3's original sizes again
	assert(t3.size() == 4);

	///////////////////////////////
	// Unite/Subtract Test Cases
	///////////////////////////////
	Set test1, test2, test3, test4, test5; // test4 and test5 will be empty
	test1.insert(1); // Begin insertion for Set test1
	test1.insert(4);
	test1.insert(5);
	test2.insert(2); // Begin insertion for Set test2
	test2.insert(3);
	test2.insert(4);
	test3.insert(3); // Begin insertion for Set test3
	test3.insert(6);
	test3.insert(7);

	unite(test1, test2, test3);
	assert(test3.size() == 5); // test3 should contain 1, 2, 3, 4, 5
	assert(test3.get(0, long2));
	assert(long2 == 1);
	assert(test3.get(1, long2));
	assert(long2 == 2);
	assert(test3.get(2, long2));
	assert(long2 == 3);
	assert(test3.get(3, long2));
	assert(long2 == 4);
	assert(test3.get(4, long2));
	assert(long2 == 5);

	unite(test1, test2, test1);
	assert(test1.size() == 5); // test1 should contain 1, 2, 3, 4, 5
	assert(test1.get(0, long2));
	assert(long2 == 1);
	assert(test1.get(1, long2));
	assert(long2 == 2);
	assert(test1.get(2, long2));
	assert(long2 == 3);
	assert(test1.get(3, long2));
	assert(long2 == 4);
	assert(test1.get(4, long2));
	assert(long2 == 5);

	unite(test1, test1, test1); // test1 should remain unchanged
	assert(test1.size() == 5); 
	assert(test1.get(0, long2));
	assert(long2 == 1);
	assert(test1.get(1, long2));
	assert(long2 == 2);
	assert(test1.get(2, long2));
	assert(long2 == 3);
	assert(test1.get(3, long2));
	assert(long2 == 4);
	assert(test1.get(4, long2));
	assert(long2 == 5);

	unite(test1, test1, test3); // All three parameters contain the same elements here
	assert(test3.size() == 5);

	unite(test1, test4, test3); // test4 is empty, therefore test3 is unchanged from above
	assert(test3.size() == 5);

	unite(test4, test4, test4); // Union of two empty Sets is the empty Set
	assert(test4.empty());

	subtract(test1, test2, test3);
	assert(test3.size() == 2); // test3 should contain 1, 5
	assert(test3.get(0, long2));
	assert(long2 == 1);
	assert(test3.get(1, long2));
	assert(long2 == 5);

	subtract(test1, test3, test2);
	assert(test2.size() == 3); // test2 should contain 2, 3, 4
	assert(test2.get(0, long2));
	assert(long2 == 2);
	assert(test2.get(1, long2));
	assert(long2 == 3);
	assert(test2.get(2, long2));
	assert(long2 == 4);

	subtract(test2, test2, test3);
	assert(test3.empty()); // test2 subtracted with test2 results in the empty Set

	subtract(test1, test4, test3);
	assert(test3.size() == 5); // Since test4 is empty, result is test1

	subtract(test4, test4, test4); // An empty Set has no unique elements
	assert(test4.empty()); */

	std::cout << "Passed all tests!" << std::endl;
}
