//
//  Centennial.cpp
//  Centennial
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//
#include "Centennial.h"
#include <iostream>
#include <string>
using namespace std;

namespace cs31
{
    // human goes first
    Centennial::Centennial() : isHumanTurn(true)
    {

    }

    // prints the state of the game play with each round of play
    std::string Centennial::display(std::string msg)
    {
        using namespace std;
        std::string s("");
        if (isHumanTurn)
        {
            s += "Human-";
            s += mHuman.whatWasRolled();
        }
        else
        {
            s += "Computer-";
            s += mComputer.whatWasRolled();
        }
        s += mBoard.display();

        if (isGameOver())
        {
            if (determineGameOutcome() == HUMANWONGAME)
            {
                s = s + "\n\t\tyou won Centennial!\n";
            }
            else
            {
                s = s + "\n\t\tyou lost Centennial!\n";
            }
        }
        else
        {
            s = s + msg;
        }
        return(s);
    }

    // CS 31 TODO: FIXED
    void Centennial::humanPlay()
    {
        isHumanTurn = true;

        mHuman.roll();

        Die nDie1 = mHuman.getDie1();
        Die nDie2 = mHuman.getDie2();
        Die nDie3 = mHuman.getDie3();

        int iDie1 = nDie1.getValue();
        int iDie2 = nDie2.getValue();
        int iDie3 = nDie3.getValue();

        int spot = mBoard.getHumanSpot();
        int counter = spot + 1;

        while (true)
        {
            if ((iDie1 == counter) || (iDie2 == counter) || (iDie3 == counter))
            {
                counter++;
            }
            else if ((iDie1 + iDie2 == counter) || (iDie2 + iDie3 == counter) || (iDie1 + iDie3 == counter))
            {
                counter++;
            }
            else if (iDie1 + iDie2 + iDie3 == counter)
            {
                counter++;
            }
            else
            {
                break;
            }
        }
        counter -= 1;

        for (int i = spot; i <= counter; i++) // use i = 1 instead of current spot
        {
            mHuman.rolled(i);
        }
        
        mBoard.setHumanSpot(counter);
    }

    // CS 31 TODO: FIXED
    void Centennial::humanPlay(Die d1, Die d2, Die d3)
    {
        isHumanTurn = true;

        mHuman.roll(d1, d2, d3);

        Die nDie1 = d1;
        Die nDie2 = d2;
        Die nDie3 = d3;

        int iDie1 = nDie1.getValue();
        int iDie2 = nDie2.getValue();
        int iDie3 = nDie3.getValue();

        int spot = mBoard.getHumanSpot();
        int counter = spot + 1;

        while (true)
        {
            if ((iDie1 == counter) || (iDie2 == counter) || (iDie3 == counter))
            {
                counter++;
            }
            else if ((iDie1 + iDie2 == counter) || (iDie2 + iDie3 == counter) || (iDie1 + iDie3 == counter))
            {
                counter++;
            }
            else if (iDie1 + iDie2 + iDie3 == counter)
            {
                counter++;
            }
            else
            {
                break;
            }
        }
        counter -= 1;

        for (int i = spot; i <= counter; i++)
        {
            mHuman.rolled(i);
        }

        mBoard.setHumanSpot(counter);
    }

    // CS 31 TODO: FIXED
    void Centennial::computerPlay()
    {
        isHumanTurn = false;

        mComputer.roll();

        Die nDie1 = mComputer.getDie1();
        Die nDie2 = mComputer.getDie2();
        Die nDie3 = mComputer.getDie3();

        int iDie1 = nDie1.getValue();
        int iDie2 = nDie2.getValue();
        int iDie3 = nDie3.getValue();

        int spot = mBoard.getComputerSpot();
        int counter = spot + 1;

        while (true)
        {
            if ((iDie1 == counter) || (iDie2 == counter) || (iDie3 == counter))
            {
                counter++;
            }
            else if ((iDie1 + iDie2 == counter) || (iDie2 + iDie3 == counter) || (iDie1 + iDie3 == counter))
            {
                counter++;
            }
            else if (iDie1 + iDie2 + iDie3 == counter)
            {
                counter++;
            }
            else
            {
                break;
            }
        }
        counter -= 1;

        for (int i = spot; i <= counter; i++)
        {
            mComputer.rolled(i);
        }

        mBoard.setComputerSpot(counter);
    }

    // CS 31 TODO: FIXED
    void Centennial::computerPlay(Die d1, Die d2, Die d3)
    {
        isHumanTurn = false;

        mComputer.roll(d1, d2, d3);

        Die nDie1 = d1;
        Die nDie2 = d2;
        Die nDie3 = d3;

        int iDie1 = nDie1.getValue();
        int iDie2 = nDie2.getValue();
        int iDie3 = nDie3.getValue();

        int spot = mBoard.getComputerSpot();
        int counter = spot + 1;

        while (true)
        {
            if ((iDie1 == counter) || (iDie2 == counter) || (iDie3 == counter))
            {
                counter++;
            }
            else if ((iDie1 + iDie2 == counter) || (iDie2 + iDie3 == counter) || (iDie1 + iDie3 == counter))
            {
                counter++;
            }
            else if (iDie1 + iDie2 + iDie3 == counter)
            {
                counter++;
            }
            else
            {
                break;
            }
        }
        counter -= 1;

        for (int i = spot; i <= counter; i++)
        {
            mComputer.rolled(i);
        }

        mBoard.setComputerSpot(counter);
    }

    // CS 31 TODO: FIXED
    Centennial::GAMEOUTCOME  Centennial::determineGameOutcome() const
    {
        GAMEOUTCOME result;

        if ((mHuman.hasRolledTwelve() != true) && (mComputer.hasRolledTwelve() != true))
        {
            result = GAMEOUTCOME::GAMENOTOVER;
        }
        else
        {
            if (mHuman.hasRolledTwelve() == true)
            {
                result = GAMEOUTCOME::HUMANWONGAME;
            }
            else
            {
                result = GAMEOUTCOME::COMPUTERWONGAME;
            }
        }

        return(result);
    }

    // CS 31 TODO: FIXED
    bool Centennial::isGameOver()
    {
        Centennial::GAMEOUTCOME indicator = determineGameOutcome();

        if (indicator == Centennial::GAMENOTOVER)
        {
            return (false);
        }
        else
        {
            return (true);
        }
    }

    // trivial getter operation
    Player Centennial::getHuman() const
    {
        return(mHuman);
    }

    // trivial getter operation
    Player Centennial::getComputer() const
    {
        return(mComputer);
    }

    // trivial getter operation
    Board  Centennial::getBoard() const
    {
        return(mBoard);
    }
}