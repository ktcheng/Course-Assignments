#include "MegaMillionsTicket.h"
using namespace std;

MegaMillionsTicket::MegaMillionsTicket(int ball1, int ball2, int ball3, int ball4, int ball5,
	int megaball)
{
	mBall1 = ball1;
	mBall2 = ball2;
	mBall3 = ball3;
	mBall4 = ball4;
	mBall5 = ball5;
	mMegaBall = megaball;
}

int MegaMillionsTicket::getBall1()
{
	return(mBall1); // Returns value 1
}

int MegaMillionsTicket::getBall2()
{
	return(mBall2); // Returns value 2
}

int MegaMillionsTicket::getBall3()
{
	return(mBall3); // Returns value 3
}

int MegaMillionsTicket::getBall4()
{
	return(mBall4); // Returns value 4
}

int MegaMillionsTicket::getBall5()
{
	return(mBall5); // Returns value 5
}

int MegaMillionsTicket::getMegaBall()
{
	return(mMegaBall); // Returns MegaBall value
}