#include "Team.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

Team::Team(std::string name, std::string logo)
{
    players[0] = Player(1); //point guard
    players[1] = Player(2); //shooting guard
    players[2] = Player(3); //center
    players[3] = Player(4); //power forward
    players[4] = Player(5); //small forward
    teamName = name;
    Texture texture;
    texture.loadFromFile(logo);
    Sprite spriteTeam;
    spriteTeam.setTexture(texture);
    teamLogo = spriteTeam;
    gameScore = 0;
    seriesScore = 0;
}
Team::Team()
{
    Team("Invalid Team", "");
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
int getSeriesScore()
{
    return seriesScore;
}
int increaseSeriesScore()
{
    seriesScore += 1;
}


std::string Team::getName()
{
    return teamName;
}
Sprite Team::getLogo()
{
    return teamLogo;
}
