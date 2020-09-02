#include <iostream>
#include <string>
using namespace std;

int main()
{
	string vehicle_model, vehicle_kind, vehicle_color, leather_interiorYN, autopilotYN, vehicle_wheels; // Declares variables needed
	double price = 0.0; // Sets price 

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2); // Numbers will display 2 decimal places for monetary purposes

	cout << "Which vehicle would you like to order? "; // Prompts user for vehicle model
	getline(cin, vehicle_model);

	if (vehicle_model != "3" && vehicle_model != "S" && vehicle_model != "X") // Checks for valid vehicle model
	{
		cout << "Error - Incorrect model choice." << endl;
		return(-1);
	}

	/// --------------------------------------------------

	cout << "Which kind would you like? "; // Prompts user for vehicle type
	getline(cin, vehicle_kind);

	if (vehicle_kind != "Long Range" && vehicle_kind != "Performance") // Checks for valid vehicle kind
	{
		cout << "Error - Incorrect kind choice." << endl;
		return(-1);
	}
	else if (vehicle_kind == "Long Range") // Adds long range model prices accordingly
	{
		if (vehicle_model == "3")
		{
			price += 47990;
		}
		else if (vehicle_model == "S")
		{
			price += 79990;
		}
		else
		{
			price += 84990;
		}
	}
	else // Adds performance model prices accordingly
	{
		if (vehicle_model == "3")
		{
			price += 55990;
		}
		else if (vehicle_model == "S")
		{
			price += 99990;
		}
		else
		{
			price += 104990;
		}
	}

	/// --------------------------------------------------

	cout << "What exterior color would you like? "; // Prompts user for vehicle color
	getline(cin, vehicle_color);

	if (vehicle_color != "White" && vehicle_color != "Black" && vehicle_color != "Blue"
		&& vehicle_color != "Grey" && vehicle_color != "Red") // Checks for valid vehicle color
	{
		cout << "Error - Incorrect color choice." << endl;
		return(-1);
	}
	else if (vehicle_color == "Black") // Adds black paint job price
	{
		if (vehicle_model == "3")
		{
			price += 500;
		}
		else
		{
			price += 1000;
		}
	}
	else if (vehicle_color == "Blue" || vehicle_color == "Grey") // Adds blue/grey paint job price
	{
		if (vehicle_model == "3")
		{
			price += 1000;
		}
		else
		{
			price += 1500;
		}
	}
	else if (vehicle_color == "Red") // Adds red paint job price
	{
		if (vehicle_model == "3")
		{
			price += 1500;
		}
		else
		{
			price += 2500;
		}
	}

	/// --------------------------------------------------

	cout << "Which wheels would you like? "; // Prompts user for vehicle tire size
	getline(cin, vehicle_wheels);

	if (vehicle_model == "3" && vehicle_wheels != "18" && vehicle_wheels != "19") // Checks for valid Model 3 tire sizes
	{
		cout << "Error - Incorrect wheel value." << endl;
		return(-1);
	}
	else if (vehicle_model == "S" && vehicle_wheels != "19" && vehicle_wheels != "21") // Checks for valid Model S tire sizes
	{
		cout << "Error - Incorrect wheel value." << endl;
		return(-1);
	}
	else if (vehicle_model == "X" && vehicle_wheels != "20" && vehicle_wheels != "22") // Checks for valid Model X tire sizes
	{
		cout << "Error - Incorrect wheel value." << endl;
		return(-1);
	}
	else if (vehicle_model == "3") // Adds size 19 extra price for Model 3
	{
		if (vehicle_wheels == "19")
		{
			price += 1500;
		}
	}
	else if (vehicle_model == "S") // Adds size 21 extra price for Model S
	{
		if (vehicle_wheels == "21")
		{
			price += 4500;
		}
	}
	else if (vehicle_model == "X") // Adds size 22 extra price for Model X
	{
		if (vehicle_wheels == "22")
		{
			price += 5500;
		}
	}

	/// --------------------------------------------------
	
	cout << "Want leather interior? "; // Prompts user for vehicle leather options
	getline(cin, leather_interiorYN);

	if (leather_interiorYN != "Yes" && leather_interiorYN != "No") // Checks for valid leather option
	{
		cout << "Error - Incorrect leather choice." << endl;
		return(-1);
	}
	else if (leather_interiorYN == "Yes") // Adds interior leather price
	{
		price += 1000;
	}

	/// --------------------------------------------------
	
	cout << "Want Auto-Pilot? "; // Prompts user for vehicle autopilot options
	getline(cin, autopilotYN);

	if (autopilotYN != "Yes" && autopilotYN != "No") // Checks for valid autopilot option
	{
		cout << "Error - Incorrect autopilot choice." << endl;
		return(-1);
	}
	else if (autopilotYN == "Yes") // Adds internal autopilot price
	{
		price += 6000;
	}

	/// --------------------------------------------------
	
	cout << "Enjoy your new $" << price << " " << vehicle_color << " Model " << vehicle_model << "!" << endl;
	// ^^^ Displays output message along with price, color, and model
}