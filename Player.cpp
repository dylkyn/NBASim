#include "Player.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>

Player::Player(int playerType)
{
    this->type = playerType;
    srand(time(NULL));
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

//getters and setters for attributes
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

void Player::setBlock(int newBlock)
{
    block = newBlock;
}
void Player::setRebound(int newRebound)
{
    rebound = newRebound;
}
void Player::setInteriorDefense(int newInterior)
{
    interiorDefense = newInterior;
}
void Player::setPerimeterDefense(int newPerimeter)
{
    perimeterDefense = newPerimeter;
}
void Player::setPass(int newPass)
{
    pass = newPass;
}
void Player::setShoot(int newShoot)
{
    shoot = newShoot;
}
void Player::setThreePointShot(int newThree)
{
    threePointShot = newThree;
}
void Player::setTwoPointShot(int newTwo)
{
    twoPointShot = newTwo;
}