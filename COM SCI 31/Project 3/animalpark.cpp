#include <iostream>
#include <cassert>
#include <string>
#include <locale>
using namespace std;

bool isValidAnimalParkString(string animalparkString);
int dogsLeft(string animalparkString);
int catsLeft(string animalparkString);
int peopleLeft(string animalparkString);

int main()
{
	string apString;
	
	while (true)
	{
		cout << "Please enter an animal park string: ";
		getline(cin, apString);

		bool y = isValidAnimalParkString(apString);
		int dogs = dogsLeft(apString);
		int cats = catsLeft(apString);
		int people = peopleLeft(apString);

		if (y == 1)
		{
			cout << "true" << endl;
			cout << "Number of dogs left: " << dogs << endl;
			cout << "Number of cats left: " << cats << endl;
			cout << "Number of people left: " << people << endl;
		}
		else
		{
			cout << "false" << endl;
		}

		if (apString == "quit")
			break;
	}
}

// Checks basic conditions for potentially valid animalparkStrings
bool stringformatChecker(string animalparkString)
{
	// Returns false for an empty string
	if (animalparkString == "") 
	{
		return false;
	}

	// Returns false if string doesn't start with a pet
	char letter = animalparkString[0];
	if (tolower(letter) != 'c' && tolower(letter) != 'd') 
	{
		return false;
	}

	// Returns false if string contains nonvalid characters
	for (int i = 0; i < animalparkString.length(); i++)
	{
		if (tolower(animalparkString[i]) != 'c' && tolower(animalparkString[i]) != 'd' &&
			tolower(animalparkString[i]) != 'p' && tolower(animalparkString[i]) != '+' &&
			tolower(animalparkString[i]) != '-')
		{
			return false;
		}
	}

	// Returns false if string doesn't end with a person
	int i = animalparkString.length() - 1;
	if (tolower(animalparkString[i]) != 'p')
	{
		return false;
	}

	return true;
}

// Checks numerical arithmetic for potentially valid animalparkStrings
bool stringnumericalChecker(string animalparkString)
{
	// If stringformatChecker is false, this function will return false also
	if (stringformatChecker(animalparkString))
	{
		int i = 0; // Counter for while loop below
		bool isPositive = true; // True if people or pets are entering
		bool isNegative = false; // True if people or pets are leaving
		string repository = ""; // Keeps track of entities in the park
		while (true)
		{
			// First checks for a sign change, then performs operations as implemented
			if (animalparkString[i] == '+' || animalparkString[i] == '-')
			{
				// Sets the boolean values to indicate for the proper sign accordingly
				if (animalparkString[i] == '+')
				{
					isPositive = true;
					isNegative = false;
				}
				else
				{
					isNegative = true;
					isPositive = false;
				}
			}
			else if (isPositive)
			{
				repository += animalparkString[i]; // Adds character to repository
			}
			else if (isNegative)
			{
				// Checks if character exists in repository & removes it, or returns false
				if (repository.find(animalparkString[i]) == string::npos)
				{
					return false;
				}
				else
				{
					int index = repository.find(animalparkString[i]);
					repository.erase(index, 1); // Removes character
				}
			}

			// Break condition (iterated through animalparkString)
			if (i == (animalparkString.length() - 1))
			{
				break;
			}

			i++;
		}
	}
	else
	{
		return false;
	}

	return true;
}

// Checks for validity of animalparkStrings
bool isValidAnimalParkString(string animalparkString)
{
	// If both functions are true, we check for string validity, otherwise false
	// There may be edge cases (e.g. ccP-Pcc), which this function will cover
	if (stringformatChecker(animalparkString) && stringnumericalChecker(animalparkString))
	{
		// Iterates over the entire animalparkString
		for (int i = 0; i < animalparkString.length(); i++)
		{
			// If not on first character, checks to see if previous character is different
			if (i != 0)
			{
				if (tolower(animalparkString[i]) != tolower(animalparkString[i - 1]))
				{
					if (tolower(animalparkString[i]) == 'd' || tolower(animalparkString[i]) == 'c')
					{
						// If different, pets can only appear after a +/-
						if (animalparkString[i - 1] != '+' && animalparkString[i - 1] != '-')
						{
							return false;
						}
					}
					else if (tolower(animalparkString[i]) == 'p')
					{
						// People can only appear after pets, not after a sign [for example]
						if (tolower(animalparkString[i - 1]) != 'd' && tolower(animalparkString[i - 1]) != 'c')
						{
							return false;
						}
					}
					else if (animalparkString[i] == '+' || animalparkString[i] == '-')
					{
						// Signs can only appear after people
						if (tolower(animalparkString[i - 1]) != 'p')
						{
							return false;
						}
					}
				}
				else if (animalparkString[i] == animalparkString[i - 1])
				{
					// Ensures you cannot have ++ and -- appear in the string
					if (animalparkString[i] == '+' || animalparkString[i] == '-')
					{
						return false;
					}
				}
			}
		}
	}
	else
	{
		return false;
	}
	
	return true;
}

// Checks for number of dogs left
int dogsLeft(string animalparkString)
{
	int numDogs = 0; 
	bool isPositive = true; // True if entities are entering the park
	bool isNegative = false; // True if entities are leaving the park
	string dogRepository = ""; // Keeps track of dogs in the park

	// If isValidAnimalParkString returns false, dogsLeft will return -1
	if (isValidAnimalParkString(animalparkString))
	{
		// Iterates over the entire animalparkString
		for (int i = 0; i < animalparkString.length(); i++)
		{
			// Checks if character (when made lowercase) is a dog, otherwise if it's a sign
			if (tolower(animalparkString[i]) == 'd')
			{
				// If positive, adds to repository, otherwise removes from repository
				if (isPositive)
				{
					dogRepository += animalparkString[i];
				}
				else if (isNegative)
				{
					int index = dogRepository.find(animalparkString[i]);
					dogRepository.erase(index, 1);
				}
			}
			else if (animalparkString[i] == '+' || animalparkString[i] == '-')
			{
				// Sets the boolean markers accordingly
				if (animalparkString[i] == '+')
				{
					isPositive = true;
					isNegative = false;
				}
				else
				{
					isPositive = false;
					isNegative = true;
				}
			}
		}

		// Number of dogs is the repository length (since repository contains d or D only)
		numDogs = dogRepository.length();
		return(numDogs);
	}
	else
	{
		numDogs = -1;
		return(numDogs);
	}
}

// Checks for number of cats left
int catsLeft(string animalparkString)
{
	int numCats = 0;
	bool isPositive = true; // True if entities are entering the park
	bool isNegative = false; // True if entities are leaving the park
	string catRepository = ""; // Keeps track of cats in the park

	// If isValidAnimalParkString returns false, catsLeft will return -1
	if (isValidAnimalParkString(animalparkString))
	{
		// Iterates over the entire animalparkString
		for (int i = 0; i < animalparkString.length(); i++)
		{
			// Checks if character (when made lowercase) is a cat, otherwise if it's a sign
			if (tolower(animalparkString[i]) == 'c')
			{
				// If positive, adds to repository, otherwise removes from repository
				if (isPositive)
				{
					catRepository += animalparkString[i];
				}
				else if (isNegative)
				{
					int index = catRepository.find(animalparkString[i]);
					catRepository.erase(index, 1);
				}
			}
			else if (animalparkString[i] == '+' || animalparkString[i] == '-')
			{
				// Sets the boolean markers accordingly
				if (animalparkString[i] == '+')
				{
					isPositive = true;
					isNegative = false;
				}
				else
				{
					isPositive = false;
					isNegative = true;
				}
			}
		}

		// Number of cats is the repository length (since repository contains c or C only)
		numCats = catRepository.length();
		return(numCats);
	}
	else
	{
		numCats = -1;
		return(numCats);
	}
}

// Checks for number of people left
int peopleLeft(string animalparkString)
{
	int numPeople = 0;
	bool isPositive = true; // True if entities are entering the park
	bool isNegative = false; // True if entities are leaving the park
	string peopleRepository = ""; // Keeps track of people in the park

	// If isValidAnimalParkString returns false, peopleLeft will return -1
	if (isValidAnimalParkString(animalparkString))
	{
		// Iterates over the entire animalparkString
		for (int i = 0; i < animalparkString.length(); i++)
		{
			// Checks if character (when made lowercase) is human, otherwise if it's a sign
			if (tolower(animalparkString[i]) == 'p')
			{
				// If positive, adds to repository, otherwise removes from repository
				if (isPositive)
				{
					peopleRepository += animalparkString[i];
				}
				else if (isNegative)
				{
					int index = peopleRepository.find(animalparkString[i]);
					peopleRepository.erase(index, 1);
				}
			}
			else if (animalparkString[i] == '+' || animalparkString[i] == '-')
			{
				// Sets the boolean markers accordingly
				if (animalparkString[i] == '+')
				{
					isPositive = true;
					isNegative = false;
				}
				else
				{
					isPositive = false;
					isNegative = true;
				}
			}
		}

		// Number of people is the repository length (since repository contains p or P only)
		numPeople = peopleRepository.length();
		return(numPeople);
	}
	else
	{
		numPeople = -1;
		return(numPeople);
	}
}