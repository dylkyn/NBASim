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
    name = "";
    switch (playerType)
    {
        case 1: //point guard
            block = rand() % 40 + 1;
            rebound = rand() % 80 + 1;
            interiorDefense = rand() % 50 + 1;
            perimeterDefense = rand() % 100 + 50;
            pass = rand() % 100 + 40;
            shoot = rand() % 100 + 20;
            threePointShot = rand() % 100 + 40;
            twoPointShot = rand() % 100 + 40;

            //set name
            int randIndex = rand() % pointGuardRange;
            name = pointGuardNames[randIndex];
            //shorten range
            pointGuardRange--;
            //shift all elements down one from random index
            for(int i = randIndex; i < pointGuardNames.length() - 1; i++)
            {
                pointGuardNames[randIndex] = pointGuardNames[randIndex + 1];
            }
            break;
        case 2: //shooting guard
            block = rand() % 50 + 1;
            rebound = rand() % 80 + 1;
            interiorDefense = rand() % 60 + 1;
            perimeterDefense = rand() % 100 + 40;
            pass = rand() % 100 + 20;
            shoot = rand() % 100 + 40;
            threePointShot = rand() % 100 + 60;
            twoPointShot = rand() % 100 + 50;

            //set name
            int randIndex = rand() % shootingGuardRange;
            name = shootingGuardNames[randIndex];
            //shorten range
            shootingGuardRange--;
            //shift all elements down one from random index
            for(int i = randIndex; i < shootingGuardNames.length() - 1; i++)
            {
                shootingGuardNames[randIndex] = shootingGuardNames[randIndex + 1];
            }
            break;
        case 3: //small forward
            block = rand() % 80 + 20;
            rebound = rand() % 90 + 20;
            interiorDefense = rand() % 90 + 40;
            perimeterDefense = rand() % 80 + 30;
            pass = rand() % 100 + 20;
            shoot = rand() % 100 + 20;
            threePointShot = rand() % 90 + 30;
            twoPointShot = rand() % 100 + 60;
            //set name
            int randIndex = rand() % smallForwardRange;
            name = smallForwardNames[randIndex];
            //shorten range
            smallForwardRange--;
            //shift all elements down one from random index
            for(int i = randIndex; i < smallForwardNames.length() - 1; i++)
            {
                smallForwardNames[randIndex] = smallForwardNames[randIndex + 1];
            }
            break;
        case 4: //power forward
            block = rand() % 90 + 40;
            rebound = rand() % 100 + 50;
            interiorDefense = rand() % 100 + 50;
            perimeterDefense = rand() % 70 + 20;
            pass = rand() % 100 + 20;
            shoot = rand() % 100 + 20;
            threePointShot = rand() % 70 + 10;
            twoPointShot = rand() % 100 + 70;
            //set name
            int randIndex = rand() % powerForwardRange;
            name = powerForwardNames[randIndex];
            //shorten range
            powerForwardRange--;
            //shift all elements down one from random index
            for(int i = randIndex; i < powerForwardNames.length() - 1; i++)
            {
                powerForwardNames[randIndex] = powerForwardNames[randIndex + 1];
            }
            break;
        case 5: //center
            block = rand() % 100 + 60;
            rebound = rand() % 100 + 70;
            interiorDefense = rand() % 100 + 70;
            perimeterDefense = rand() % 50 + 10;
            pass = rand() % 100 + 20;
            shoot = rand() % 100 + 20;
            threePointShot = rand() % 50 + 1;
            twoPointShot = rand() % 100 + 75;
            //set name
            int randIndex = rand() % centerRange;
            name = powerForwardNames[randIndex];
            //shorten range
            centerRange--;
            //shift all elements down one from random index
            for(int i = randIndex; i < powerForwardNames.length() - 1; i++)
            {
                powerForwardNames[randIndex] = powerForwardNames[randIndex + 1];
            }
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
    return numSteals;
}
int Player::getNumBlocks()
{
    return numBlocks;
}
