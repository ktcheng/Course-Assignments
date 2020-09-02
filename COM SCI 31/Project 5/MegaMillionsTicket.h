#pragma once
#ifndef MEGAMILLIONSTICKET_H
#define MEGAMILLIONSTICKET_H

class MegaMillionsTicket
{
public:
	// Ticket constructor with argument
	MegaMillionsTicket(int ball1, int ball2, int ball3, int ball4, int ball5, int megaball);

	int getBall1();
	int getBall2();
	int getBall3();
	int getBall4();
	int getBall5();
	int getMegaBall();
private:
	int mBall1, mBall2, mBall3, mBall4, mBall5, mMegaBall;
};
#endif