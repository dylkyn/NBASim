#include "Player.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <iostream>

Player::Player(int playerType)
{
	position = playerType;
	srand(time(NULL));
	numTwo = 0;
	numThree = 0;
	numMissedTwo = 0;
	numMissedThree = 0;
	numAssists = 0;
	numRebounds = 0;
	numSteals = 0;
    numBlocks = 0;
	name = "";
    gameNumTwo = 0;
    gameNumThree = 0;
    gameNumMissedTwo = 0;
    gameNumMissedThree = 0;
    gameNumAssists = 0;
    gameNumRebounds = 0;
    gameNumSteals = 0;
    gameNumBlocks = 0;
	int randIndex;
	switch (playerType)
	{
	case 1: //point guard
	{
		block = rand() % 60 + 1;
		rebound = rand() % 80 + 1;
		interiorDefense = rand() % 90 + 1;
		perimeterDefense = rand() % 40 + 60;
		pass = rand() % 60 + 40;
		shoot = rand() % 80 + 20;
		threePointShot = rand() % 80 + 10;
		twoPointShot = rand() % 70 + 10;
  		while (name == "")
		{
            if(pointGuardNames[0] == "")
                break;
			//set name
			randIndex = rand() % pointGuardRange;
			name = pointGuardNames[randIndex];
		}
		//shorten range
		pointGuardRange--;
		//shift all elements down one from random index
		for (int i = 0; i < 31; i++)
		{
			pointGuardNames[i] = pointGuardNames[i + 1];
		}
		pointGuardNames[31] = "";
		break;
	}
	case 2: //shooting guard
	{
		block = rand() % 70 + 1;
		rebound = rand() % 80 + 1;
		interiorDefense = rand() % 100 + 1;
		perimeterDefense = rand() % 60 + 40;
		pass = rand() % 80 + 20;
		shoot = rand() % 60 + 40;
		threePointShot = rand() % 70 + 30;
		twoPointShot = rand() % 80 + 20;
		while (name == "")
		{
            if(shootingGuardNames[0] == "")
                break;
			//set name
			randIndex = rand() % shootingGuardRange;
			name = shootingGuardNames[randIndex];
		}
		//shorten range
		shootingGuardRange--;
		//shift all elements down one from random index
		for (int i = 0; i < 31; i++)
		{
			shootingGuardNames[i] = shootingGuardNames[i + 1];
		}
		shootingGuardNames[31] = "";
		break;
	}
	case 3: //small forward
	{
		block = rand() % 80 + 20;
		rebound = rand() % 80 + 20;
		interiorDefense = rand() % 50 + 50;
		perimeterDefense = rand() % 50 + 40;
		pass = rand() % 80 + 20;
		shoot = rand() % 80 + 20;
		threePointShot = rand() % 70 + 10;
		twoPointShot = rand() % 60 + 40;
		while (name == "")
		{
            if(smallForwardNames[0] == "")
                break;
			//set name
			randIndex = rand() % smallForwardRange;
			name = smallForwardNames[randIndex];
		}
		//shorten range
		smallForwardRange--;
		//shift all elements down one from random index
		for (int i = 0; i < 31; i++)
		{
			smallForwardNames[i] = smallForwardNames[i + 1];
		}
		smallForwardNames[31] = "";
		break;
	}
	case 4: //power forward
	{
		block = rand() % 60 + 40;
		rebound = rand() % 50 + 50;
		interiorDefense = rand() % 40 + 60;
		perimeterDefense = rand() % 60 + 20;
		pass = rand() % 80 + 20;
		shoot = rand() % 80 + 20;
		threePointShot = rand() % 70 + 10;
		twoPointShot = rand() % 50 + 50;
		while (name == "")
		{
            if(powerForwardNames[0] == "")
                break;
			//set name
			randIndex = rand() % powerForwardRange;
			name = powerForwardNames[randIndex];
		}
		//shorten range
		powerForwardRange--;
		//shift all elements down one from random index
		for (int i = 0; i < 31; i++)
		{
			powerForwardNames[i] = powerForwardNames[i + 1];
		}
		powerForwardNames[31] = "";
		break;
	}
	case 5: //center
	{
		block = rand() % 40 + 60;
		rebound = rand() % 30 + 70;
		interiorDefense = rand() % 30 + 70;
		perimeterDefense = rand() % 60 + 10;
		pass = rand() % 80 + 20;
		shoot = rand() % 80 + 20;
		threePointShot = rand() % 50 + 1;
		twoPointShot = rand() % 45 + 55;
		while (name == "")
		{
            if(centerNames[0] == "")
                break;
			//set name
			randIndex = rand() % centerRange;
			name = centerNames[randIndex];
		}
		//shorten range
		centerRange--;
		//shift all elements down one from random index
		for (int i = 0; i < 31; i++)
		{
			centerNames[i] = centerNames[i + 1];
		}
		centerNames[31] = "";
		break;
	}
	}
}

Player::Player()
{
    //do nothing if default
}

//getters and setters for attributes
int Player::getPosition()
{
	return position;
}
int Player::getBlock()
{
	return block;
}
int Player::getRebound()
{
	return rebound;
}
int Player::getInteriorDefense()
{
	return interiorDefense;
}
int Player::getPerimeterDefense()
{
	return perimeterDefense;
}
int Player::getPass()
{
	return pass;
}
int Player::getShoot()
{
	return shoot;
}
int Player::getThreePointShot()
{
	return threePointShot;
}
int Player::getTwoPointShot()
{
	return twoPointShot;
}

//player totals
void Player::setNumMissedTwo(int newMissedTwo)
{
	numMissedTwo = newMissedTwo;
}
void Player::setNumMissedThree(int newMissedThree)
{
	numMissedThree = newMissedThree;
}
void Player::increaseMissedTwo()
{
	numMissedTwo += 1;
}
void Player::increaseMissedThree()
{
	numMissedThree += 1;
}

void Player::setNumTwo(int newNumTwo)
{
	numTwo = newNumTwo;
}
void Player::setNumThree(int newNumThree)
{
	numThree = newNumThree;
}
void Player::setNumAssist(int newNumAssist)
{
	numAssists = newNumAssist;
}
void Player::setNumRebounds(int newNumRebounds)
{
	numRebounds = newNumRebounds;
}
void Player::setNumSteals(int newNumSteals)
{
	numSteals = newNumSteals;
}
void Player::setNumBlocks(int newNumBlocks)
{
	numBlocks = newNumBlocks;
}
void Player::setGameNumTwo(int newNumTwo)
{
    gameNumTwo = newNumTwo;
}
void Player::setGameNumThree(int newNumThree)
{
    gameNumThree = newNumThree;
}
void Player::setGameNumAssist(int newNumAssist)
{
    gameNumAssists = newNumAssist;
}
void Player::setGameNumRebounds(int newNumRebounds)
{
    gameNumRebounds = newNumRebounds;
}
void Player::setGameNumSteals(int newNumSteals)
{
    gameNumSteals = newNumSteals;
}
void Player::setGameNumBlocks(int newNumBlocks)
{
    gameNumBlocks = newNumBlocks;
}
void Player::resetGameStats()
{
    gameNumTwo = 0;
    gameNumThree = 0;
    gameNumMissedTwo = 0;
    gameNumMissedThree = 0;
    gameNumAssists = 0;
    gameNumRebounds = 0;
    gameNumSteals = 0;
    gameNumBlocks = 0;
}
int Player::getNumMissedThree()
{
	return numMissedThree;
}
std::string Player::getName()
{
	return this->name;
}
int Player::getNumMissedTwo()
{
	return numMissedTwo;
}
int Player::getNumTwo()
{
	return numTwo;
}
int Player::getNumThree()
{
	return numThree;
}
int Player::getNumAssist()
{
	return numAssists;
}
int Player::getNumRebounds()
{
	return numRebounds;
}
int Player::getNumSteals()
{
	return numSteals;
}
int Player::getNumBlocks()
{
	return numBlocks;
}
int Player::getGameNumTwo()
{
    return gameNumTwo;
}
int Player::getGameNumThree()
{
    return gameNumThree;
}
int Player::getGameNumAssist()
{
    return gameNumAssists;
}
int Player::getGameNumRebounds()
{
    return gameNumRebounds;
}
int Player::getGameNumSteals()
{
    return gameNumSteals;
}
int Player::getGameNumBlocks()
{
    return gameNumBlocks;
}

