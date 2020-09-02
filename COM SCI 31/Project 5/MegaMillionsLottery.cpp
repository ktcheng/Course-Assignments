#include <random>
#include <utility>
#include <string>
#include "MegaMillionsLottery.h"
#include "RandomNumber.h"

MegaMillionsLottery::MegaMillionsLottery()
{
	RandomNumber rNumber = RandomNumber(1, 75); // Generates range for balls 1-5
	RandomNumber rMega = RandomNumber(1, 25); // Generates range for the MegaBall
	mBall1 = rNumber.random();
	mBall2 = rNumber.random();

	while (true) // Checks that ball 2 and ball 1 are distinct
	{
		// Breaks upon distinct value, otherwise continues generating values
		if (mBall2 != mBall1)
		{
			break;
		}
		mBall2 = rNumber.random();
	}

	mBall3 = rNumber.random();

	while (true) // Checks that ball 3 is distinct
	{
		// Breaks upon distinct value, otherwise continues generating values
		if ((mBall3 != mBall2) && (mBall3 != mBall1))
		{
			break;
		}
		mBall3 = rNumber.random();
	}

	mBall4 = rNumber.random();

	while (true) // Checks that ball 4 is distinct
	{
		// Breaks upon distinct value, otherwise continues generating values
		if ((mBall4 != mBall3) && (mBall4 != mBall2) && (mBall4 != mBall1))
		{
			break;
		}
		mBall4 = rNumber.random();
	}

	mBall5 = rNumber.random();

	while (true) // Checks that ball 5 is distinct
	{
		// Breaks upon distinct value, otherwise continues generating values
		if ((mBall5 != mBall4) && (mBall5 != mBall3) && (mBall5 != mBall2) 
			&& (mBall5 != mBall1))
		{
			break;
		}
		mBall5 = rNumber.random();
	}

	mMegaBall = rMega.random();
}

MegaMillionsLottery::MegaMillionsLottery(int ball1, int ball2, int ball3,
	int ball4, int ball5, int megaball)
{
	mBall1 = ball1;
	mBall2 = ball2;
	mBall3 = ball3; 
	mBall4 = ball4;
	mBall5 = ball5;
	mMegaBall = megaball;
}

MegaMillionsTicket MegaMillionsLottery::quickPick()
{
	RandomNumber rNumber = RandomNumber(1, 75); // Generates range for balls 1-5
	RandomNumber rMega = RandomNumber(1, 25); // Generates range for the MegaBall
	int n1, n2, n3, n4, n5, nMega; // MegaMillionsTicket constructor arguments

	n1 = rNumber.random();
	n2 = rNumber.random();

	while (true) // Checks that ball 2 and ball 1 are distinct
	{
		// Breaks upon distinct value, otherwise continues generating values
		if (n2 != n1)
		{
			break;
		}
		n2 = rNumber.random();
	}

	n3 = rNumber.random();

	while (true) // Checks that ball 3 is distinct
	{
		// Breaks upon distinct value, otherwise continues generating values
		if ((n3 != n2) && (n3 != n1))
		{
			break;
		}
		n3 = rNumber.random();
	}

	n4 = rNumber.random();

	while (true) // Checks that ball 4 is distinct
	{
		// Breaks upon distinct value, otherwise continues generating values
		if ((n4 != n3) && (n4 != n2) && (n4 != n1))
		{
			break;
		}
		n4 = rNumber.random();
	}

	n5 = rNumber.random();

	while (true) // Checks that ball 5 is distinct
	{
		// Breaks upon distinct value, otherwise continues generating values
		if ((n5 != n4) && (n5 != n3) && (n5 != n2) && (n5 != n1))
		{
			break;
		}
		n5 = rNumber.random();
	}

	nMega = rMega.random();

	MegaMillionsTicket generatedTicket = MegaMillionsTicket(n1, n2, n3, n4, n5, nMega);

	return(generatedTicket);
}

MegaMillionsLottery::WinningPossibility MegaMillionsLottery::checkTicket(MegaMillionsTicket ticket)
{
	MegaMillionsLottery::WinningPossibility reward; // Initializes WinningPossibility

	// Ticket/Lottery values in arrays for comparison analysis
	int ticketArray[5] = {ticket.getBall1(), ticket.getBall2(), ticket.getBall3(), 
		ticket.getBall4(), ticket.getBall5()}; 
	int lottoArray[5] = { mBall1, mBall2, mBall3, mBall4, mBall5};
	int matchCounter = 0; // Declared to check for enum WinningPossibility

	// Nested for loops to compare values regardless of ball ordering
	for (int i = 0; i < 5; i++) // Iterates through ticket values barring MegaBall
	{
		for (int j = 0; j < 5; j++) // Iterates through lottery values barring MegaBall
		{
			if (ticketArray[i] == lottoArray[j])
			{
				matchCounter += 1;
			}
		}
	}

	switch (matchCounter) // Uses matchCounter to set the reward
	{
		case 0:
			if (ticket.getMegaBall() == mMegaBall)
			{
				reward = MegaMillionsLottery::MEGABALL;
			}
			else
			{
				reward = MegaMillionsLottery::NOTWINNING;
			}
			break;
		case 1:
			if (ticket.getMegaBall() == mMegaBall)
			{
				reward = MegaMillionsLottery::ONEPLUSMEGABALL;
			}
			else
			{
				reward = MegaMillionsLottery::NOTWINNING;
			}
			break;
		case 2:
			if (ticket.getMegaBall() == mMegaBall)
			{
				reward = MegaMillionsLottery::TWOPLUSMEGABALL;
			}
			else
			{
				reward = MegaMillionsLottery::NOTWINNING;
			}
			break;
		case 3:
			if (ticket.getMegaBall() == mMegaBall)
			{
				reward = MegaMillionsLottery::THREEPLUSMEGABALL;
			}
			else
			{
				reward = MegaMillionsLottery::THREE;
			}
			break;
		case 4:
			if (ticket.getMegaBall() == mMegaBall)
			{
				reward = MegaMillionsLottery::FOURPLUSMEGABALL;
			}
			else
			{
				reward = MegaMillionsLottery::FOUR;
			}
			break;
		case 5:
			if (ticket.getMegaBall() == mMegaBall)
			{
				reward = MegaMillionsLottery::FIVEPLUSMEGABALL;
			}
			else
			{
				reward = MegaMillionsLottery::FIVE;
			}
			break;
	}
	return(reward);
}

string MegaMillionsLottery::whatHappened(MegaMillionsTicket ticket)
{
	string msg = ""; // Initializes output message

	// Recalls the WinningPossibility by calling MegaMillionsLottery::checkTicket method
	MegaMillionsLottery::WinningPossibility reward = MegaMillionsLottery::checkTicket(ticket);

	if (reward == MegaMillionsLottery::MEGABALL)
	{
		msg = "You matched the megaball!";
	}
	else if (reward == MegaMillionsLottery::ONEPLUSMEGABALL)
	{
		msg = "You matched 1 ball plus the megaball!";
	}
	else if (reward == MegaMillionsLottery::TWOPLUSMEGABALL)
	{
		msg = "You matched 2 balls plus the megaball!";
	}
	else if (reward == MegaMillionsLottery::THREE)
	{
		msg = "You matched 3 balls!";
	}
	else if (reward == MegaMillionsLottery::THREEPLUSMEGABALL)
	{
		msg = "You matched 3 balls plus the megaball!";
	}
	else if (reward == MegaMillionsLottery::FOUR)
	{
		msg = "You matched 4 balls!";
	}
	else if (reward == MegaMillionsLottery::FOURPLUSMEGABALL)
	{
		msg = "You matched 4 balls plus the megaball!";
	}
	else if (reward == MegaMillionsLottery::FIVE)
	{
		msg = "You matched 5 balls!";
	}
	else if (reward == MegaMillionsLottery::FIVEPLUSMEGABALL)
	{
		msg = "You matched 5 balls plus the megaball!";
	}
	else
	{
		msg = "You didn't win anything at all!";
	}

	return (msg);
}

int MegaMillionsLottery::getBall1()
{
	return(mBall1); // Returns value 1
}

int MegaMillionsLottery::getBall2()
{
	return(mBall2); // Returns value 2
}

int MegaMillionsLottery::getBall3()
{
	return(mBall3); // Returns value 3
}

int MegaMillionsLottery::getBall4()
{
	return(mBall4); // Returns value 4
}

int MegaMillionsLottery::getBall5()
{
	return(mBall5); // Returns value 5
}

int MegaMillionsLottery::getMegaBall()
{
	return(mMegaBall); // Returns MegaBall value
}