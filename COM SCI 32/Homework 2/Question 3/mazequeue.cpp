#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

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

bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
	bool solvable = false; // Indicates whether a valid solution exists
	std::queue<Coord> pointQueue; // Initialize the coordinate queue
	pointQueue.push(Coord(sr, sc)); // Enqueues starting coordinate onto queue
	pointQueue.push(Coord(sr, sc));
	
	maze[sr][sc] = 'C';

	while (pointQueue.size() != 0)
	{
		Coord curr = pointQueue.front(); // Set current equal to the front coordinate 
		pointQueue.pop(); // Pop the front coordinate off of the queue
		int r = curr.r();
		int c = curr.c();

		// If the current coordinate is the end coordinate, return true
		if (r == er && c == ec)
		{
			solvable = true;
			break;
		}

		if (maze[r + 1][c] == '.') // If S unique, push onto stack and set as encountered
		{
			pointQueue.push(Coord(r + 1, c));
			maze[r + 1][c] = 'C';
		}
		if (maze[r][c - 1] == '.') // If W unique, push onto stack and set as encountered
		{
			pointQueue.push(Coord(r, c - 1));
			maze[r][c - 1] = 'C';
		}
		if (maze[r - 1][c] == '.') // If N unique, push onto stack and set as encountered
		{
			pointQueue.push(Coord(r - 1, c));
			maze[r - 1][c] = 'C';
		}
		if (maze[r][c + 1] == '.') // If E unique, push onto stack and set as encountered
		{
			pointQueue.push(Coord(r, c + 1));
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
	{ 'X','.','X','X','.','.','X','.','.','X' },
	{ 'X','.','.','.','.','.','.','X','.','X' },
	{ 'X','.','X','X','X','.','.','.','X','X' },
	{ 'X','.','X','.','X','.','.','.','.','X' },
	{ 'X','.','.','.','X','.','.','.','.','X' },
	{ 'X','.','.','.','X','.','.','.','.','X' },
	{ 'X','.','.','.','X','.','.','.','.','X' },
	{ 'X','X','X','X','X','X','X','X','X','X' }
	};


	if (pathExists(maze, 8, 2, 8, 8))
	{
		std::cout << "Solvable!" << std::endl;
	}
	else
		std::cout << "Out of luck!" << std::endl;
}