/*
Author: Bella Poage, Chris Burgett, Justin Lau, Dylan Knyoch
Class : ECE4122
Last Date Modified : 12-7-2021
Description :
	File contains the methods to make a single game function.
*/

#include "Game.h"
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <chrono>
/**
 * Game constructor that takes in 2 teams.
 *
 * @param team1 first team
 * @param team2 second team
 */
Game::Game(Team& team1, Team& team2)
{
	this->team1 = team1;
	this->team2 = team2;
	this->team1.setStatus(true);
	this->team2.setStatus(true);

	team1.setGameScore(0);
	team2.setGameScore(0);
}
/**
 * Getters and setters.
 */
void Game::setWinner(Team team)
{
	winner = team;
}
Team& Game::getWinner()
{
	return winner;
}
Team& Game::getLoser()
{
	return loser;
}
void Game::setTeamScore(int newScore, Team team)
{
	team.setGameScore(newScore);
}
/**
 * Simulates a single possession in a game.
 * @param offense attacking team with a random offender chosen to attack and possibly assist
 * @param defense defending team with a random defender chosen
 */
void Game::possessionSimulation(Team& offense, Team& defense)
{
	bool assist = false;
    // pick competing players
	Player offender = offense.getPlayer();
	Player assister = offense.getPlayer();

	Player defender = defense.getPlayer();

    //do not have the same player chosen twice on the offense
	while (offender.getPosition() == assister.getPosition())
	{
		assister = offense.getPlayer(); //This while loop makes sure that two different players are selected
	}
    // randomize the players' current skills based off of their attributes
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
		if (block >= rebound)
		{
			twoPoint = rand() % offender.getTwoPointShot()
					   + 1; //This is ran for a second time due to the bias that would be created from it winning against the three point in the first time. This will be same logic for block being re-ran.
			block = rand() % defender.getBlock() + 1;

			if (block <= twoPoint)
			{
				offense
					.setGameScore(2);
				offender.setNumTwo(offender.getNumTwo() + 1);
				if (assist)
				{
					assister.setNumAssist(assister.getNumAssist()
										  + 1); //this is just updating how many assists the player has
				}
			}
			else
			{
				defender.setNumBlocks(defender.getNumBlocks() + 1);
				offender.increaseMissedTwo();
			}
		}
		else
		{
			twoPoint = rand() % offender.getTwoPointShot()
					   + 1; //This is ran for a second time due to the bias that would be created from it winning against the three point in the first time. This will be same logic for block being re-ran.
			rebound = rand() % defender.getBlock() + 1;
			if (rebound <= twoPoint)
			{
				offense.setGameScore(2);
				offender.setNumTwo(offender.getNumTwo() + 1);
				if (assist)
				{
					assister.setNumAssist(assister.getNumAssist()
										  + 1); //this is just updating how many assists the player has. We can also do this by updating something within the Game file where its like the number of assists the player pos has
				}
			}
			else
			{
				defender.setNumRebounds(defender.getNumRebounds() + 1);
				offender.increaseMissedTwo();
			}
		}
	}
	else
	{
		int perimeterD = rand() % defender.getPerimeterDefense() + 1;
		threePoint = rand() % offender.getThreePointShot() + 1;

		if (threePoint >= perimeterD)
		{
			offense
				.setGameScore(3); //I do not know how we are doing and setting up the game but this is lowkey pseudocode here
			offender.setNumThree(offender.getNumThree() + 1);
			if (assist)
			{
				assister.setNumAssist(assister.getNumAssist()
									  + 1); //this is just updating how many assists the player has. We can also do this by updating something within the Game file where its like the number of assists the player pos has
			}
		}
		else
		{
			defender.setNumSteals(defender.getNumSteals() + 1);
			offender.increaseMissedThree();
		}
	}
}
/**
 * Simulates an entire game allowing 103 possessions for each team.
 *
 * @return the winning team of the game
 */
Team Game::fullGameSimulation()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);
	team1.resetTeamScore();
	team2.resetTeamScore();
#pragma omp parallel for default(shared) private(i) schedule(static, chunk) reduction(+:totalArea)
	for (int i = 0; i < 103; i++) //all of the possessions in a loop
	{
		possessionSimulation(team1, team2);
		possessionSimulation(team2, team1);
	}
    //if tie: pick winner randomly
	if (team1.getGameScore() == team2.getGameScore())
	{
		int pickWinner = rand() % 2;
		winner = pickWinner == 0 ? team1 : team2;
		loser = pickWinner != 0 ? team1 : team2;
		Player addScore = winner.getPlayer();
		addScore.setNumTwo(addScore.getNumTwo() + 1);
		winner.setGameScore(2);
	}
    //team 1 score higher, team one is winner
	else if (team1.getGameScore() > team2.getGameScore())
	{
		winner = team1;
		loser = team2;
	}
    //team 2 score higher, team 2 is winner
    else
	{
		winner = team2;
		loser = team1;
	}

	return winner;
}
