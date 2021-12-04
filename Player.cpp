#include "Player.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>

Player::Player(int playerType)
{
    position = playerType;
    srand(time(NULL));
    numTwo = 0;
    numThree = 0;
    numAssist = 0;
    numRebounds = 0;
    numSteals = 0;
    switch (playerType)
    {
        case 1: //point guard
            block = rand() % 100 + 1;
            rebound = rand() % 100 + 1;
            interiorDefense = rand() % 100 + 1;
            perimeterDefense = rand() % 100 + 1;
            pass = rand() % 100 + 1;
            shoot = rand() % 100 + 1;
            threePointShot = rand() % 100 + 1;
            twoPointShot = rand() % 100 + 1;
            break;
        case 2: //shooting guard
            block = rand() % 100 + 1;
            rebound = rand() % 100 + 1;
            interiorDefense = rand() % 100 + 1;
            perimeterDefense = rand() % 100 + 1;
            pass = rand() % 100 + 1;
            shoot = rand() % 100 + 1;
            threePointShot = rand() % 100 + 1;
            twoPointShot = rand() % 100 + 1;
            break;
        case 3: //center
            block = rand() % 100 + 1;
            rebound = rand() % 100 + 1;
            interiorDefense = rand() % 100 + 1;
            perimeterDefense = rand() % 100 + 1;
            pass = rand() % 100 + 1;
            shoot = rand() % 100 + 1;
            threePointShot = rand() % 100 + 1;
            twoPointShot = rand() % 100 + 1;
            break;
        case 4: //power forward
            block = rand() % 100 + 1;
            rebound = rand() % 100 + 1;
            interiorDefense = rand() % 100 + 1;
            perimeterDefense = rand() % 100 + 1;
            pass = rand() % 100 + 1;
            shoot = rand() % 100 + 1;
            threePointShot = rand() % 100 + 1;
            twoPointShot = rand() % 100 + 1;
            break;
        case 5: //small forward
            block = rand() % 100 + 1;
            rebound = rand() % 100 + 1;
            interiorDefense = rand() % 100 + 1;
            perimeterDefense = rand() % 100 + 1;
            pass = rand() % 100 + 1;
            shoot = rand() % 100 + 1;
            threePointShot = rand() % 100 + 1;
            twoPointShot = rand() % 100 + 1;
            break;
    }
}

Player::Player()
{
    Player(1);
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
    numAssist = newNumAssist;
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
int Player::getNumMissedThree()
{
    return numMissedThree;
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
    return numAssist;
}
int Player::getNumRebounds()
{
    return numRebounds;
}
int Player::getNumSteals()
{
    reutn numSteals;
}
int Player::getNumBlocks()
{
    return numBlocks;
}