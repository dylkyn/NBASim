/*
Author: Bella Poage, Chris Burgett, Justin Lau, Dylan Knyoch
Class : ECE4122
Last Date Modified : 12-7-2021
Description :
	Header file for the team class containing all of the class variables and functions.
*/

#ifndef NBASIM_TEAM_H
#define NBASIM_TEAM_H
#include "Player.h"
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;
class Team
{
 private:
	Player players[5];
	int gameScore;
	std::string teamName;
	Texture teamTex;
	Sprite teamLogo;
	int seriesScore;
	bool status;
 public:
	Team();
	Team(std::string name, std::string logo);
	Player getPlayer();
    Player getPlayer(int playerType);
	int getGameScore();
	void resetTeamScore();
	void setGameScore(int score);
	void setStatus(bool stat);
	bool getStatus();
	std::string getName();
	Sprite* getLogo();
	int getSeriesScore();
	void increaseSeriesScore();
};
#endif //NBASIM_TEAM_H
