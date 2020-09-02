#include <iostream>
#include <vector>

// Parses through to see if maze is solvable
bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
    bool solvable = false; // Indicates whether a valid solution exists
    bool inside = false;

    maze[sr][sc] = 'C'; // Indicates that algorithm has encountered tile

    if (sr == er && sc == ec)
    {
        return(!solvable); // If we are currently at the end, return true
    }

    // If North unique, attempt to solve
    if (maze[sr - 1][sc] == '.' && pathExists(maze, sr - 1, sc, er, ec))
    {
        inside = true;
        solvable = true;
    }

    // If West unique, attempt to solve
    else if (maze[sr][sc - 1] == '.' && pathExists(maze, sr, sc - 1, er, ec))
    {
        inside = true;
        solvable = true;
    }

    // If East unique, attempt to solve
    else if (maze[sr][sc + 1] == '.' && pathExists(maze, sr, sc + 1, er, ec))
    {
        inside = true;
        solvable = true;
    }

    // If South unique, attempt to solve
    else if (maze[sr + 1][sc] == '.' && pathExists(maze, sr + 1, sc, er, ec))
    {
        inside = true;
        solvable = true;
    }

    return(solvable);
}

/////////////////////////////////////////////
// Remove main routine (before submission)!!
/////////////////////////////////////////////
int main()
{
	std::cout << "It builds!" << std::endl;

    char maze[10][10] = {
                { 'X','X','X','X','X','X','X','X','X','X' },
                { 'X','.','.','.','.','.','.','.','.','X' },
                { 'X','.','.','.','.','.','.','.','.','X' },
                { 'X','.','.','.','X','.','.','.','.','X' },
                { 'X','.','.','.','X','.','.','.','.','X' },
                { 'X','.','.','.','X','.','.','.','.','X' },
                { 'X','.','.','.','X','.','.','.','.','X' },
                { 'X','.','.','.','X','.','.','.','.','X' },
                { 'X','.','.','.','X','.','.','.','.','X' },
                { 'X','X','X','X','X','X','X','X','X','X' }
    };

    if (pathExists(maze, 5, 2, 8, 8))
        std::cout << "Solvable!" << std::endl;
    else
        std::cout << "Out of luck!" << std::endl;
}