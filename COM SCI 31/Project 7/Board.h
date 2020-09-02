//
//  Board.h
//  Centennial
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright � 2017 Howard Stahl. All rights reserved.
//
#ifndef Board_h
#define Board_h
#include <string>

namespace cs31
{
    class Board
    {
    public:
        Board();

        // a spot on the board is a value between 0-12
        // spot 0 is the opening position, before any rolls of 1-12 have taken place
        // once a player has rolled desired value, adjust the spot accordingly
        void setHumanSpot(int spot);
        void setComputerSpot(int spot);
        int  getHumanSpot();
        int  getComputerSpot();

        // CS 31 TODO: FIXED
        void markComputerAsWinner();

        // CS 31 TODO: FIXED
        void markHumanAsWinner();

        // CS 31 TODO: FIXED
        bool isHumanWinner() const;
        
        // CS 31 TODO: FIXED
        void setGameOver(bool value);

        // CS 31 TODO: FIXED
        bool isGameOver() const;

        // the major operation of board
        // prints the state of the game play with each round of play
        std::string display() const;
    private:
        int  mHumanSpot, mComputerSpot; // how far along are the two players?
        bool mGameOver;  // is the game over?
        bool mHumanWon;  // has the human won?
    };
}
#endif