#include "Player.h"
#include "Team.h"
#include "Game.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <vector>
#include <chrono>
#include <random>

using namespace sf;

int main()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	srand(seed);
	// Create a video mode object
	VideoMode vm(1920, 1080);

	// Create and open a window for the game
	RenderWindow window(vm, "NBA Simulation", Style::Resize);

	// Create a texture to hold a graphic on the GPU
	Texture textureBackground;
	// Load a graphic into the texture
	textureBackground.loadFromFile("../graphics/background.png");

	// Create a sprite
	Sprite spriteBackground;

	// Attach the texture to the sprite
	spriteBackground.setTexture(textureBackground);

	// Set the spriteBackground to cover the screen
	spriteBackground.setPosition(0, 0);

	//create vector of teams
	std::vector<Team> teams;
	Team hawks("Hawks", "../graphics/hawks.png");
	teams.push_back(hawks);
	Team thunder("Thunder", "../graphics/thunder.png");
	teams.push_back(thunder);
	Team celtics("Celtics", "../graphics/celtics.png");
	teams.push_back(celtics);
	Team nets("Nets", "../graphics/nets.png");
	teams.push_back(nets);
	Team hornets("Hornets", "../graphics/hornets.png");
	teams.push_back(hornets);
	Team cavaliers("Cavaliers", "../graphics/cavaliers.png");
	teams.push_back(cavaliers);
	Team mavericks("Mavericks", "../graphics/mavericks.png");
	teams.push_back(mavericks);
	Team nuggets("Nuggets", "../graphics/nuggets.png");
	teams.push_back(nuggets);
	Team pistons("Pistons", "../graphics/pistons.png");
	teams.push_back(pistons);
	Team warriors("Warriors", "../graphics/warriors.png");
	teams.push_back(warriors);
	Team rockets("Rockets", "../graphics/rockets.png");
	teams.push_back(rockets);
	Team pacers("Pacers", "../graphics/pacers.png");
	teams.push_back(pacers);
	Team lakers("Lakers", "../graphics/lakers.png");
	teams.push_back(lakers);
	Team grizzlies("Grizzlies", "../graphics/grizzlies.png");
	teams.push_back(grizzlies);
	Team bucks("Bucks", "../graphics/bucks.png");
	teams.push_back(bucks);
	Team timberwolves("Timberwolves", "../graphics/timberwolves.png");
	teams.push_back(timberwolves);
	Team pelicans("Pelicans", "../graphics/pelicans.png");
	teams.push_back(pelicans);
	Team knicks("Knicks", "../graphics/knicks.png");
	teams.push_back(knicks);
	Team magic("Magic", "../graphics/magic.png");
	teams.push_back(magic);
	Team the76ers("76ers", "../graphics/76ers.png");
	teams.push_back(the76ers);
	Team suns("Suns", "../graphics/suns.png");
	teams.push_back(suns);
	Team blazers("Blazers", "../graphics/blazers.png");
	teams.push_back(blazers);
	Team spurs("Spurs", "../graphics/spurs.png");
	teams.push_back(spurs);
	Team raptors("Raptors", "../graphics/raptors.png");
	teams.push_back(raptors);
	Team jazz("Jazz", "../graphics/jazz.png");
	teams.push_back(jazz);
	Team heat("Heat", "../graphics/heat.png");
	teams.push_back(heat);
	Team wizards("Wizards", "../graphics/wizards.png");
	teams.push_back(wizards);
	Team clippers("Clippers", "../graphics/clippers.png");
	teams.push_back(clippers);
	Team kings("Kings", "../graphics/kings.png");
	teams.push_back(kings);
	Team buzz("Buzz", "../graphics/buzz.png");
	teams.push_back(buzz);
	Team wreck("Ramblin' Wreck", "../graphics/wreck.png");
	teams.push_back(wreck);
	Team bulls("Bulls", "../graphics/bulls.png");
	teams.push_back(bulls);

	//randomly shuffle teams
	std::vector<Team> randomTeams;
	randomTeams = teams;
	// obtain a time-based seed.
	std::shuffle(randomTeams.begin(), randomTeams.end(), std::default_random_engine(seed));
	//place teams in columns
	std::vector<Team> leftColumnOne;
	std::vector<Team> rightColumnOne;
	std::vector<Team> leftColumnTwo;
	std::vector<Team> rightColumnTwo;
	std::vector<Team> leftColumnThree;
	std::vector<Team> rightColumnThree;
	std::vector<Team> leftColumnFour;
	std::vector<Team> rightColumnFour;
	std::vector<Team> championship;

	// SPLIT TEAMS
	//first half of teams in the left most column
	for (int i = 0; i < 16; i++)
	{
		leftColumnOne.push_back(randomTeams.at(i));
	}
	//second half of teams in right most column
	for (int i = 16; i < 32; i++)
	{
		rightColumnOne.push_back(randomTeams.at(i));
	}

	// PLAY ROUND 1
	//Above the left most and right most teams are put into their respected vectors
	for (int i = 0; i < leftColumnOne.size(); i += 2)
	{
		Game curr(leftColumnOne.at(i), leftColumnOne.at(i + 1));
		curr.fullGameSimulation();
		leftColumnTwo.push_back(curr.getWinner());
		std::cout << "Round 1 left Winner is: " << curr.getWinner().getName() << " the score was "
				  << curr.getWinner().getGameScore()
				  << " and " << curr.getLoser().getGameScore() << std::endl;
	}
	for (int i = 0; i < rightColumnOne.size(); i += 2)
	{
		Game curr(rightColumnOne.at(i), rightColumnOne.at(i + 1));
		curr.fullGameSimulation();
		rightColumnTwo.push_back(curr.getWinner());

		std::cout << "Round 1 right Winner is: " << curr.getWinner().getName() << " the score was "
				  << curr.getWinner().getGameScore()
				  << " and " << curr.getLoser().getGameScore() << std::endl;
	}

	// PLAY ROUND 2
	for (int i = 0; i < leftColumnTwo.size(); i += 2)
	{
		Game curr(leftColumnTwo.at(i), leftColumnTwo.at(i + 1));
		curr.fullGameSimulation();
		leftColumnThree.push_back(curr.getWinner());
		std::cout << "Round 2 left Winner is: " << curr.getWinner().getName() << " the score was "
				  << curr.getWinner().getGameScore()
				  << " and " << curr.getLoser().getGameScore() << std::endl;
	}
	for (int i = 0; i < rightColumnTwo.size(); i += 2)
	{
		Game curr(rightColumnTwo.at(i), rightColumnTwo.at(i + 1));
		curr.fullGameSimulation();
		rightColumnThree.push_back(curr.getWinner());
		std::cout << "Round 2 right Winner is: " << curr.getWinner().getName() << " the score was "
				  << curr.getWinner().getGameScore()
				  << " and " << curr.getLoser().getGameScore() << std::endl;
	}

	// PLAY ROUND 3
	for (int i = 0; i < leftColumnThree.size(); i += 2)
	{
		Game curr(leftColumnThree.at(i), leftColumnThree.at(i + 1));
		curr.fullGameSimulation();
		leftColumnFour.push_back(curr.getWinner());
		std::cout << "Round 3 left Winner is: " << curr.getWinner().getName() << " the score was "
				  << curr.getWinner().getGameScore()
				  << " and " << curr.getLoser().getGameScore() << std::endl;
	}
	for (int i = 0; i < rightColumnThree.size(); i += 2)
	{
		Game curr(rightColumnThree.at(i), rightColumnThree.at(i + 1));
		curr.fullGameSimulation();
		rightColumnFour.push_back(curr.getWinner());
		std::cout << "Round 3 right Winner is: " << curr.getWinner().getName() << " the score was "
				  << curr.getWinner().getGameScore()
				  << " and " << curr.getLoser().getGameScore() << std::endl;
	}

	// PLAY ROUND 4
	for (int i = 0; i < leftColumnFour.size(); i += 2)
	{
		Game curr(leftColumnFour.at(i), leftColumnFour.at(i + 1));
		curr.fullGameSimulation();
		championship.push_back(curr.getWinner());
		std::cout << "Round 4 left Winner is: " << curr.getWinner().getName() << " the score was "
				  << curr.getWinner().getGameScore()
				  << " and " << curr.getLoser().getGameScore() << std::endl;
	}
	for (int i = 0; i < rightColumnFour.size(); i += 2)
	{
		Game curr(rightColumnFour.at(i), rightColumnFour.at(i + 1));
		curr.fullGameSimulation();
		championship.push_back(curr.getWinner());
		std::cout << "Round 4 right Winner is: " << curr.getWinner().getName() << " the score was "
				  << curr.getWinner().getGameScore()
				  << " and " << curr.getLoser().getGameScore() << std::endl;
	}

	// PLAY CHAMPIONSHIP
	Game curr(championship.at(0), rightColumnFour.at(1));
	curr.fullGameSimulation();
	std::cout << "The Championship Winner is: " << curr.getWinner().getName() << " the score was "
			  << curr.getWinner().getGameScore()
			  << " and " << curr.getLoser().getGameScore() << std::endl;

	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			switch (e.type)
			{
			case sf::Event::EventType::Closed:
				window.close();
				break;
			}
		}
		window.clear();
		window.draw(spriteBackground);
		window.display();
	}
	return 0;
}