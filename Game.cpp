#include "Game.h"
#include <omp.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

Game::Game(Team team1, Team team2)
{
    this ->team1 = team1;
    this ->team2 = team2;
    team1.setGameScore(0);
    team2.setGameScore(0);
    team2Score = 0;
}
void Game::setWinner(Team team)
{
    winner = team;
}
Team Game::getWinner()
{
    return winner;
}
void Game::setTeamScore(int newScore, Team team)
{
    team.setGameScore(newScore);
}
//void Game::setTeam2Score(int newScore)
//{
//    team2Score = newScore;
//}
//int Game::getTeam1Score()
//{
//    return team1Score;
//}
//int Game::getTeam2Score()
//{
//    return team2Score;
//}
void Game::possessionSimulation(Team offense, Team defense)
{
    bool assist = false;
    Player offender = offense.getPlayer();
    Player assister = offense.getPlayer();
    Player defender = defense.getPlayer();
    while(offender.getPosition() == assister.getPosition())
    {
        assister = offense.getPlayer(); //This while loop makes sure that two different players are selected
    }
    srand (time(NULL));
//	v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014

    int pass = rand() % offender.getPass() + 1;
    int shoot = rand() % offender.getShoot() + 1;

    if (pass >= shoot)
    {
        assist = true;
        std::swap(offender, assister); //https://www.cplusplus.com/reference/algorithm/swap/ need to include <algorithms>
    }

    int twoPoint = rand() % offender.getTwoPointShot() + 1;
    int threePoint = rand() % offender.getThreePointShot() + 1;

    if (twoPoint >= threePoint)
    {
        int block = rand() % defender.getBlock() + 1;
        int rebound = rand() % defender.getRebound() + 1;
        if(block >= rebound)
        {
            twoPoint = rand() % offender.getTwoPointShot() + 1; //This is ran for a second time due to the bias that would be created from it winning against the three point in the first time. This will be same logic for block being re-ran.

            block = rand() % defender.getBlock() + 1;

            if (block <= twoPoint)
            {
                offense.setGameScore(offense.getGameScore() + 2); //I do not know how we are doing and setting up the game but this is lowkey pseudocode here
                offender.setNumTwo(offender.getNumTwo() + 1);
                if (assist)
                {
                    assister.setNumAssist(assister.getNumAssist() + 1); //this is just updating how many assists the player has. We can also do this by updating something within the Game file where its like the number of assists the player pos has
                }
            }
            else
            {
                defender.setNumBlocks(defender.getNumBlocks() + 1);
                offender.setNumMissedTwo(offender.getNumMissedTwo() + 1);
            }
        }
        else
        {
            twoPoint = rand() % offender.getTwoPointShot() + 1; //This is ran for a second time due to the bias that would be created from it winning against the three point in the first time. This will be same logic for block being re-ran.

            rebound = rand() % defender.getBlock() + 1;

            if (rebound <= twoPoint)
            {
                offense.setGameScore(offense.getGameScore() + 2); //I do not know how we are doing and setting up the game but this is lowkey pseudocode here
                offender.setNumTwo(offender.getNumTwo() + 1);
                if (assist)
                {
                    assister.setNumAssist(assister.getNumAssist() + 1); //this is just updating how many assists the player has. We can also do this by updating something within the Game file where its like the number of assists the player pos has
                }
            }
            else
            {
                defender.setNumRebounds(defender.getNumRebounds() + 1);
                offender.setNumMissedTwo(offender.getNumMissedTwo() + 1);

            }
        }
    }
    else
    {
        int perimeterD = rand() % defender.getPerimeterDefense() + 1;
        threePoint = rand() % offender.getThreePointShot() + 1;

        if (threePoint >= perimeterD)
        {
            offense.setGameScore(offense.getGameScore() + 3); //I do not know how we are doing and setting up the game but this is lowkey pseudocode here
            offender.setNumThree(offender.getNumThree() + 1);
            if (assist)
            {
                assister.setNumAssist(assister.getNumAssist() + 1); //this is just updating how many assists the player has. We can also do this by updating something within the Game file where its like the number of assists the player pos has
            }
        }
        else
        {
            defender.setNumSteals(defender.getNumSteals() + 1);
            offender.setNumMissedThree(offender.getNumMissedThree() + 1);
        }
    }
}

Team Game::fullGameSimulation()
{
    #pragma omp parallel for default(shared) private(i) schedule(static, chunk) reduction(+:totalArea)
    for (int i = 0; i < 103; i++)
    {
        possessionSimulation(team1, team2);
        possessionSimulation(team2, team1);
    }
    if (team1.getGameScore() == team2.getGameScore())
    {
        int pickWinner = rand() % 2;
        winner = pickWinner == 0 ? team1 : team2;
        Player addScore = winner.getPlayer();
        addScore.setNumTwo(addScore.getNumTwo() + 1);
        winner.setGameScore(winner.getGameScore() + 2);
    }
    else if (team1.getGameScore() > team2.getGameScore())
    {
        winner = team1;
    }
    else
    {
        winner = team2;
    }
    return winner;
}
