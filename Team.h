#ifndef NBASIM_TEAM_H
#define NBASIM_TEAM_H
#include "Player.h"
#include <string>
class Team
{
private:
    Player players[5];
    int gameScore;
    string teamName;
public:
    Team(std::string name);
    Player getPlayer();
    int getGameScore();
    void setGameScore(int score);
};
#endif //NBASIM_TEAM_H
