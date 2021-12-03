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
    Player(int type);
};
#endif //NBASIM_PLAYER_H
