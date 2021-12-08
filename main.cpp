/*
Author: Bella Poage, Chris Burgett, Justin Lau, Dylan Knyoch
Class : ECE4122
Last Date Modified : 12-7-2021
Description :
	Create an NBA simulation with 32 teams including the 30 professional NBA teams along with
 Buzz and Ramblin' Wreck. This file randomly creates our teams with players with random names
 and attributes. Then it simulates the actual season using Open MP to increase the speed of
 games and SFML to show the graphics. The graphics consist of displaying the team names that
 are continuing through each round of the tournament on the bracket, as well as a Box Score
 of the final game with the players outputs.
*/

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

using namespace sf;

int main()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	srand(seed);
	// Create a video mode object
	VideoMode vm(1920, 1080);

	// Create and open a window for the game
	RenderWindow window(vm, "NBA Simulation", Style::Resize | Style::Close);

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

    bool initialDisplay = false;
    bool started = false;
    bool nextSelected = false;
    bool roundOneCalc = false;
    bool roundOneVisible = false;
    bool roundTwoCalc = false;
    bool roundTwoVisible = false;
    bool roundThreeCalc = false;
    bool roundThreeVisible = false;
    bool roundFourCalc = false;
    bool roundFourVisible = false;
    bool champCalc = false;
    bool championVisible = false;

    std::vector<Text> leftColOneTeams;
    std::vector<Text> rightColOneTeams;
    std::vector<Text> leftColTwoTeams;
    std::vector<Text> rightColTwoTeams;
    std::vector<Text> leftColThreeTeams;
    std::vector<Text> rightColThreeTeams;
    std::vector<Text> leftColFourTeams;
    std::vector<Text> rightColFourTeams;
    Text leftChampTeam;
    Text rightChampTeam;
    Text winnerText;
    Sprite winnerLogo;

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
                    //Escape pressed to close
                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        window.close();
                    }
                    //Enter pressed
                    else if (event.key.code == sf::Keyboard::Enter)
                    {
                        nextSelected = true;
                    }
                    break;
                default:
                    break;
            }
        }
        //if nextSelected allow next round of games
        if (nextSelected)
        {
            nextSelected = false;
            if (!started)
            {
                started = true;
                initialDisplay = true;
            }
            else if (!roundOneVisible)
            {
                roundOneVisible = true;
                roundOneCalc = true;
            }
            else if (!roundTwoVisible)
            {
                roundTwoVisible = true;
                roundTwoCalc = true;
            }
            else if (!roundThreeVisible)
            {
                roundThreeVisible = true;
                roundThreeCalc = true;
            }
            else if (!roundFourVisible)
            {
                roundFourVisible = true;
                roundFourCalc = true;
            }
            else if (!championVisible)
            {
                championVisible = true;
                champCalc = true;
            }
        }
        //start with 16 teams on both sides
        if (initialDisplay)
        {
            std::cout << "started" << std::endl;
            // SPLIT TEAMS
            //first half of teams in the left most column
            for (int i = 0; i < 16; i++)
            {
                leftColumnOne.push_back(randomTeams.at(i));
                myText.setString(leftColumnOne.at(i).getName());
                myText.setPosition(50.0f, 140.0f + 55.0f * i);
                myText.setFillColor(Color(255, 0, 0));
                myText.setCharacterSize(25);
                leftColOneTeams.push_back(myText);
            }
            //second half of teams in right most column
            for (int i = 16; i < 32; i++)
            {
                rightColumnOne.push_back(randomTeams.at(i));
                myText.setString(rightColumnOne.at(i - 16).getName());
                myText.setPosition(1725.0f, 140.0f + 55.0f * (i - 16));
                myText.setFillColor(Color(255, 0, 0));
                myText.setCharacterSize(25);
                rightColOneTeams.push_back(myText);
            }
            initialDisplay = false;
        }
        //8 teams on both sides
        if (roundOneCalc)
        {
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
                leftColTwoTeams.push_back(myText);
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
                rightColTwoTeams.push_back(myText);
            }
            roundOneCalc = false;
        }
        // 4 teams on both sides
        if (roundTwoCalc)
        {
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
                leftColThreeTeams.push_back(myText);
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
                rightColThreeTeams.push_back(myText);
            }
            roundTwoCalc = false;
        }
        //2 teams on each side
        if (roundThreeCalc)
        {
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
                leftColFourTeams.push_back(myText);
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
                rightColFourTeams.push_back(myText);
            }
            roundThreeCalc = false;
        }
        //find finalists
        if (roundFourCalc)
        {
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
                leftChampTeam = myText;
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
                rightChampTeam = myText;
            }
            roundFourCalc = false;
        }
        //calculate the overall winner
        if (champCalc)
        {
            // PLAY CHAMPIONSHIP
            Game curr(championship.at(0), championship.at(1));
            curr.fullGameSimulation();
            std::cout << "The Championship Winner is: " << curr.getWinner().getName() << " the score was "
                      << curr.getWinner().getGameScore()
                      << " and " << curr.getLoser().getGameScore() << std::endl;
            myText.setString(curr.getWinner().getName());
            myText.setPosition(900.0f, 650);
            curr.getWinner().getLogo()->setPosition(915.0f, 525.0f);
            winnerLogo = *curr.getWinner().getLogo();
            winnerText = myText;
            champCalc = false;
        }
        //draw the screen
        window.clear();
        window.draw(spriteBackground);
        //outside column
        if (started)
        {
            for (int i = 0; i < 16; i++)
            {
                window.draw(leftColOneTeams.at(i));
                window.draw(rightColOneTeams.at(i));
            }
        }
        //sweet 16 columns
        if (roundOneVisible)
        {
            for (int i = 0; i < 8; i++)
            {
                window.draw(leftColTwoTeams.at(i));
                window.draw(rightColTwoTeams.at(i));
            }
        }
        //elite 8 columns
        if (roundTwoVisible)
        {
            for (int i = 0; i < 4; i++)
            {
                window.draw(leftColThreeTeams.at(i));
                window.draw(rightColThreeTeams.at(i));
            }
        }
        //final 4 columns
        if (roundThreeVisible)
        {
            for (int i = 0; i < 2; i++)
            {
                window.draw(leftColFourTeams.at(i));
                window.draw(rightColFourTeams.at(i));
            }
        }
        //championship game teams
        if (roundFourVisible)
        {
            window.draw(leftChampTeam);
            window.draw(rightChampTeam);
        }
        //champion!!
        if (championVisible)
        {
            window.draw(winnerLogo);
            window.draw(winnerText);
        }
        window.display();
    }
	return 0;
}