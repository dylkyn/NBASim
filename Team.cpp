#include "Team.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

Team::Team(std::string name std::string logo)
{
    players[0] = Player(1); //point guard
    players[1] = Player(2); //shooting guard
    players[2] = Player(3); //center
    players[3] = Player(4); //power forward
    players[4] = Player(5); //small forward
    teamName = name;
    teamLogo = logo;
    gameScore = 0;
}
Team::Team()
{
    Team("Invalid Team");
}

Player Team::getPlayer()
{
    int player = rand() % 5;
    return players[player];
}

void Team::resetTeamScore()
{
    gameScore = 0;
}

void Team::setGameScore(int score) {
    gameScore += score;
}

int Team::getGameScore() {
    return gameScore;
}
std::string Team::getName()
{
    return teamName;
}
std::string Team::getLogo()
{
    return teamLogo;
}
