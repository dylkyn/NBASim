#include <iostream>
#include "Player.h"
#include "Team.h"
#include "Game.h"
#include <algorithm>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <chrono>
#include <random>

using namespace sf;

int main()
{
    srand(time(NULL));
    // Create a video mode object
    VideoMode vm(1920, 1080);

    // Create and open a window for the game
    RenderWindow window(vm, "NBA Simulation", Style::Close | Style::Titlebar);// , Style::Fullscreen);

    // Create a texture to hold a graphic on the GPU
    Texture textureBackground;

    // Load a graphic into the texture
    textureBackground.loadFromFile("../graphics/background.png"); //FIX THIS TO OUR FILE

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

    Team bulls("Bulls", "../graphics/bulls.png");
    teams.push_back(bulls);

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

    //randomly shuffle teams
    std::vector<Team> randomTeams;
    randomTeams = teams;
    // obtain a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::shuffle(randomTeams.begin(), randomTeams.end(), std::default_random_engine(seed));
    //place teams in columns
    std::vector<Team> columnOne;
    std::vector<Team> columnTwo;
    //first half of teams in column one
    for (int i = 0; i < 16; i++)
    {
        columnOne.push_back(randomTeams.at(i));
    }
    //second half of teams in column two
    for (int i = 4; i < 32; i++)
    {
        columnTwo.push_back(randomTeams.at(i));
    }
    for (unsigned i = 0; i < columnOne.size(); i++)
    {
        columnOne.at(i).getLogo().setPosition(100, 300 + 150 * i);
    }
    for (unsigned i = 0; i < columnTwo.size(); i++)
    {
        columnTwo.at(i).getLogo().setPosition(1750, 300 + 150 * i);
    }
//for (int i = 0; i < 16; i+=2)
    Game game1(columnOne.at(0), columnOne.at(1));
    Game game2(columnOne.at(2), columnOne.at(3));
    Game game3(columnOne.at(4), columnOne.at(5));
    Game game4(columnOne.at(6), columnOne.at(7));
    Game game5(columnOne.at(8), columnOne.at(9));
    Game game6(columnOne.at(10), columnOne.at(11));
    Game game7(columnOne.at(12), columnOne.at(13));
    Game game8(columnOne.at(14), columnOne.at(15));

    std::cout << hawks.getGameScore() << " " << thunder.getGameScore() << std::endl;
    Player test(1);
    std::cout << test.getName() << std::endl;
    game1.fullGameSimulation();
    game2.fullGameSimulation();
    game3.fullGameSimulation();
    game4.fullGameSimulation();
    std::cout << "Winner is: " << game1.getWinner().getName() << " the score was " << game1.getWinner().getGameScore()
              << " and " << game1.getLoser().getGameScore() << std::endl;
    std::cout << "Winner is: " << game2.getWinner().getName() << " the score was " << game2.getWinner().getGameScore()
              << " and " << game2.getLoser().getGameScore() << std::endl;
    std::cout << "Winner is: " << game3.getWinner().getName() << " the score was " << game3.getWinner().getGameScore()
              << " and " << game3.getLoser().getGameScore() << std::endl;
    std::cout << "Winner is: " << game4.getWinner().getName() << " the score was " << game4.getWinner().getGameScore()
              << " and " << game4.getLoser().getGameScore() << std::endl;

    Game gameA(game1.getWinner(), game2.getWinner());
    Game gameB(game3.getWinner(), game4.getWinner());
    gameA.fullGameSimulation();
    gameB.fullGameSimulation();
    std::cout << "Winner is: " << gameA.getWinner().getName() << " the score was " << gameA.getWinner().getGameScore()
              << " and " << gameA.getLoser().getGameScore() << std::endl;
    std::cout << "Winner is: " << gameB.getWinner().getName() << " the score was " << gameB.getWinner().getGameScore()
              << " and " << gameB.getLoser().getGameScore() << std::endl;

    Game gameC(gameA.getWinner(), gameB.getWinner());
    gameC.fullGameSimulation();
    std::cout << "Winner is: " << gameC.getWinner().getName() << " the score was " << gameC.getWinner().getGameScore()
              << " and " << gameC.getLoser().getGameScore() << std::endl;



    return 0;
}