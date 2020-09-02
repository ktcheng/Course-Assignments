#include <iostream>

#ifndef GAME_H
#define GAME_H

class Arena; // Indicates to compiler that Arena is a class

class Game
{
public:
    // Constructor/destructor
    Game(int rows, int cols, int nVampires);
    ~Game();

    // Mutators
    void play();

private:
    Arena* m_arena;

    // Helper functions
    std::string takePlayerTurn();
};

bool decodeDirection(char ch, int& dir);
bool recommendMove(const Arena& a, int r, int c, int& bestDir);
int computeDanger(const Arena& a, int r, int c);

#endif