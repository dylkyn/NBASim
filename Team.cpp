/*
Author: Bella Poage, Chris Burgett, Justin Lau, Dylan Knyoch
Class : ECE4122
Last Date Modified : 12-7-2021
Description :
	File contains the methods to make a single team function.
*/

#include "Team.h"
#include <stdlib.h>
#include <iostream>
/**
 * Team constructor that takes in a name and a logo string.
 *
 * @param name team name
 * @param logo team logo picture location in files
 */
Team::Team(std::string name, std::string logo)
{
	players[0] = Player(1); //point guard
	players[1] = Player(2); //shooting guard
	players[2] = Player(3); //center
	players[3] = Player(4); //power forward
	players[4] = Player(5); //small forward
	teamName = name;
	teamTex.loadFromFile(logo);
	teamLogo.setTexture(teamTex);
	gameScore = 0;
	seriesScore = 0;
	status = false;
}
/*
 * Team default constructor.
 */
Team::Team()
{
	Team("Invalid Team", "../graphics/hawks.png");
}
/*
 * Get a random player off of the team.
 * @return the random player to use for the current function
 */
Player Team::getPlayer()
{
	int player = rand() % 5;
	return players[player];
}
/*
 * For a new game, reset the score to 0.
 */

Player Team::getPlayer(int playerType)
{
    return players[playerType];
}

void Team::resetTeamScore()
{
	gameScore = 0;
}
/*
 * Getter and setter methods.
 */
void Team::setGameScore(int score)
{
	gameScore += score;
}

int Team::getGameScore()
{
	return gameScore;
}

bool Team::getStatus()
{
	return status;
}

void Team::setStatus(bool stat)
{
	status = stat;
}

int Team::getSeriesScore()
{
	return seriesScore;
}
void Team::increaseSeriesScore()
{
	seriesScore += 1;
}

std::string Team::getName()
{
	return teamName;
}
Sprite* Team::getLogo()
{
	return &teamLogo;
}
