/*
Author: Bella Poage, Chris Burgett, Justin Lau, Dylan Kynoch
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
#include <fstream>
#include <random>
#include <mshtmlc.h>

using namespace sf;


void exportCSV(std::ofstream* myfile, Team loser)
{
    *myfile << loser.getName() << "\n";
    *myfile << "Name, Total Points, 3pt, 3pt %, 2pt, 2pt %, Assist, Rebounds, Blocks \n";
    for (int i = 1; i < 6; i++)
    {
        *myfile << loser.getPlayer(i)->getName() << "," << loser.getPlayer(i)->getNumTwo() * 2 + loser.getPlayer(i)->getNumThree() * 3 << "," <<
        loser.getPlayer(i)->getNumThree() << "," << loser.getPlayer(i)->getNumThree() * 1.0 / ((loser.getPlayer(i)->getNumMissedThree() + loser.getPlayer(i)->getNumThree() * 1.0) * 1.0) <<
        "," << loser.getPlayer(i)->getNumTwo() << "," << loser.getPlayer(i)->getNumTwo() * 1.0 / ((loser.getPlayer(i)->getNumMissedTwo() + loser.getPlayer(i)->getNumTwo()) * 1.0) <<
        "," << loser.getPlayer(i)->getNumAssist() << "," << loser.getPlayer(i)->getNumRebounds() << "," << loser.getPlayer(i)->getNumBlocks() << "\n";
    }
}

void execute(Game* curr)
{
    curr->fullGameSimulation();
}


int main()
{

    std::ofstream myfile;
    myfile.open ("../gameExports/seasonBoxScore.csv");
    myfile << "Season Box Score\n";

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
    myText.setFillColor(Color(0, 0, 255));

//	std::chrono::milliseconds duration(250);
//	std::this_thread::sleep_for(duration);

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
	bool boxScoreVisible = false;

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

	//box score display
	Texture textureBoxScore;
	textureBoxScore.loadFromFile("../graphics/boxscore.png");
	Sprite spriteBoxScore;
	spriteBoxScore.setTexture(textureBoxScore);
	spriteBoxScore.setPosition(280, 100);
	spriteBoxScore.setScale(4.8, 4.3);

	Text boxScoreText;
	boxScoreText.setFont(font);
	boxScoreText.setCharacterSize(25);
	boxScoreText.setStyle(sf::Text::Regular);
	boxScoreText.setFillColor(Color(0, 0, 255));

	//box score variables (global)
	std::string winningTeamName;
	std::string losingTeamName;
	std::string winningPGName;
	std::string winningSGName;
	std::string winningSFName;
	std::string winningPFName;
	std::string winningCName;
	int winningTeamScore;
	int losingTeamScore;
	int winningPGpts;
	int winningPGasts;
	int winningPGrebs;
	int winningPGstls;
	int winningPGblks;
	int winningSGpts;
	int winningSGasts;
	int winningSGrebs;
	int winningSGstls;
	int winningSGblks;
	int winningSFpts;
	int winningSFasts;
	int winningSFrebs;
	int winningSFstls;
	int winningSFblks;
	int winningPFpts;
	int winningPFasts;
	int winningPFrebs;
	int winningPFstls;
	int winningPFblks;
	int winningCpts;
	int winningCasts;
	int winningCrebs;
	int winningCstls;
	int winningCblks;
	int losingPGpts;
	int losingPGasts;
	int losingPGrebs;
	int losingPGstls;
	int losingPGblks;
	int losingSGpts;
	int losingSGasts;
	int losingSGrebs;
	int losingSGstls;
	int losingSGblks;
	int losingSFpts;
	int losingSFasts;
	int losingSFrebs;
	int losingSFstls;
	int losingSFblks;
	int losingPFpts;
	int losingPFasts;
	int losingPFrebs;
	int losingPFstls;
	int losingPFblks;
	int losingCpts;
	int losingCasts;
	int losingCrebs;
	int losingCstls;
	int losingCblks;
	std::string losingPGName;
	std::string losingSGName;
	std::string losingSFName;
	std::string losingPFName;
	std::string losingCName;

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
            else if(!boxScoreVisible)
            {
                boxScoreVisible = true;
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
            for (int i = 0; i < leftColumnOne.size(); i += 8)
            {
                Game curr(leftColumnOne.at(i), leftColumnOne.at(i + 1));
                Game curr1(leftColumnOne.at(i+2), leftColumnOne.at(i + 3));
                std::thread t1(execute,&curr);
                std::thread t2(execute,&curr1);
                Game curr2(leftColumnOne.at(i+4), leftColumnOne.at(i + 5));
                Game curr3(leftColumnOne.at(i+6), leftColumnOne.at(i + 7));
                std::thread t3(execute,&curr2);
                std::thread t4(execute,&curr3);

                exportCSV(&myfile, curr.getLoser());
                exportCSV(&myfile, curr1.getLoser());
                exportCSV(&myfile, curr2.getLoser());
                exportCSV(&myfile, curr3.getLoser());

                t1.join();
                t2.join();
                t3.join();
                t4.join();
                leftColumnTwo.push_back(curr.getWinner());
                std::cout << "Round 1 left Winner is: " << curr.getWinner().getName() << " the score was "
                          << curr.getWinner().getGameScore()
                          << " and " << curr.getLoser().getGameScore() << std::endl;
                myText.setString(curr.getWinner().getName());
                myText.setPosition(235.0f, 160.0f + 55.0f * i);
                leftColTwoTeams.push_back(myText);

                leftColumnTwo.push_back(curr1.getWinner());
                std::cout << "Round 1 left Winner is: " << curr1.getWinner().getName() << " the score was "
                          << curr1.getWinner().getGameScore()
                          << " and " << curr1.getLoser().getGameScore() << std::endl;
                myText.setString(curr1.getWinner().getName());
                myText.setPosition(235.0f, 160.0f + 55.0f * (i+2));
                leftColTwoTeams.push_back(myText);

                leftColumnTwo.push_back(curr2.getWinner());
                std::cout << "Round 1 left Winner is: " << curr2.getWinner().getName() << " the score was "
                          << curr2.getWinner().getGameScore()
                          << " and " << curr2.getLoser().getGameScore() << std::endl;
                myText.setString(curr2.getWinner().getName());
                myText.setPosition(235.0f, 160.0f + 55.0f * (i+4));
                leftColTwoTeams.push_back(myText);

                leftColumnTwo.push_back(curr3.getWinner());
                std::cout << "Round 1 left Winner is: " << curr3.getWinner().getName() << " the score was "
                          << curr3.getWinner().getGameScore()
                          << " and " << curr3.getLoser().getGameScore() << std::endl;
                myText.setString(curr3.getWinner().getName());
                myText.setPosition(235.0f, 160.0f + 55.0f * (i+6));
                leftColTwoTeams.push_back(myText);
            }
            for (int i = 0; i < rightColumnOne.size(); i += 8)
            {
                Game curr(rightColumnOne.at(i), rightColumnOne.at(i + 1));
                Game curr1(rightColumnOne.at(i+2), rightColumnOne.at(i + 3));
                std::thread t1(execute,&curr);
                std::thread t2(execute,&curr1);
                Game curr2(rightColumnOne.at(i+4), rightColumnOne.at(i + 5));
                Game curr3(rightColumnOne.at(i+6), rightColumnOne.at(i + 7));
                std::thread t3(execute,&curr2);
                std::thread t4(execute,&curr3);

                exportCSV(&myfile, curr.getLoser());
                exportCSV(&myfile, curr1.getLoser());
                exportCSV(&myfile, curr2.getLoser());
                exportCSV(&myfile, curr3.getLoser());

                t1.join();
                t2.join();
                t3.join();
                t4.join();
                rightColumnTwo.push_back(curr.getWinner());
                std::cout << "Round 1 right Winner is: " << curr.getWinner().getName() << " the score was "
                          << curr.getWinner().getGameScore()
                          << " and " << curr.getLoser().getGameScore() << std::endl;
                myText.setString(curr.getWinner().getName());
                myText.setPosition(1550.0f, 160.0f + 55.0f * i);
                rightColTwoTeams.push_back(myText);

                rightColumnTwo.push_back(curr1.getWinner());
                std::cout << "Round 1 right Winner is: " << curr1.getWinner().getName() << " the score was "
                          << curr1.getWinner().getGameScore()
                          << " and " << curr1.getLoser().getGameScore() << std::endl;
                myText.setString(curr1.getWinner().getName());
                myText.setPosition(1550.0f, 160.0f + 55.0f * (i+2));
                rightColTwoTeams.push_back(myText);

                rightColumnTwo.push_back(curr2.getWinner());
                std::cout << "Round 1 right Winner is: " << curr2.getWinner().getName() << " the score was "
                          << curr2.getWinner().getGameScore()
                          << " and " << curr2.getLoser().getGameScore() << std::endl;
                myText.setString(curr2.getWinner().getName());
                myText.setPosition(1550.0f, 160.0f + 55.0f * (i+4));
                rightColTwoTeams.push_back(myText);

                rightColumnTwo.push_back(curr3.getWinner());
                std::cout << "Round 1 right Winner is: " << curr3.getWinner().getName() << " the score was "
                          << curr3.getWinner().getGameScore()
                          << " and " << curr3.getLoser().getGameScore() << std::endl;
                myText.setString(curr3.getWinner().getName());
                myText.setPosition(1550.0f, 160.0f + 55.0f * (i+6));
                rightColTwoTeams.push_back(myText);
            }
            roundOneCalc = false;
        }
        // 4 teams on both sides
        if (roundTwoCalc)
        {
            // PLAY ROUND 2
            int z = 0;
            while (z == 0)
            {
                Game curr(leftColumnTwo.at(0), leftColumnTwo.at(1));
                Game curr1(leftColumnTwo.at(2), leftColumnTwo.at(3));
                std::thread t1(execute,&curr);
                std::thread t2(execute,&curr1);
                Game curr2(leftColumnTwo.at(4), leftColumnTwo.at(5));
                Game curr3(leftColumnTwo.at(6), leftColumnTwo.at(7));
                std::thread t3(execute,&curr2);
                std::thread t4(execute,&curr3);

                t1.join();
                t2.join();
                t3.join();
                t4.join();
                exportCSV(&myfile, curr.getLoser());
                exportCSV(&myfile, curr1.getLoser());
                exportCSV(&myfile, curr2.getLoser());
                exportCSV(&myfile, curr3.getLoser());


                leftColumnThree.push_back(curr.getWinner());
                std::cout << "Round 2 left Winner is: " << curr.getWinner().getName() << " the score was "
                          << curr.getWinner().getGameScore()
                          << " and " << curr.getLoser().getGameScore() << std::endl;
                myText.setString(curr.getWinner().getName());
                myText.setPosition(400.0f, 220.0f + 110.0f * 0);
                leftColThreeTeams.push_back(myText);

                leftColumnThree.push_back(curr1.getWinner());
                std::cout << "Round 2 left Winner is: " << curr1.getWinner().getName() << " the score was "
                          << curr1.getWinner().getGameScore()
                          << " and " << curr1.getLoser().getGameScore() << std::endl;
                myText.setString(curr1.getWinner().getName());
                myText.setPosition(400.0f, 220.0f + 110.0f * 2);
                leftColThreeTeams.push_back(myText);

                leftColumnThree.push_back(curr2.getWinner());
                std::cout << "Round 2 left Winner is: " << curr2.getWinner().getName() << " the score was "
                          << curr2.getWinner().getGameScore()
                          << " and " << curr2.getLoser().getGameScore() << std::endl;
                myText.setString(curr2.getWinner().getName());
                myText.setPosition(400.0f, 220.0f + 110.0f * 4);
                leftColThreeTeams.push_back(myText);

                leftColumnThree.push_back(curr3.getWinner());
                std::cout << "Round 2 left Winner is: " << curr3.getWinner().getName() << " the score was "
                          << curr3.getWinner().getGameScore()
                          << " and " << curr3.getLoser().getGameScore() << std::endl;
                myText.setString(curr3.getWinner().getName());
                myText.setPosition(400.0f, 220.0f + 110.0f * 6);
                leftColThreeTeams.push_back(myText);
                z = 1;
            }


            int c = 0;
            while (c == 0)
            {
                Game curr(rightColumnTwo.at(0), rightColumnTwo.at(1));
                Game curr1(rightColumnTwo.at(2), rightColumnTwo.at(3));
                std::thread t1(execute,&curr);
                std::thread t2(execute,&curr1);
                Game curr2(rightColumnTwo.at(4), rightColumnTwo.at(5));
                Game curr3(rightColumnTwo.at(6), rightColumnTwo.at(7));
                std::thread t3(execute,&curr2);
                std::thread t4(execute,&curr3);

                exportCSV(&myfile, curr.getLoser());
                exportCSV(&myfile, curr1.getLoser());
                exportCSV(&myfile, curr2.getLoser());
                exportCSV(&myfile, curr3.getLoser());

                t1.join();
                t2.join();
                t3.join();
                t4.join();
                rightColumnThree.push_back(curr.getWinner());
                std::cout << "Round 2 right Winner is: " << curr.getWinner().getName() << " the score was "
                          << curr.getWinner().getGameScore()
                          << " and " << curr.getLoser().getGameScore() << std::endl;
                myText.setString(curr.getWinner().getName());
                myText.setPosition(1380.0f, 220.0f + 110.0f * 0);
                rightColThreeTeams.push_back(myText);

                rightColumnThree.push_back(curr1.getWinner());
                std::cout << "Round 2 right Winner is: " << curr1.getWinner().getName() << " the score was "
                          << curr1.getWinner().getGameScore()
                          << " and " << curr1.getLoser().getGameScore() << std::endl;
                myText.setString(curr1.getWinner().getName());
                myText.setPosition(1380.0f, 220.0f + 110.0f * 2);
                rightColThreeTeams.push_back(myText);

                rightColumnThree.push_back(curr2.getWinner());
                std::cout << "Round 2 right Winner is: " << curr2.getWinner().getName() << " the score was "
                          << curr2.getWinner().getGameScore()
                          << " and " << curr2.getLoser().getGameScore() << std::endl;
                myText.setString(curr2.getWinner().getName());
                myText.setPosition(1380.0f, 220.0f + 110.0f * 4);
                rightColThreeTeams.push_back(myText);

                rightColumnThree.push_back(curr3.getWinner());
                std::cout << "Round 2 right Winner is: " << curr3.getWinner().getName() << " the score was "
                          << curr3.getWinner().getGameScore()
                          << " and " << curr3.getLoser().getGameScore() << std::endl;
                myText.setString(curr3.getWinner().getName());
                myText.setPosition(1380.0f, 220.0f + 110.0f * 6);
                rightColThreeTeams.push_back(myText);
                c = 1;
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
                exportCSV(&myfile, curr.getLoser());

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
                exportCSV(&myfile, curr.getLoser());

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
                exportCSV(&myfile, curr.getLoser());

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
                exportCSV(&myfile, curr.getLoser());

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
            exportCSV(&myfile, curr.getLoser());
            std::cout << "The Championship Winner is: " << curr.getWinner().getName() << " the score was "
                      << curr.getWinner().getGameScore()
                      << " and " << curr.getLoser().getGameScore() << std::endl;
            myText.setString(curr.getWinner().getName());
            myText.setPosition(900.0f, 650);
            curr.getWinner().getLogo()->setPosition(915.0f, 525.0f);
            winnerLogo = *curr.getWinner().getLogo();
            winnerText = myText;
            winningTeamName = curr.getWinner().getName();
            losingTeamName = curr.getLoser().getName();
            winningTeamScore = curr.getWinner().getGameScore();
            losingTeamScore = curr.getLoser().getGameScore();
            winningPGName = curr.getWinner().getPlayer(0)->getName();
            winningSGName = curr.getWinner().getPlayer(1)->getName();
            winningSFName = curr.getWinner().getPlayer(2)->getName();
            winningPFName = curr.getWinner().getPlayer(3)->getName();
            winningCName = curr.getWinner().getPlayer(4)->getName();
            losingPGName = curr.getLoser().getPlayer(0)->getName();
            losingSGName = curr.getLoser().getPlayer(1)->getName();
            losingSFName = curr.getLoser().getPlayer(2)->getName();
            losingPFName = curr.getLoser().getPlayer(3)->getName();
            losingCName = curr.getLoser().getPlayer(4)->getName();
            winningPGpts = curr.getWinner().getPlayer(0)->getGameNumTwo() * 2 + curr.getWinner().getPlayer(0)->getGameNumThree() * 3;
            winningPGasts = curr.getWinner().getPlayer(0)->getGameNumAssist();
            winningPGrebs = curr.getWinner().getPlayer(0)->getGameNumRebounds();
            winningPGstls = curr.getWinner().getPlayer(0)->getGameNumSteals();
            winningPGblks = curr.getWinner().getPlayer(0)->getGameNumBlocks();
            winningSGpts = curr.getWinner().getPlayer(1)->getGameNumTwo() * 2 + curr.getWinner().getPlayer(1)->getGameNumThree() * 3;
            winningSGasts = curr.getWinner().getPlayer(1)->getGameNumAssist();
            winningSGrebs = curr.getWinner().getPlayer(1)->getGameNumRebounds();
            winningSGstls = curr.getWinner().getPlayer(1)->getGameNumSteals();
            winningSGblks = curr.getWinner().getPlayer(1)->getGameNumBlocks();
            winningSFpts = curr.getWinner().getPlayer(2)->getGameNumTwo() * 2 + curr.getWinner().getPlayer(2)->getGameNumThree() * 3;
            winningSFasts = curr.getWinner().getPlayer(2)->getGameNumAssist();
            winningSFrebs = curr.getWinner().getPlayer(2)->getGameNumRebounds();
            winningSFstls = curr.getWinner().getPlayer(2)->getGameNumSteals();
            winningSFblks = curr.getWinner().getPlayer(2)->getGameNumBlocks();
            winningPFpts = curr.getWinner().getPlayer(3)->getGameNumTwo() * 2 + curr.getWinner().getPlayer(3)->getGameNumThree() * 3;
            winningPFasts = curr.getWinner().getPlayer(3)->getGameNumAssist();
            winningPFrebs = curr.getWinner().getPlayer(3)->getGameNumRebounds();
            winningPFstls = curr.getWinner().getPlayer(3)->getGameNumSteals();
            winningPFblks = curr.getWinner().getPlayer(3)->getGameNumBlocks();
            winningCpts = curr.getWinner().getPlayer(4)->getGameNumTwo() * 2 + curr.getWinner().getPlayer(0)->getGameNumThree() * 3;
            winningCasts = curr.getWinner().getPlayer(4)->getGameNumAssist();
            winningCrebs = curr.getWinner().getPlayer(4)->getGameNumRebounds();
            winningCstls = curr.getWinner().getPlayer(4)->getGameNumSteals();
            winningCblks = curr.getWinner().getPlayer(4)->getGameNumBlocks();
            losingPGpts = curr.getLoser().getPlayer(0)->getGameNumTwo() * 2 + curr.getLoser().getPlayer(0)->getGameNumThree() * 3;
            losingPGasts = curr.getLoser().getPlayer(0)->getGameNumAssist();
            losingPGrebs = curr.getLoser().getPlayer(0)->getGameNumRebounds();
            losingPGstls = curr.getLoser().getPlayer(0)->getGameNumSteals();
            losingPGblks = curr.getLoser().getPlayer(0)->getGameNumBlocks();
            losingSGpts = curr.getLoser().getPlayer(1)->getGameNumTwo() * 2 + curr.getLoser().getPlayer(1)->getGameNumThree() * 3;
            losingSGasts = curr.getLoser().getPlayer(1)->getGameNumAssist();
            losingSGrebs = curr.getLoser().getPlayer(1)->getGameNumRebounds();
            losingSGstls = curr.getLoser().getPlayer(1)->getGameNumSteals();
            losingSGblks = curr.getLoser().getPlayer(1)->getGameNumBlocks();
            losingSFpts = curr.getLoser().getPlayer(2)->getGameNumTwo() * 2 + curr.getLoser().getPlayer(2)->getGameNumThree() * 3;
            losingSFasts = curr.getLoser().getPlayer(2)->getGameNumAssist();
            losingSFrebs = curr.getLoser().getPlayer(2)->getGameNumRebounds();
            losingSFstls = curr.getLoser().getPlayer(2)->getGameNumSteals();
            losingSFblks = curr.getLoser().getPlayer(2)->getGameNumBlocks();
            losingPFpts = curr.getLoser().getPlayer(3)->getGameNumTwo() * 2 + curr.getLoser().getPlayer(3)->getGameNumThree() * 3;
            losingPFasts = curr.getLoser().getPlayer(3)->getGameNumAssist();
            losingPFrebs = curr.getLoser().getPlayer(3)->getGameNumRebounds();
            losingPFstls = curr.getLoser().getPlayer(3)->getGameNumSteals();
            losingPFblks = curr.getLoser().getPlayer(3)->getGameNumBlocks();
            losingCpts = curr.getLoser().getPlayer(4)->getGameNumTwo() * 2 + curr.getLoser().getPlayer(0)->getGameNumThree() * 3;
            losingCasts = curr.getLoser().getPlayer(4)->getGameNumAssist();
            losingCrebs = curr.getLoser().getPlayer(4)->getGameNumRebounds();
            losingCstls = curr.getLoser().getPlayer(4)->getGameNumSteals();
            losingCblks = curr.getLoser().getPlayer(4)->getGameNumBlocks();
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
        if(boxScoreVisible)
        {
            window.draw(spriteBoxScore);
            //drawing box score
            window.draw(boxScoreText);
            boxScoreText.setString("BOX SCORE");
            boxScoreText.setPosition(750, 100);
            boxScoreText.setCharacterSize(100);
            window.draw(boxScoreText); //draw title
            boxScoreText.setCharacterSize(50);
            boxScoreText.setString(winningTeamName);
            boxScoreText.setPosition(420, 250);
            window.draw(boxScoreText); //draw winner
            boxScoreText.setString(losingTeamName);
            boxScoreText.setPosition(1200, 250);
            window.draw(boxScoreText); //draw loser
            boxScoreText.setString(std::to_string(winningTeamScore));
            boxScoreText.setPosition(460, 300);
            window.draw(boxScoreText); //draw winning score
            boxScoreText.setString(std::to_string(losingTeamScore));
            boxScoreText.setPosition(1240, 300);
            window.draw(boxScoreText); //draw losing score
            boxScoreText.setCharacterSize(25);
            boxScoreText.setString(winningPGName);
            boxScoreText.setPosition(350, 400);
            window.draw(boxScoreText); //draw PG name on winning team
            boxScoreText.setString(winningSGName);
            boxScoreText.setPosition(350, 480);
            window.draw(boxScoreText); //draw SG name on winning team
            boxScoreText.setString(winningSFName);
            boxScoreText.setPosition(350, 560);
            window.draw(boxScoreText); //draw SF name on winning team
            boxScoreText.setString(winningPFName);
            boxScoreText.setPosition(350, 640);
            window.draw(boxScoreText); //draw PF name on winning team
            boxScoreText.setString(winningCName);
            boxScoreText.setPosition(350, 720);
            window.draw(boxScoreText); //draw C name on winning team
            boxScoreText.setString(losingPGName);
            boxScoreText.setPosition(1000, 400);
            window.draw(boxScoreText); //draw PG name on losing team
            boxScoreText.setString(losingSGName);
            boxScoreText.setPosition(1000, 480);
            window.draw(boxScoreText); //draw SG name on losing team
            boxScoreText.setString(losingSFName);
            boxScoreText.setPosition(1000, 560);
            window.draw(boxScoreText); //draw SF name on losing team
            boxScoreText.setString(losingPFName);
            boxScoreText.setPosition(1000, 640);
            window.draw(boxScoreText); //draw PF name on losing team
            boxScoreText.setString(losingCName);
            boxScoreText.setPosition(1000, 720);
            window.draw(boxScoreText); //draw C name on losing team
            boxScoreText.setString(std::to_string(
                    winningPGpts) +
                                   " pts, " + std::to_string(winningPGasts) + " asts, " +
                                   std::to_string(winningPGrebs) + " rebs, " +
                                   std::to_string(winningPGstls) + " stls, " +
                                   std::to_string(winningPGblks) + " blks");
            boxScoreText.setPosition(350, 440);
            window.draw(boxScoreText); //draw PG stats on winning team
            boxScoreText.setString(std::to_string(
                    winningSGpts) +
                                   " pts, " + std::to_string(winningSGasts) + " asts, " +
                                   std::to_string(winningSGrebs) + " rebs, " +
                                   std::to_string(winningSGstls) + " stls, " +
                                   std::to_string(winningSGblks) + " blks");
            boxScoreText.setPosition(350, 520);
            window.draw(boxScoreText); //draw SG stats on winning team
            boxScoreText.setString(std::to_string(
                    winningSFpts) +
                                   " pts, " + std::to_string(winningSFasts) + " asts, " +
                                   std::to_string(winningSFrebs) + " rebs, " +
                                   std::to_string(winningSFstls) + " stls, " +
                                   std::to_string(winningSFblks) + " blks");
            boxScoreText.setPosition(350, 600);
            window.draw(boxScoreText); //draw SF stats on winning team
            boxScoreText.setString(std::to_string(
                    winningPFpts) +
                                   " pts, " + std::to_string(winningPFasts) + " asts, " +
                                   std::to_string(winningPFrebs) + " rebs, " +
                                   std::to_string(winningPFstls) + " stls, " +
                                   std::to_string(winningPFblks) + " blks");
            boxScoreText.setPosition(350, 680);
            window.draw(boxScoreText); //draw PF stats on winning team
            boxScoreText.setString(std::to_string(
                    winningCpts) +
                                   " pts, " + std::to_string(winningCasts) + " asts, " +
                                   std::to_string(winningCrebs) + " rebs, " +
                                   std::to_string(winningCstls) + " stls, " +
                                   std::to_string(winningCblks) + " blks");
            boxScoreText.setPosition(350, 760);
            window.draw(boxScoreText); //draw C stats on winning team
            boxScoreText.setString(std::to_string(
                    losingPGpts) +
                                   " pts, " + std::to_string(losingPGasts) + " asts, " +
                                   std::to_string(losingPGrebs) + " rebs, " +
                                   std::to_string(losingPGstls) + " stls, " +
                                   std::to_string(losingPGblks) + " blks");
            boxScoreText.setPosition(1000, 440);
            window.draw(boxScoreText); //draw PG stats on losing team
            boxScoreText.setString(std::to_string(
                    losingSGpts) +
                                   " pts, " + std::to_string(losingSGasts) + " asts, " +
                                   std::to_string(losingSGrebs) + " rebs, " +
                                   std::to_string(losingSGstls) + " stls, " +
                                   std::to_string(losingSGblks) + " blks");
            boxScoreText.setPosition(1000, 520);
            window.draw(boxScoreText); //draw SG stats on losing team
            boxScoreText.setString(std::to_string(
                    losingSFpts) +
                                   " pts, " + std::to_string(losingSFasts) + " asts, " +
                                   std::to_string(losingSFpts) + " rebs, " +
                                   std::to_string(losingSFstls) + " stls, " +
                                   std::to_string(losingSFblks) + " blks");
            boxScoreText.setPosition(1000, 600);
            window.draw(boxScoreText); //draw SF stats on losing team
            boxScoreText.setString(std::to_string(
                    losingPFpts) +
                                   " pts, " + std::to_string(losingPFasts) + " asts, " +
                                   std::to_string(losingPFrebs) + " rebs, " +
                                   std::to_string(losingPFstls) + " stls, " +
                                   std::to_string(losingPFblks) + " blks");
            boxScoreText.setPosition(1000, 680);
            window.draw(boxScoreText); //draw PF stats on losing team
            boxScoreText.setString(std::to_string(
                    losingCpts) +
                                   " pts, " + std::to_string(losingCasts) + " asts, " +
                                   std::to_string(losingCrebs) + " rebs, " +
                                   std::to_string(losingCstls) + " stls, " +
                                   std::to_string(losingCblks) + " blks");
            boxScoreText.setPosition(1000, 760);
            window.draw(boxScoreText); //draw C stats on losing team
        }

        window.display();
    }
    myfile.close();
    return 0;
}