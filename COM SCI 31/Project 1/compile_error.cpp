// Code for Project 1

// Generations
#include <iostream>
using namespace std;   // pp. 37-38 in Savitch book explain this line

int main()
{

    int genX;
    int genY;
    int genZ;

    cout << "How many of you were born between 1965 and 1980? ";
    cin >> genX;
    cout << "How many of you were born between 1981 and 1996? ";
    cin >> genY;
    cout << "How many of you were born between 1997 and 2010? ";
    cin >> genZ;

    double pctGenK = 100.0 * genX / (genX + genY + genZ); // Compile Error 1: Named pctGenX as pctGenK (results in undeclared identifiers)
    double pctGenY = 100.0 * genY / (genX + genY + genZ);
    double pctGenZ = 100.0 * genZ / (genX + genY + genZ);

    cout.setf(ios::fixed);  // see pp. 30-31 in Savitch book
    cout.precision(1);
    cout << endl;

    cout << pctGenX << "% GenX" << endl;
    cout << pctGenY << "% GenY" << endl;
    cout << pctGenZ << "% GenZ" << endl // Compile Error 2: No Semicolon (this is a syntax error)
    cout << endl;

    if (pctGenX > pctGenY && pctGenX > pctGenZ)
    {
        cout << "Looks like most of you are GenX." << endl;
    }
    else if (pctGenY > pctGenX&& pctGenY > pctGenZ)
    {
        cout << "Looks like most of you are GenY." << endl;
    }
    else
    {
        cout << "Looks like most of you are GenZ." << endl;
    }
    return(0);


}