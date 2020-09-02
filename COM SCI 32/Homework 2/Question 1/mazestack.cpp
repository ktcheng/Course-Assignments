#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

// Coordinate Class
class Coord
{
public:
	Coord(int rr, int cc) : m_row(rr), m_col(cc) {}
	int r() const { return m_row; }
	int c() const { return m_col; }
private:
	int m_row;
	int m_col;
};

// Parses through to see if maze is solvable
bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
	bool solvable = false; // Indicates whether a valid solution exists

	std::stack<Coord> pointStack; // Initialize the coordinate stack
	pointStack.push(Coord(sr, sc)); // Pushes starting coordinate onto stack
	maze[sr][sc] = 'C'; // Indicates that algorithm has encountered the tile

	// While available coordinates exist, parse through the maze
	while (pointStack.size() != 0)
	{
		Coord curr = pointStack.top(); // Set current coordinate equal to the top coordinate
		pointStack.pop(); // Pop the top coordinate off of the stack
		int r = curr.r();
		int c = curr.c();
		bool inside = false;

		// If the current coordinate is the end coordinate, return true
		if (r == er && c == ec)
		{
			solvable = true;
		}

		if (maze[r + 1][c] == '.') // If S unique, push onto stack and set as encountered
		{
			inside = true;
			pointStack.push(Coord(r + 1, c));
			maze[r + 1][c] = 'C'; 
		}
		if (maze[r][c - 1] == '.') // If W unique, push onto stack and set as encountered
		{
			inside = true;
			pointStack.push(Coord(r, c - 1));
			maze[r][c - 1] = 'C';
		}
		if (maze[r - 1][c] == '.') // If N unique, push onto stack and set as encountered
		{
			inside = true;
			pointStack.push(Coord(r - 1, c));
			maze[r - 1][c] = 'C';
		}
		if (maze[r][c + 1] == '.') // If E unique, push onto stack and set as encountered
		{
			inside = true;
			pointStack.push(Coord(r, c + 1));
			maze[r][c + 1] = 'C';
		}
	}

	return(solvable); 
	
}

int main()
{
	std::cout << "It Builds!" << std::endl;

	char maze[10][10] = {
	{ 'X','X','X','X','X','X','X','X','X','X' },
	{ 'X','.','.','.','.','X','.','.','.','X' },
	{ 'X','.','.','.','.','X','.','.','.','X' },
	{ 'X','.','.','.','.','.','.','.','.','X' },
	{ 'X','.','X','X','X','.','X','X','X','X' },
	{ 'X','.','X','.','.','.','X','.','X' },
	{ 'X','.','.','.','X','.','X','.','.','X' },
	{ 'X','X','X','X','X','.','X','.','X','X' },
	{ 'X','.','.','.','.','.','.','.','.','X' },
	{ 'X','X','X','X','X','X','X','X','X','X' }
	};

	if (pathExists(maze, 5, 2, 3, 2))
		std::cout << "Solvable!" << std::endl;
	else
		std::cout << "Out of luck!" << std::endl;
}