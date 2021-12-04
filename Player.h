//
// Created by bella on 12/3/2021.
//

#ifndef NBASIM_PLAYER_H
#define NBASIM_PLAYER_H
class Player
{
private:
    int position; //what type of player? 1-5
    int block;
    int rebound;
    int interiorDefense;
    int perimeterDefense;
    int pass;
    int shoot;
    int threePointShot;
    int twoPointShot;

    //player stats
    int numMissedTwo;
    int numMissedThree;
    int numTwo;
    int numThree;
    int numAssist;
    int numRebounds;
    int numSteals;
    int numBlocks;
public:
    Player(int playerType);
    Player();
    //getters and setters for attributes
    int getPosition();
    int getBlock();
    int getRebound();
    int getInteriorDefense();
    int getPerimeterDefense();
    int getPass();
    int getShoot();
    int getThreePointShot();
    int getTwoPointShot();

    //player totals
    void setNumMissedTwo(int newMissedTwo);
    void setNumMissedThree(int newMissedThree);
    void setNumTwo(int newNumTwo);
    void setNumThree(int newNumThree);
    void setNumAssist(int newNumAssist);
    void setNumRebounds(int newNumRebounds);
    void setNumSteals(int newNumSteals);
    void setNumBlocks(int newNumBlocks);
    int getNumMissedThree();
    int getNumMissedTwo();
    int getNumThree();
    int getNumTwo();
    int getNumAssist();
    int getNumRebounds();
    int getNumSteals();
    int getNumBlocks();
};
#endif //NBASIM_PLAYER_H
