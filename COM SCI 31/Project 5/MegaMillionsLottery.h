#pragma once
#include <string>
#include "MegaMillionsTicket.h"
#ifndef MEGAMILLIONSLOTTERY_H
#define MEGAMILLIONSLOTTERY_H
using namespace std;

class MegaMillionsLottery
{
public:
	// Enum of potential rewards
	enum WinningPossibility {MEGABALL, ONEPLUSMEGABALL, TWOPLUSMEGABALL, THREE, THREEPLUSMEGABALL,
	FOUR, FOURPLUSMEGABALL, FIVE, FIVEPLUSMEGABALL, NOTWINNING};
	
	MegaMillionsLottery(); // Empty lottery constructor

	// Lottery constructor with arguments
	MegaMillionsLottery(int ball1, int ball2, int ball3, int ball4, int ball5, int megaball);

	int getBall1(); 
	int getBall2();
	int getBall3();
	int getBall4();
	int getBall5();
	int getMegaBall();

	MegaMillionsTicket quickPick(); // Picks random lottery ticket

	// Checks ticket against lottery for potential rewards
	WinningPossibility checkTicket(MegaMillionsTicket ticket);
	string whatHappened(MegaMillionsTicket ticket);
private:
	int mBall1, mBall2, mBall3, mBall4, mBall5, mMegaBall;
};
#endif