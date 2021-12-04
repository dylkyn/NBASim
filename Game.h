#ifndef NBASIM_GAME_H
#define NBASIM_GAME_H
#include "Team.h"
class Game
{
private:
    Team team1;
    Team team2;
    Team winner;
    Team loser;
    int team1Score;
    int team2Score;
public:
    Game(Team& team1, Team& team2);
    void setWinner(Team team);
    Team& getWinner();
    Team& getLoser();
    void setTeamScore(int newScore, Team team);

    void possessionSimulation(Team& offense, Team& defense);
    Team fullGameSimulation();
};
#endif //NBASIM_GAME_H
