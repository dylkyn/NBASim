#ifndef NBASIM_GAME_H
#define NBASIM_GAME_H
#include "Team.h"
class Game
{
private:
    Team team1;
    Team team2;
    Team winner;
public:
    Team getWinner();
    //chris method names
};
#endif //NBASIM_GAME_H
