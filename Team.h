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
    std::string teamLogo;
public:
    Team();
    Team(std::string name, std::string logo);
    Player getPlayer();
    int getGameScore();
    void resetTeamScore();
    void setGameScore(int score);
    std::string getName();
    std::string getLogo();
};
#endif //NBASIM_TEAM_H
