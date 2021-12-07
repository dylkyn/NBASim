#include "Player.h"
#include "Team.h"
#include "Game.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <thread>
#include <vector>
#include <chrono>
#include <random>
#include <mshtmlc.h>

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

	window.clear();
	window.draw(spriteBackground);

	//create vector of teams
	std::vector<Team> teams;
	Team hawks("Hawks", "../resized/hawks.png");
	teams.push_back(hawks);
	Team thunder("Thunder", "../resized/thunder.png");
	teams.push_back(thunder);
	Team celtics("Celtics", "../resized/celtics.png");
	teams.push_back(celtics);
	Team nets("Nets", "../resized/nets.png");
	teams.push_back(nets);
	Team hornets("Hornets", "../resized/hornets.png");
	teams.push_back(hornets);
	Team cavaliers("Cavaliers", "../resized/cavaliers.png");
	teams.push_back(cavaliers);
	Team mavericks("Mavericks", "../resized/mavericks.png");
	teams.push_back(mavericks);
	Team nuggets("Nuggets", "../resized/nuggets.png");
	teams.push_back(nuggets);
	Team pistons("Pistons", "../resized/pistons.png");
	teams.push_back(pistons);
	Team warriors("Warriors", "../resized/warriors.png");
	teams.push_back(warriors);
	Team rockets("Rockets", "../resized/rockets.png");
	teams.push_back(rockets);
	Team pacers("Pacers", "../resized/pacers.png");
	teams.push_back(pacers);
	Team lakers("Lakers", "../resized/lakers.png");
	teams.push_back(lakers);
	Team grizzlies("Grizzlies", "../resized/grizzlies.png");
	teams.push_back(grizzlies);
	Team bucks("Bucks", "../resized/bucks.png");
	teams.push_back(bucks);
	Team timberwolves("Timberwolves", "../resized/timberwolves.png");
	teams.push_back(timberwolves);
	Team pelicans("Pelicans", "../resized/pelicans.png");
	teams.push_back(pelicans);
	Team knicks("Knicks", "../resized/knicks.png");
	teams.push_back(knicks);
	Team magic("Magic", "../resized/magic.png");
	teams.push_back(magic);
	Team the76ers("76ers", "../resized/76ers.png");
	teams.push_back(the76ers);
	Team suns("Suns", "../resized/suns.png");
	teams.push_back(suns);
	Team blazers("Blazers", "../resized/blazers.png");
	teams.push_back(blazers);
	Team spurs("Spurs", "../resized/spurs.png");
	teams.push_back(spurs);
	Team raptors("Raptors", "../resized/raptors.png");
	teams.push_back(raptors);
	Team jazz("Jazz", "../resized/jazz.png");
	teams.push_back(jazz);
	Team heat("Heat", "../resized/heat.png");
	teams.push_back(heat);
	Team wizards("Wizards", "../resized/wizards.png");
	teams.push_back(wizards);
	Team clippers("Clippers", "../resized/clippers.png");
	teams.push_back(clippers);
	Team kings("Kings", "../resized/kings.png");
	teams.push_back(kings);
	Team buzz("Buzz", "../resized/buzz.png");
	teams.push_back(buzz);
	Team wreck("Ramblin' Wreck", "../resized/wreck.png");
	teams.push_back(wreck);
	Team bulls("Bulls", "../resized/bulls.png");
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

	// Declare a new font
	sf::Font font;
	// Load it from a file
	if (!font.loadFromFile("../font.ttf"))
	{
		std::cout << "Oh shit, no font." << std::endl;
	}
	Text myText;
	myText.setFont(font);
	myText.setCharacterSize(25);
	myText.setStyle(sf::Text::Regular);
	myText.setFillColor(Color(255, 0, 0));

	std::chrono::milliseconds duration(250);
	std::this_thread::sleep_for(duration);
    //next button
//    Text next;
//    next.setFont(font);
//    next.setString("Next Round");
//    next.setPosition(1500, 975);
//    next.setCharacterSize(40);
//    next.setStyle(sf::Text::Regular);
//    next.setFillColor(Color(0, 0, 0));

    bool nextSelected = false;

//	std::chrono::seconds dura( 5);
//	std::this_thread::sleep_for( dura );

	// SPLIT TEAMS
	//first half of teams in the left most column
	for (int i = 0; i < 16; i++)
	{
		leftColumnOne.push_back(randomTeams.at(i));
		myText.setString(leftColumnOne.at(i).getName());
		myText.setPosition(50.0f, 135.0f + 55.0f * i);
		window.draw(myText);
	}
	//second half of teams in right most column
	for (int i = 16; i < 32; i++)
	{
		rightColumnOne.push_back(randomTeams.at(i));
		myText.setString(rightColumnOne.at(i - 16).getName());
		myText.setPosition(1715.0f, 135.0f + 55.0f * (i - 16));
		window.draw(myText);
	}
	window.display();
	std::this_thread::sleep_for(dura);
	window.clear();
	window.draw(spriteBackground);
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
		myText.setString(curr.getWinner().getName());
		myText.setPosition(235.0f, 160.0f + 55.0f * i);
		window.draw(myText);
	}
	for (int i = 0; i < rightColumnOne.size(); i += 2)
	{
		Game curr(rightColumnOne.at(i), rightColumnOne.at(i + 1));
		curr.fullGameSimulation();
		rightColumnTwo.push_back(curr.getWinner());
		std::cout << "Round 1 right Winner is: " << curr.getWinner().getName() << " the score was "
				  << curr.getWinner().getGameScore()
				  << " and " << curr.getLoser().getGameScore() << std::endl;
		myText.setString(curr.getWinner().getName());
		myText.setPosition(1550.0f, 160.0f + 55.0f * i);
		window.draw(myText);
	}
	window.display();
	std::this_thread::sleep_for(dura);
	window.clear();
	window.draw(spriteBackground);
	// PLAY ROUND 2
	for (int i = 0; i < leftColumnTwo.size(); i += 2)
	{
		Game curr(leftColumnTwo.at(i), leftColumnTwo.at(i + 1));
		curr.fullGameSimulation();
		leftColumnThree.push_back(curr.getWinner());
		std::cout << "Round 2 left Winner is: " << curr.getWinner().getName() << " the score was "
				  << curr.getWinner().getGameScore()
				  << " and " << curr.getLoser().getGameScore() << std::endl;
		myText.setString(curr.getWinner().getName());
		myText.setPosition(400.0f, 220.0f + 110.0f * i);
		window.draw(myText);
	}
	for (int i = 0; i < rightColumnTwo.size(); i += 2)
	{
		Game curr(rightColumnTwo.at(i), rightColumnTwo.at(i + 1));
		curr.fullGameSimulation();
		rightColumnThree.push_back(curr.getWinner());
		std::cout << "Round 2 right Winner is: " << curr.getWinner().getName() << " the score was "
				  << curr.getWinner().getGameScore()
				  << " and " << curr.getLoser().getGameScore() << std::endl;
		myText.setString(curr.getWinner().getName());
		myText.setPosition(1380.0f, 220.0f + 110.0f * i);
		window.draw(myText);
	}
	window.display();
	std::this_thread::sleep_for(dura);
	window.clear();
	window.draw(spriteBackground);
	// PLAY ROUND 3
	for (int i = 0; i < leftColumnThree.size(); i += 2)
	{
		Game curr(leftColumnThree.at(i), leftColumnThree.at(i + 1));
		curr.fullGameSimulation();
		leftColumnFour.push_back(curr.getWinner());
		std::cout << "Round 3 left Winner is: " << curr.getWinner().getName() << " the score was "
				  << curr.getWinner().getGameScore()
				  << " and " << curr.getLoser().getGameScore() << std::endl;
		myText.setString(curr.getWinner().getName());
		myText.setPosition(570.0f, 330.0f + 220.0f * i);
		window.draw(myText);
	}
	for (int i = 0; i < rightColumnThree.size(); i += 2)
	{
		Game curr(rightColumnThree.at(i), rightColumnThree.at(i + 1));
		curr.fullGameSimulation();
		rightColumnFour.push_back(curr.getWinner());
		std::cout << "Round 3 right Winner is: " << curr.getWinner().getName() << " the score was "
				  << curr.getWinner().getGameScore()
				  << " and " << curr.getLoser().getGameScore() << std::endl;
		myText.setString(curr.getWinner().getName());
		myText.setPosition(1215.0f, 330.0f + 220.0f * i);
		window.draw(myText);
	}
	window.display();
	std::this_thread::sleep_for(dura);
	window.clear();
	window.draw(spriteBackground);
	// PLAY ROUND 4
	for (int i = 0; i < leftColumnFour.size(); i += 2)
	{
		Game curr(leftColumnFour.at(i), leftColumnFour.at(i + 1));
		curr.fullGameSimulation();
		championship.push_back(curr.getWinner());
		std::cout << "Round 4 left Winner is: " << curr.getWinner().getName() << " the score was "
				  << curr.getWinner().getGameScore()
				  << " and " << curr.getLoser().getGameScore() << std::endl;
		myText.setString(curr.getWinner().getName());
		myText.setPosition(735.0f, 550);
		window.draw(myText);
	}
	for (int i = 0; i < rightColumnFour.size(); i += 2)
	{
		Game curr(rightColumnFour.at(i), rightColumnFour.at(i + 1));
		curr.fullGameSimulation();
		championship.push_back(curr.getWinner());
		std::cout << "Round 4 right Winner is: " << curr.getWinner().getName() << " the score was "
				  << curr.getWinner().getGameScore()
				  << " and " << curr.getLoser().getGameScore() << std::endl;
		myText.setString(curr.getWinner().getName());
		myText.setPosition(1050.0f, 550);
		window.draw(myText);
	}
	window.display();
	std::this_thread::sleep_for(dura);
	window.clear();
	window.draw(spriteBackground);
	// PLAY CHAMPIONSHIP
	Game curr(championship.at(0), rightColumnFour.at(1));
	curr.fullGameSimulation();
	std::cout << "The Championship Winner is: " << curr.getWinner().getName() << " the score was "
			  << curr.getWinner().getGameScore()
			  << " and " << curr.getLoser().getGameScore() << std::endl;
	myText.setString(curr.getWinner().getName());
	myText.setPosition(900.0f, 650);
	window.draw(myText);
	window.display();
	std::this_thread::sleep_for(dura);
	while (window.isOpen())
	{
        sf::Event event;

    // while there are pending events...
        while (window.pollEvent(event))
        {
            // check the type of the event...
            switch (event.type)
            {
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;

                    // key pressed
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        window.close();
                    }
                    else if (event.key.code == sf::Keyboard::Enter)
                    {
                        nextSelected = true;
                    }
                    break;
                default:
                    break;
            }
        }
        window.clear();
        if (nextSelected)
        {
            std::cout << "drawing test" << std::endl;
            window.draw(test);
        }

		window.draw(spriteBackground);
		window.draw(myText);
		window.display();
	}
	return 0;
}