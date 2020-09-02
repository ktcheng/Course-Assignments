#include <iostream>
#include <string>
using namespace std;

int locateMaximum(const string array[], int n);

bool hasDuplicates(const string array[], int n);

int countSs(const string array[], int n);

int shiftLeft(string array[], int n, int amount, string placeholderToFillEmpties);

bool isInDecreasingOrder(const string array[], int n);

bool matchingValuesTogether(const string array[], int n);

int divide(string array[], int n, string divider);

int main()
{
	cout.setf(ios::boolalpha);

	string friends[9] = {"Franklin", "Amy", "Susan", "Allan", "Sajan", 
		"Zechariah", "franklin", "jon", "Shyam"};
	
	string literals[10] = {"1", "0", "19", "3", "9", "10", " ", "65", "54", "hi"};
	
	string duplicates[7] = {"hi", "Hi", "hI", "HI", "hi", "Hi", " HI"};

	string decreasing[5] = {"z", "x", "w", "Z", "a"};

	string decreasingNumbers[6] = {"90", "9", "7", "34", "20", "8"};

	string matching[4] = {"x", "x", "x", "x"};
	
	string alsoMatching[6] = {"a", "a", "", "xyz", "a", "a"};

	return(0);
}

int locateMaximum(const string array[], int n)
{
	int maxIndex = 0; // Variable for maximum value index
	string maxString = ""; // Variable for maximum comparison

	if (n <= 0)
	{
		maxIndex = -1;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (i != 0) 
			{
				if (array[i] > maxString) // Check for new maximum
				{
					maxString = array[i];
					maxIndex = i;
				}
			}
			else // If first element, by default set as maximum
			{
				maxString = array[i];
			}
		}
	}

	return(maxIndex);
}

bool hasDuplicates(const string array[], int n)
{
	
	if (n <= 0)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < n; i++) // Loops through array
		{
			for (int j = 0; j < n; j++) // Loops through for each element
			{
				if (j != i) // Eliminates comparison of same index
				{
					if (array[j] == array[i])
					{
						return true;
					}
				}
			}
		}
	}

	return(false);
}

int countSs(const string array[], int n)
{
	int sCounter = 0; // Variable for # of s

	if (n <= 0)
	{
		return(-1);
	}

	for (int i = 0; i < n; i++) // Loops through array
	{
		// Loops through all characters in each array item
		for (int j = 0; j < array[i].length(); j++)
		{
			if (tolower(array[i][j]) == 's')
			{
				sCounter += 1;
			}
		}
	}

	return(sCounter);
}

int shiftLeft(string array[], int n, int amount, string placeholderToFillEmpties)
{
	if (n <= 0 || amount <= 0)
	{
		return(0);
	}
	else if (amount >= n)
	{
		for (int i = 0; i < n; i++)
		{
			// Since max is n, replace n values with placeholder
			array[i] = placeholderToFillEmpties;
		}

		return(n);
	}
	else
	{
		int leftover = n - amount; // Offset amount

		for (int i = 0; i < n; i++)
		{
			if (i < leftover)
			{
				// Replace with the new shifted values
				array[i] = array[i + amount];
			}
			else
			{
				// Populate remaining spots with placeholder
				array[i] = placeholderToFillEmpties;
			}
		}
		
		return(amount);
	}
}

bool isInDecreasingOrder(const string array[], int n)
{
	if (n <= 0)
	{
		return(false);
	}
	else
	{
		for (int i = 1; i < n; i++)
		{
			// If any item violates this rule, return false
			if (!(array[i] < array[i - 1]))
			{
				return(false);
			}
		}
	}

	return(true);
}

bool matchingValuesTogether(const string array[], int n)
{
	bool checkerFlag = true; 
	// Variable for enabling certain operations...seen below
	if (n <= 0)
	{
		return(false);
	}
	if (hasDuplicates(array, n))
	{
		for (int i = 0; i < n; i++) // Loops through array
		{
			for (int j = 0; j < i; j++) // Loops up to current element
			{
				if (array[j] == array[i]) 
				{
					// Checks case for multiple duplicates in a row
					if (j != i - 1)
					{
						// Loops between duplicate and current element
						for (int k = j; k < i; k++) 
						{
							// If any not all the same, change enabling variable
							if (array[k] != array[j])
							{
								checkerFlag = false;
							}
						}

						if (!checkerFlag)
						{
							return(false);
						}
					}
				}
			}
		}
	}
	else // If no duplicates, principle is not violated
	{
		return(true);
	}

	return(true);
}

int divide(string array[], int n, string divider)
{
	int numLess = 0; // Variable for # of items less than divider
	string placeholder = ""; // Placeholder needed for array sorting

	if (n <= 0)
	{
		return(numLess);
	}
	else
	{
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (array[j] > array[i])
				{
					placeholder = array[j]; // Sets placeholder
					array[j] = array[i]; // Sets < item in front
					array[i] = placeholder; // Sets > item in back
				}
			}
		}

		// After sorting, count items less than divider
		for (int i = 0; i < n; i++)
		{
			if (array[i] < divider)
			{
				numLess += 1;
			}
		}
	}

	return(numLess);
}