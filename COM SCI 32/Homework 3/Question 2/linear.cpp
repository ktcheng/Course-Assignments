////////////////////////////////
// Remove #include directives!
////////////////////////////////
#include <iostream>
#include <cassert>

/////////////////////////////////////////////////////////
// somePredicate Declaration (remove before submission)
/////////////////////////////////////////////////////////
bool somePredicate(const std::string s)
{
	return(s.empty()); // True if the string is empty, false otherwise
}

bool allFalse(const std::string a[], int n)
{
	bool everyFalse = true; // Keeps track of false history

	// If we inspect none or an invalid number, return true
	if (n <= 0)
	{
		return(true);
	}

	// If somePredicate is true, set everyFalse to be false
	if (somePredicate(a[n - 1])) // Highest index is n - 1
	{
		everyFalse = false;
	}

	// If everyFalse is false, return immediately
	if (!everyFalse)
	{
		return(everyFalse);
	}

	return(allFalse(a, n - 1)); // Recursive call to inspect previous element
}

int countFalse(const std::string a[], int n)
{
	int count = 0;

	// If we inspect none or an invalid number, return 0
	if (n <= 0)
	{
		return(count);
	}

	// If somePredicate is false, increment count
	if (!somePredicate(a[n - 1])) // Highest index is n - 1
	{
		count++;
	}

	// Find total count from previous recursive calls
	int precount = countFalse(a, n - 1);
	count += precount;

	return(count);
}

int firstFalse(const std::string a[], int n)
{
	int first = -1; 

	// If we inspect none or an invalid number, return -1
	if (n <= 0)
	{
		return(first);
	}

	// If somePredicate is false, set first to that index
	if (!somePredicate(a[n - 1]))
	{
		first = n - 1;
	}

	int prefirst = firstFalse(a, n - 1); // Calculate previous index using recursion

	// If prefirst is valid, assign first to prefirst
	if (prefirst >= 0)
	{
		first = prefirst; 
	}

	return(first);
}

int locateMaximum(const std::string a[], int n)
{
	int maxIndex = -1;

	// If we inspect none or an invalid number, return -1
	if (n <= 0)
	{
		return(maxIndex);
	}
	else if (n == 1)
	{
		maxIndex = 0;
	}
	else // n > 1
	{
		// Use recursion to gather successive "maximum" index
		int premax = locateMaximum(a, n - 1);

		// Compute the index with the maximum string
		if (a[n - 1] > a[premax])
		{
			maxIndex = n - 1;
		}
		else
		{
			maxIndex = premax;
		}
	}

	return(maxIndex);
}

bool contains(const std::string a1[], int n1, const std::string a2[], int n2)
{
	bool isContained; 

	if (n2 <= 0)
	{
		// Regardless of n1, if n2 <= 0, it is contained
		isContained = true;
	}
	else if (n1 <= 0)
	{
		// If n1 is invalid but n2 is valid, it cannot be contained
		isContained = false;
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
					isContained = contains(a1, n1 - 1, a2, n2 - 1);
				}
				else
				{
					isContained = true;
				}
			}
			else if (n1 > n2)
			{
				// Recursively call contains, decrementing n1 only
				isContained = contains(a1, n1 - 1, a2, n2);
			}
			else
			{
				isContained = false;
			}
		}
		else
		{
			isContained = false;
		}
	}

	return(isContained);
}

////////////////////////////////////////////////
// Comment out main routine before submission
////////////////////////////////////////////////
int main()
{
	std::cout << "It builds!" << std::endl;
	std::cout.setf(std::ios::boolalpha);

	////////////////////////////////////////////////
	// Test Cases
	////////////////////////////////////////////////
	// Test std::string Arrays
	std::string filler[5] = {};
	std::string filler1[] = { "table", "cup", "drawer", "chair", "whiteboard" };
	std::string filler2[] = { "", "bedroom", "foyer", "bathroom", "living room" };
	std::string filler3[] = { "laptop", "smartphone", "smartwatch", "tablet", "television", "" };

	std::string max1[] = { "a", "b", "c", "d" };
	std::string max2[] = { "Z", "X", "A", "C" };

	///////////////////////////////////////////////
	// bool allFalse(const std::string a[], int n)
	///////////////////////////////////////////////
	{assert(!allFalse(filler, 5));
	assert(allFalse(filler1, 5));
	assert(!allFalse(filler2, 5)); // Filler2's test cases
	assert(allFalse(filler2 + 1, 4));
	assert(allFalse(filler2 + 1, 3));
	assert(allFalse(filler2 + 1, 2));
	assert(allFalse(filler2 + 1, 1));
	assert(allFalse(filler2, 0));
	assert(allFalse(filler2, -1));
	assert(!allFalse(filler3, 6)); // Filler3's test cases
	assert(allFalse(filler3, 5));
	assert(allFalse(filler3, 4));
	assert(allFalse(filler3, 3));
	assert(allFalse(filler3, 2));
	assert(allFalse(filler3, 1));
	assert(allFalse(filler3, 0)); }

	////////////////////////////////////////////////
	// int countFalse(const std::string a[], int n)
	////////////////////////////////////////////////
	{assert(countFalse(filler, 5) == 0); // Filler's test cases
	assert(countFalse(filler, 4) == 0);
	assert(countFalse(filler, 3) == 0);
	assert(countFalse(filler, 2) == 0);
	assert(countFalse(filler, 1) == 0);
	assert(countFalse(filler, 0) == 0);
	assert(countFalse(filler, -1) == 0);
	assert(countFalse(filler1, 5) == 5); // Filler1's test cases
	assert(countFalse(filler1, 4) == 4);
	assert(countFalse(filler1, 3) == 3);
	assert(countFalse(filler1, 2) == 2);
	assert(countFalse(filler1, 1) == 1);
	assert(countFalse(filler1, 0) == 0); 
	assert(countFalse(filler2, 5) == 4); // Filler2's test cases
	assert(countFalse(filler2, 4) == 3);
	assert(countFalse(filler2, 3) == 2);
	assert(countFalse(filler2, 2) == 1);
	assert(countFalse(filler2, 1) == 0);
	assert(countFalse(filler3, 6) == 5); // Filler3's test cases
	assert(countFalse(filler3, 5) == 5);
	assert(countFalse(filler3 + 1, 5) == 4);
	assert(countFalse(filler3 + 2, 4) == 3);
	assert(countFalse(filler3 + 3, 3) == 2);
	assert(countFalse(filler3 + 4, 2) == 1);
	assert(countFalse(filler3 + 5, 1) == 0);}

	////////////////////////////////////////////////
	// int firstFalse(const std::string a[], int n)
	////////////////////////////////////////////////
	{assert(firstFalse(filler, 5) == -1);
	assert(firstFalse(filler1, 5) == 0); // Filler1's test cases
	assert(firstFalse(filler1, 4) == 0);
	assert(firstFalse(filler1, 3) == 0);
	assert(firstFalse(filler1, 2) == 0);
	assert(firstFalse(filler1, 1) == 0);
	assert(firstFalse(filler1 + 1, 4) == 0);
	assert(firstFalse(filler1 + 2, 3) == 0);
	assert(firstFalse(filler1 + 3, 2) == 0);
	assert(firstFalse(filler1 + 4, 1) == 0);
	assert(firstFalse(filler2, 5) == 1); // Filler2's test cases
	assert(firstFalse(filler2 + 1, 4) == 0);
	assert(firstFalse(filler3, 6) == 0); // Filler3's test cases
	assert(firstFalse(filler3 + 1, 5) == 0);
	assert(firstFalse(filler3 + 2, 4) == 0);
	assert(firstFalse(filler3 + 3, 3) == 0);
	assert(firstFalse(filler3 + 4, 2) == 0);
	assert(firstFalse(filler3 + 5, 1) == -1); }

	///////////////////////////////////////////////////
	// int locateMaximum(const std::string a[], int n)
	///////////////////////////////////////////////////
	{assert(locateMaximum(max1, 4) == 3); // Max1's test cases
	assert(locateMaximum(max1 + 1, 3) == 2);
	assert(locateMaximum(max1 + 2, 2) == 1);
	assert(locateMaximum(max1 + 3, 1) == 0);
	assert(locateMaximum(max2, 4) == 0); // Max2's test cases
	assert(locateMaximum(max2 + 1, 3) == 0);
	assert(locateMaximum(max2 + 2, 2) == 1);
	assert(locateMaximum(max2 + 2, 1) == 0);
	assert(locateMaximum(max2 + 2, 0) == -1);
	assert(locateMaximum(max2 + 3, -1) == -1);
	assert(locateMaximum(max2 + 3, 1) == 0); }

	// Contains Test std::string Arrays
	std::string str1[] = { "stan", "kyle", "cartman", "kenny", "kyle",
		"cartman", "butters" };
	std::string str2[] = { "kyle", "kenny", "butters" };
	std::string str3[] = { "kyle", "cartman", "cartman" };
	std::string str4[] = { "kyle", "butters", "kenny" };
	std::string str5[] = { "stan", "kenny", "kenny" };
	std::string tester[] = {"stan"};
	
	/////////////////////////////////////////////////////////////////////////////////
	// bool contains(const std::string a1[], int n1, const std::string a2[], int n2)
	/////////////////////////////////////////////////////////////////////////////////
	assert(contains(str1, 7, str2, 3));
	assert(contains(str1, 7, str3, 3));
	assert(!contains(str1, 7, str4, 3));
	assert(!contains(str1, 7, str5, 3));
	assert(contains(str1, 7, str4, 2));
	assert(contains(str1, 7, str5 + 1, 1));
	assert(contains(str5, 3, tester, 1));
	assert(contains(str1, 7, tester, 1));
}