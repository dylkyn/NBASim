#ifndef NBASIM_TEAM_H
#define NBASIM_TEAM_H
#include "Player.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
class Team
{
 private:
	Player players[5];
	int gameScore;
	std::string teamName;
	Sprite teamLogo;
	int seriesScore;
 public:
	Team();
	Team(std::string name, std::string logo);
	Player getPlayer();
	int getGameScore();
	void resetTeamScore();
	void setGameScore(int score);
	std::string getName();
	Sprite getLogo();
	int getSeriesScore();
	void increaseSeriesScore();
};
#endif //NBASIM_TEAM_H
