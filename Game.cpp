#include "Game.h"

Game::Game(Team team1, Team team2)
{
    this ->team1 = team1;
    this ->team2 = team2;
    team1Score = 0;
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
void Game::setTeam1Score(int newScore)
{
    team1Score = newScore;
}
void Game::setTeam2Score(int newScore)
{
    team2Score = newScore;
}
int Game::getTeam1Score()
{
    return team1Score;
}
int Game::getTeam2Score()
{
    return team2Score;
}