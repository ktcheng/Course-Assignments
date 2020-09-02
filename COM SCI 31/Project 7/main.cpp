#include <iostream>
#include <string>
#include <cassert>
#include "Centennial.h"
using namespace std;
using namespace cs31;

void clearScreen();

int main()
{
    cout.setf(ios::boolalpha);
    Board b;
    Centennial game;
    Die d1, d2, d3, d4, d5, d6;
    d1.setValue(1);
    d2.setValue(2);
    d3.setValue(3);
    d4.setValue(4);
    d5.setValue(5);
    d6.setValue(6);
    Player p1, p2, p3;

    // Centennial Asserts
    //p2 = game.getHuman();
    //p3 = game.getComputer();
    //assert(game.isGameOver() == false);
    //assert(game.determineGameOutcome() == Centennial::GAMENOTOVER);
    //game.humanPlay(d1, d2, d3);
    //game.computerPlay(d1, d2, d3);
    //assert(p2.whatSpotIsNeededNext() == 1);
    //assert(p3.whatSpotIsNeededNext() == 1);
    //p2 = game.getHuman();
    //assert(p2.whatSpotIsNeededNext() == 7);
    //assert(p3.whatSpotIsNeededNext() == 1);
    //assert(game.determineGameOutcome() == Centennial::GAMENOTOVER);
    //game.humanPlay(d3, d4, d5); // Next spot: 10; Current spot: 9
    //game.computerPlay(d2, d3, d4); // Next spot: 8; Current spot: 7
    //assert(p2.whatSpotIsNeededNext() == 7);
    //assert(p3.whatSpotIsNeededNext() == 1);
    //p2 = game.getHuman();
    //p3 = game.getComputer();
    //assert(p2.whatSpotIsNeededNext() == 10);
    //assert(p3.whatSpotIsNeededNext() == 8);
    //game.humanPlay(d5, d5, d1); // Next spot: 12; Current spot: 11
    //game.computerPlay(d4, d4, d1); // Next spot: 10; Current spot: 9
    //assert(game.determineGameOutcome() == Centennial::GAMENOTOVER);
    //game.humanPlay(d6, d6, d1);
    //p2 = game.getHuman();
    //p3 = game.getComputer();
    //assert(p2.whatSpotIsNeededNext() == 0);
    //assert(p3.whatSpotIsNeededNext() == 10);
    //assert(game.determineGameOutcome() == Centennial::HUMANWONGAME);
    //assert(game.isGameOver() == true);

    // Board Asserts
    //b.markComputerAsWinner();
    //assert(b.isHumanWinner() == false);
    //b.markHumanAsWinner();
    //assert(b.isHumanWinner() == true);
    //assert(b.getComputerSpot() == 0);
    //assert(b.getHumanSpot() == 0);
    //assert(b.isGameOver() == false);
    //b.setComputerSpot(9);
    //b.setHumanSpot(1);
    //assert(b.getComputerSpot() == 9);
    //assert(b.getHumanSpot() == 1);
    //b.setComputerSpot(2);
    //b.setHumanSpot(11);
    //assert(b.getComputerSpot() == 2);
    //assert(b.getHumanSpot() == 11);
    //b.setComputerSpot(1);
    //b.setHumanSpot(12);
    //assert(b.getComputerSpot() == 1);
    //assert(b.getHumanSpot() == 12);
    //assert(b.isGameOver() == false);
    //b.markComputerAsWinner(); // marked human as winner in an earlier assert
    //assert(b.isHumanWinner() == false);
    //b.markHumanAsWinner();
    //assert(b.isHumanWinner() == true);
    //assert(b.isGameOver() == false);
    //b.setGameOver(true);
    //assert(b.isGameOver() == true);

    // Player Asserts
    //assert(p1.whatSpotIsNeededNext() == 1);
    //assert(!p1.hasRolledOne());
    //assert(!p1.hasRolledTwelve());
    //p1.rolled(11);
    //assert(p1.whatSpotIsNeededNext() == 1);
    //p1.rolled(-1);
    //assert(p1.whatSpotIsNeededNext() == 1);
    //p1.rolled(1);
    //assert(p1.whatSpotIsNeededNext() == 2);
    //p1.rolled(2);
    //p1.rolled(3);
    //p1.rolled(5);
    //assert(p1.whatSpotIsNeededNext() == 4);
    //p1.rolled(4);
    //assert(p1.whatSpotIsNeededNext() == 5);
    //p1.rolled(5);
    //p1.rolled(6);
    //p1.rolled(7);
    //assert(p1.whatSpotIsNeededNext() == 8);
    //p1.rolled(8);
    //p1.rolled(9);
    //p1.rolled(10);
    //p1.rolled(11);
    //assert(p1.whatSpotIsNeededNext() == 12);
    //p1.rolled(12);
    //assert(p1.whatSpotIsNeededNext() == 0);

    //clearScreen();

    //Centennial game;
    //std::string action, message = "(r)oll (q)uit: ";
    //std::cout << message;

    //// for now...
    //Die d1;
    //Die d2;
    //Die d3;

    //do
    //{
    //    getline(cin, action);
    //    while (action.size() == 0)
    //    {
    //        getline(cin, action);  // no blank entries allowed....
    //    }
    //    switch (action[0])
    //    {
    //    default:   // if bad move, nobody moves
    //        cout << '\a' << endl;  // beep
    //        continue;
    //    case 'Q':
    //    case 'q':
    //        return 0;
    //    case 'r':
    //    case 'R':
    //        game.humanPlay();
    //        cout << game.display("") << endl;
    //        if (!game.isGameOver())
    //        {
    //            game.computerPlay();
    //            cout << game.display(message) << endl;
    //        }
    //        break;
    //    }

    //} while (!game.isGameOver());

    return(0);
}


///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
        &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr || strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif