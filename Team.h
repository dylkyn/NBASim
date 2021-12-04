#ifndef NBASIM_TEAM_H
#define NBASIM_TEAM_H
#include "Player.h"
#include <string>
class Team
{
private:
    Player players[5];
    int gameScore;
    std::string teamName;
public:
    Team();
    Team(std::string name);
    Player getPlayer();
    int getGameScore();
    void setGameScore(int score);
    std::string getName();
};
#endif //NBASIM_TEAM_H
