#ifndef NBASIM_GAME_H
#define NBASIM_GAME_H
#include "Team.h"
class Game
{
private:
    Team team1;
    Team team2;
    Team winner;
    int team1Score;
    int team2Score;
public:
    Game(Team team1, Team team2);
    void setWinner(Team team);
    Team getWinner();
    void setTeamScore(int newScore, Team team);
//    void setTeam2Score(int newScore);
    int getTeam1Score();
    int getTeam2Score();

    void possessionSimulation(Team offense, Team defense);
};
#endif //NBASIM_GAME_H
