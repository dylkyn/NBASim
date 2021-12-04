#include "Team.h"
#include <stdlib.h>
#include <time.h>

Team::Team(std::string name)
{
    players[0] = new Player(1); //point guard
    players[1] = new Player(2); //shooting guard
    players[2] = new Player(3); //center
    players[3] = new Player(4); //power forward
    players[4] = new Player(5); //small forward
    teamName = name;

    gameScore = 0;
}
Team::Team()
{
    Team("Invalid Team");
}

Player Team::getPlayer()
{
    srand(time(NULL));
    int player = rand() % 5;
    return players[player];
}

void Team::setGameScore(int score) {
    gameScore = score;
}

int Team::getGameScore() {
    return gameScore;
}
