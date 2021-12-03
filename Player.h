//
// Created by bella on 12/3/2021.
//

#ifndef NBASIM_PLAYER_H
#define NBASIM_PLAYER_H
class Player
{
private:
    int type; //what type of player? 1-5
    int block;
    int rebound;
    int interiorDefense;
    int perimeterDefense;
    int pass;
    int shoot;
    int threePointShot;
    int twoPointShot;
public:
    Player(int playerType);
    //getters and setters for attributes
    int getBlock();
    int getRebound();
    int getInteriorDefense();
    int getPerimeterDefense();
    int getPass();
    int getShoot();
    int getThreePointShot();
    int getTwoPointShot();

    void setBlock(int newBlock);
    void setRebound(int newRebound);
    void setInteriorDefense(int newInterior);
    void setPerimeterDefense(int newPerimeter);
    void setPass(int newPass);
    void setShoot(int newShoot);
    void setThreePointShot(int newThree);
    void setTwoPointShot(int newTwo);
};
#endif //NBASIM_PLAYER_H
