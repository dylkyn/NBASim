#ifndef NBASIM_TEAM_H
#define NBASIM_TEAM_H
#include "Player.h"
#include <string>
class Team
{
private:
    Player players[5];
public:
    Team(std::string name);
    Player getPlayer();
};
#endif //NBASIM_TEAM_H
