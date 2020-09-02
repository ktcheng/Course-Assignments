#include <iostream>
#include <cassert>

// countContains implementation: Branch off on each matching string for all cases
int countContains(const std::string a1[], int n1, const std::string a2[], int n2)
{
	int count = 0; // Keeps track of number of possibilities

	if (n2 <= 0)
	{
		// Regardless of n1, if n2 <= 0, there is one possibility
		count = 1;
	}
	else if (n1 <= 0)
	{
		// If n1 is invalid but n2 is valid, there is no possibility
		count = 0;
	}
	else
	{
		// If n2 strictly > n1, there is also no possibility
		if (n2 <= n1)
		{
			if (a1[n1 - 1] == a2[n2 - 1])
			{
				if (n1 != 1 && n2 != 1)
				{
					// If not inspecting the base case, call recursively
					count += countContains(a1, n1 - 1, a2, n2 - 1);
				}
				else
				{
					// We are at the base case, therefore increment count
					count++;
				}
			}

			// For no match, if n2
			// If they don't match, if n1 > n2, decrement n1
			if (n1 > n2)
			{
				count += countContains(a1, n1 - 1, a2, n2);
			}
		}
	}

	return(count);
}

void exchange(std::string& x, std::string& y)
{
	std::string t = x;
	x = y;
	y = t;
}

void divide(std::string a[], int n, std::string divider, int& firstNotLess, int& firstGreater)
{
	if (n < 0)
		n = 0;

	// It will always be the case that just before evaluating the loop
	// condition:
	//  firstNotLess <= firstUnknown and firstUnknown <= firstGreater
	//  Every element earlier than position firstNotLess is < divider
	//  Every element from position firstNotLess to firstUnknown-1 is
	//    == divider
	//  Every element from firstUnknown to firstGreater-1 is not known yet
	//  Every element at position firstGreater or later is > divider

	firstNotLess = 0;
	firstGreater = n;
	int firstUnknown = 0;
	while (firstUnknown < firstGreater)
	{
		if (a[firstUnknown] > divider)
		{
			firstGreater--;
			exchange(a[firstUnknown], a[firstGreater]);
		}
		else
		{
			if (a[firstUnknown] < divider)
			{
				exchange(a[firstNotLess], a[firstUnknown]);
				firstNotLess++;
			}
			firstUnknown++;
		}
	}
}

// order implementation: Split array, ordering each part separately
void order(std::string a[], int n)
{
	// Do nothing if we are inspecting 1 or less elements
	if (n <= 1)
	{
		return;
	}

	// Declare firstNotLess, firstGreater and midpoint parameters
	int firstNotLess = 0, firstGreater = 0, mid = n / 2;

	// Divide the array in half
	divide(a, n, a[mid], firstNotLess, firstGreater);
	order(a, firstNotLess); // Order the first half of the array
	order(a + firstGreater, n - firstGreater); // Order back half of the array
}

////////////////////////////////////////////
// Remove main routine (before submission)
////////////////////////////////////////////
int main()
{
	std::cout << "It builds!" << std::endl;
	std::cout.setf(std::ios::boolalpha);
	////////////////////////////////////////
	// Test std::string Arrays
	////////////////////////////////////////
	std::string a1[] = { "stan", "kyle", "cartman", "kenny", "kyle", "cartman", "butters" };
	std::string a2[] = { "kyle", "cartman", "butters" };
	std::string a3[] = { "kyle", "cartman", "butters" };
	std::string str1[] = { "2", "0", "8", "4", "5", "1", "9", "3", "8", "6", "7" };
	std::string str2[] = { "cartman", "butters", "kyle" };
	std::string str3[] = { "9", "8", "5", "7", "6" };
	std::string str4[] = { "z", "c", "o", "y", "t", "l", "p" };
}