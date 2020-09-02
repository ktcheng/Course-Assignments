//
//  Player.cpp
//  Centennial
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//
#include "Player.h"
#include <iostream>

namespace cs31
{
    // set up three six sided dies
    // indicate that none of the spots 1-12 have yet been tossed
    Player::Player() : mDie1(6), mDie2(6), mDie3(6), hasRolled1(false), hasRolled2(false), hasRolled3(false), hasRolled4(false), hasRolled5(false), hasRolled6(false), hasRolled7(false), hasRolled8(false), hasRolled9(false), hasRolled10(false), hasRolled11(false), hasRolled12(false)
    {

    }

    // CS 31 TODO: FIXED
    void Player::roll(Die d1, Die d2, Die d3)
    {
        mDie1 = d1;
        mDie2 = d2;
        mDie3 = d3;
    }

    // CS 31 TODO: FIXED
    void Player::roll()
    {
        mDie1.roll();
        mDie2.roll();
        mDie3.roll();
    }

    // CS 31 TODO: FIXED
    int  Player::whatSpotIsNeededNext()
    {
        int result = 0;

        if (hasRolled12)
        {
            result = 0;
        }
        else if (hasRolled11)
        {
            result = 12;
        }
        else if (hasRolled10)
        {
            result = 11;
        }
        else if (hasRolled9)
        {
            result = 10;
        }
        else if (hasRolled8)
        {
            result = 9;
        }
        else if (hasRolled7)
        {
            result = 8;
        }
        else if (hasRolled6)
        {
            result = 7;
        }
        else if (hasRolled5)
        {
            result = 6;
        }
        else if (hasRolled4)
        {
            result = 5;
        }
        else if (hasRolled3)
        {
            result = 4;
        }
        else if (hasRolled2)
        {
            result = 3;
        }
        else if (hasRolled1)
        {
            result = 2;
        }
        else
        {
            result = 1;
        }

        return(result);
    }

    // CS 31 TODO: FIXED
    void Player::rolled(int spot)
    {
        switch (spot)
        {
            case 1:
                if (!hasRolled2)
                {
                    hasRolled1 = true;
                }
                break;
            case 2:
                if (hasRolled1 && !hasRolled3)
                {
                    hasRolled2 = true;
                }
                break;
            case 3:
                if (hasRolled2 && !hasRolled4)
                {
                    hasRolled3 = true;
                }
                break;
            case 4:
                if (hasRolled3 && !hasRolled5)
                {
                    hasRolled4 = true;
                }
                break;
            case 5:
                if (hasRolled4 && !hasRolled6)
                {
                    hasRolled5 = true;
                }
                break;
            case 6:
                if (hasRolled5 && !hasRolled7)
                {
                    hasRolled6 = true;
                }
                break;
            case 7:
                if (hasRolled6 && !hasRolled8)
                {
                    hasRolled7 = true;
                }
                break;
            case 8:
                if (hasRolled7 && !hasRolled9)
                {
                    hasRolled8 = true;
                }
                break;
            case 9:
                if (hasRolled8 && !hasRolled10)
                {
                    hasRolled9 = true;
                }
                break;
            case 10:
                if (hasRolled9 && !hasRolled11)
                {
                    hasRolled10 = true;
                }
                break;
            case 11:
                if (hasRolled10 && !hasRolled12)
                {
                    hasRolled11 = true;
                }
                break;
            case 12:
                if (hasRolled11)
                {
                    hasRolled12 = true;
                }
            default:
                break;
        }
    }

    // trivial getter operation
    Die Player::getDie1() const
    {
        return(mDie1);
    }

    // trivial getter operation
    Die Player::getDie2() const
    {
        return(mDie2);
    }

    // trivial getter operation
    Die Player::getDie3() const
    {
        return(mDie3);
    }

    // trivial getter operation
    bool Player::hasRolledOne() const
    {
        return(hasRolled1);
    }

    // trivial getter operation
    bool Player::hasRolledTwo() const
    {
        return(hasRolled2);
    }

    // trivial getter operation
    bool Player::hasRolledThree() const
    {
        return(hasRolled3);
    }

    // trivial getter operation
    bool Player::hasRolledFour() const
    {
        return(hasRolled4);
    }

    // trivial getter operation
    bool Player::hasRolledFive() const
    {
        return(hasRolled5);
    }

    // trivial getter operation
    bool Player::hasRolledSix() const
    {
        return(hasRolled6);
    }

    // trivial getter operation
    bool Player::hasRolledSeven() const
    {
        return(hasRolled7);
    }

    // trivial getter operation
    bool Player::hasRolledEight() const
    {
        return(hasRolled8);
    }

    // trivial getter operation
    bool Player::hasRolledNine() const
    {
        return(hasRolled9);
    }

    // trivial getter operation
    bool Player::hasRolledTen() const
    {
        return(hasRolled10);
    }

    // trivial getter operation
    bool Player::hasRolledEleven() const
    {
        return(hasRolled11);
    }

    // trivial getter operation
    bool Player::hasRolledTwelve() const
    {
        return(hasRolled12);
    }

    // used solely for testing purposes to see the value of each die
    // if we are using random rolls, we won't know what was tossed
    //         unless we use this operation
    std::string Player::whatWasRolled()
    {
        using namespace std;
        std::string s = "";
        s += "Die1: ";
        s += std::to_string(mDie1.getValue());
        s += " Die2: ";
        s += std::to_string(mDie2.getValue());
        s += " Die3: ";
        s += std::to_string(mDie3.getValue());
        s += "\n";
        return(s);
    }
}