#include "History.h"
#include <iostream>

History::History(int nRows, int nCols)
{
	m_rows = nRows;
    m_cols = nCols;

    // Initializes grid data member
    for (int r = 1; r <= m_rows; r++)
        for (int c = 1; c <= m_cols; c++)
            m_grid[r - 1][c - 1] = 0;
}

bool History::record(int r, int c)
{
    if (r > m_rows || c > m_cols || r <= 0 || c <= 0)
    {
        return(false);
    }
    else
    {
        // If valid, increment grid to indicate a dropped vial
        m_grid[r - 1][c - 1] += 1;
        return(true);
    }
}

void History::display() const
{
    // Implementation borrowed from Arena's display() method
    char displayGrid[MAXROWS][MAXCOLS];
    int r, c;

    clearScreen();
    for (r = 1; r <= m_rows; r++)
    {
        for (c = 1; c <= m_cols; c++)
        {
            int i = m_grid[r - 1][c - 1];

            char gridChar;

            // Matches number of vials dropped to character
            switch (i)
            {
            case 1:
                gridChar = 'A';
                break;
            case 2:
                gridChar = 'B';
                break;
            case 3:
                gridChar = 'C';
                break;
            case 4:
                gridChar = 'D';
                break;
            case 5:
                gridChar = 'E';
                break;
            case 6:
                gridChar = 'F';
                break;
            case 7:
                gridChar = 'G';
                break;
            case 8:
                gridChar = 'H';
                break;
            case 9:
                gridChar = 'I';
                break;
            case 10:
                gridChar = 'J';
                break;
            case 11:
                gridChar = 'K';
                break;
            case 12:
                gridChar = 'L';
                break;
            case 13:
                gridChar = 'M';
                break;
            case 14:
                gridChar = 'N';
                break;
            case 15:
                gridChar = 'O';
                break;
            case 16:
                gridChar = 'P';
                break;
            case 17:
                gridChar = 'Q';
                break;
            case 18:
                gridChar = 'R';
                break;
            case 19:
                gridChar = 'S';
                break;
            case 20:
                gridChar = 'T';
                break;
            case 21:
                gridChar = 'U';
                break;
            case 22:
                gridChar = 'V';
                break;
            case 23:
                gridChar = 'W';
                break;
            case 24:
                gridChar = 'X';
                break;
            case 25:
                gridChar = 'Y';
                break;
            default:
                gridChar = '.';
                break;
            }

            if (i >= 26)
            {
                gridChar = 'Z';
            }

            displayGrid[r - 1][c - 1] = gridChar;
            std::cout << displayGrid[r - 1][c - 1];
        } 
        std::cout << std::endl;
    }
    std::cout << std::endl;
}