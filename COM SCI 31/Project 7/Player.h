//
//  Player.h
//  Centennial
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright � 2017 Howard Stahl. All rights reserved.
//
#ifndef Player_h
#define Player_h
#include "Die.h"
#include <string>

namespace cs31
{
    class Player
    {
    public:
        Player();

        // CS 31 TODO: FIXED
        void roll();
        // CS 31 TODO: FIXED
        void roll(Die d1, Die d2, Die d3);

        // trivial getter operations for each of this player's dice
        Die  getDie1() const;
        Die  getDie2() const;
        Die  getDie3() const;

        // primarily for testing purposes, show textually what was just rolled
        std::string whatWasRolled();

        // CS 31 TODO: FIXED
        void rolled(int spot);
        // CS 31 TODO: FIXED
        int  whatSpotIsNeededNext();

        // trivial getter operations for each spot 1-12
        bool hasRolledOne() const;
        bool hasRolledTwo() const;
        bool hasRolledThree() const;
        bool hasRolledFour() const;
        bool hasRolledFive() const;
        bool hasRolledSix() const;
        bool hasRolledSeven() const;
        bool hasRolledEight() const;
        bool hasRolledNine() const;
        bool hasRolledTen() const;
        bool hasRolledEleven() const;
        bool hasRolledTwelve() const;

    private:
        Die  mDie1, mDie2, mDie3;  // this player's three dice
        bool hasRolled1;   // has the player tossed 1 yet?
        bool hasRolled2;   // has the player tossed 2 yet?
        bool hasRolled3;   // has the player tossed 3 yet?
        bool hasRolled4;   // has the player tossed 4 yet?
        bool hasRolled5;   // has the player tossed 5 yet?
        bool hasRolled6;   // has the player tossed 6 yet?
        bool hasRolled7;   // has the player tossed 7 yet?
        bool hasRolled8;   // has the player tossed 8 yet?
        bool hasRolled9;   // has the player tossed 9 yet?
        bool hasRolled10;  // has the player tossed 10 yet?
        bool hasRolled11;  // has the player tossed 11 yet?
        bool hasRolled12;  // has the player tossed 12 yet?
    };
}
#endif