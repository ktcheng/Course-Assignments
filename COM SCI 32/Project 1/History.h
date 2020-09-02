#include "globals.h"

#ifndef HISTORY_H
#define HISTORY_H

class History
{
public:
	// Constructor
	History(int nRows, int nCols);

	// Accessor
	void display() const;

	// Mutator
	bool record(int r, int c);
private:
	int m_rows, m_cols;
	int m_grid[MAXROWS][MAXCOLS];
};

#endif