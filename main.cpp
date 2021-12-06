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
    textureBackground.loadFromFile("graphics/background.png"); //FIX THIS TO OUR FILE

    // Create a sprite
    Sprite spriteBackground;

    // Attach the texture to the sprite
    spriteBackground.setTexture(textureBackground);

    // Set the spriteBackground to cover the screen
    spriteBackground.setPosition(0, 0);

    //create vector of teams
    std::vector<Team> teams;
    Team hawks("Hawks", "graphics/hawks.png");
    Texture textureHawks;
    textureHawks.loadFromFile(hawks.getLogo());
    Sprite spriteHawks;
    spriteHawks.setTexture(textureHawks);
    teams.push_back(hawks);

    Team thunder("Thunder", "graphics/thunder.png");
    Texture textureThunder;
    textureThunder.loadFromFile(thunder.getLogo());
    Sprite spriteThunder;
    spriteThunder.setTexture(textureThunder);
    teams.push_back(thunder);

    Team celtics("Celtics", "graphics/celtics.png");
    Texture textureCeltics;
    textureCeltics.loadFromFile(celtics.getLogo());
    Sprite spriteCeltics;
    spriteCeltics.setTexture(textureCeltics);
    teams.push_back(celtics);

    Team nets("Nets", "graphics/nets.png");
    Texture textureNets;
    textureNets.loadFromFile(nets.getLogo());
    Sprite spriteNets;
    spriteNets.setTexture(textureNets);
    teams.push_back(nets);

    Team hornets("Hornets", "graphics/hornets.png");
    Texture textureHornets;
    textureHornets.loadFromFile(hornets.getLogo());
    Sprite spriteHornets;
    spriteHornets.setTexture(textureHornets);
    teams.push_back(hornets);

    Team bulls("Bulls", "graphics/bulls.png");
    Texture textureBulls;
    textureBulls.loadFromFile(bulls.getLogo());
    Sprite spriteBulls;
    spriteBulls.setTexture(textureBulls);
    teams.push_back(bulls);

    Team cavaliers("Cavaliers", "graphics/cavaliers.png");
    Texture textureCavs;
    textureCavs.loadFromFile(cavaliers.getLogo());
    Sprite spriteCavs;
    spriteCavs.setTexture(textureCavs);
    teams.push_back(cavaliers);
    Team mavericks("Mavericks", "graphics/mavericks.png");
    Texture textureMavericks;
    textureMavericks.loadFromFile(mavericks.getLogo());
    Sprite spriteMavericks;
    spriteMavericks.setTexture(textureMavericks);
    teams.push_back(mavericks);

    Team nuggets("Nuggets", "graphics/nuggets.png");
    Texture textureNuggets;
    textureNuggets.loadFromFile(nuggets.getLogo());
    Sprite spriteNuggets;
    spriteNuggets.setTexture(textureNuggets);
    teams.push_back(nuggets);

    Team pistons("Pistons", "graphics/pistons.png");
    Texture texturePistons;
    texturePistons.loadFromFile(pistons.getLogo());
    Sprite spritePistons;
    spritePistons.setTexture(texturePistons);
    teams.push_back(pistons);

    Team warriors("Warriors", "graphics/warriors.png");
    Texture textureWarriors;
    textureThunder.loadFromFile(warriors.getLogo());
    Sprite spriteThunder;
    spriteThunder.setTexture(textureThunder);
    teams.push_back(thunder);

    Team rockets("Rockets", "graphics/rockets.png");
    Team pacers("Pacers", "graphics/pacers.png");
    Team lakers("Lakers", "graphics/lakers.png");
    Team grizzlies("Grizzlies", "graphics/grizzlies.png");
    Team bucks("Bucks", "graphics/bucks.png");
    Team timberwolves("Timberwolves", "graphics/timberwolves.png");
    Team pelicans("Pelicans", "graphics/pelicans.png");
    Team knicks("Knicks", "graphics/knicks.png");
    Team magic("Magic", "graphics/magic.png");
    Team the76ers("76ers", "graphics/76ers.png");
    Team suns("Suns", "graphics/suns.png");
    Team blazers("Blazers", "graphics/blazers.png");
    Team spurs("Spurs", "graphics/spurs.png");
    Team raptors("Raptors", "graphics/raptors.png");
    Team jazz("Jazz", "graphics/jazz.png");
    Team heat("Heat", "graphics/heat.png");
    Team wizards("Wizards", "graphics/wizards.png");
    Team clippers("Clippers", "graphics/clippers.png");
    Team kings("Kings", "graphics/kings.png");
    Team buzz("Buzz", "graphics/buzz.png");
    Team wreck("Ramblin' Wreck", "graphics/wreck.png");

    Game game1(hawks, thunder);
    Game game2(heat, lakers);
    Game game3(wizards, nets);
    Game game4(clippers,kings);

    std::cout << hawks.getGameScore() << " " << thunder.getGameScore() << std::endl;
    Player test(1);
    std::cout << test.getName() << std::endl;
    game1.fullGameSimulation();
    game2.fullGameSimulation();
    game3.fullGameSimulation();
    game4.fullGameSimulation();
    std::cout << "Winner is: " << game1.getWinner().getName() << " the score was " << game1.getWinner().getGameScore() << " and " << game1.getLoser().getGameScore() << std::endl;
    std::cout << "Winner is: " << game2.getWinner().getName() << " the score was " << game2.getWinner().getGameScore() << " and " << game2.getLoser().getGameScore() << std::endl;
    std::cout << "Winner is: " << game3.getWinner().getName() << " the score was " << game3.getWinner().getGameScore() << " and " << game3.getLoser().getGameScore() << std::endl;
    std::cout << "Winner is: " << game4.getWinner().getName() << " the score was " << game4.getWinner().getGameScore() << " and " << game4.getLoser().getGameScore() << std::endl;

    Game game5(game1.getWinner(), game2.getWinner());
    Game game6(game3.getWinner(), game4.getWinner());
    game5.fullGameSimulation();
    game6.fullGameSimulation();
    std::cout << "Winner is: " << game5.getWinner().getName() << " the score was " << game5.getWinner().getGameScore() << " and " << game5.getLoser().getGameScore() << std::endl;
    std::cout << "Winner is: " << game6.getWinner().getName() << " the score was " << game6.getWinner().getGameScore() << " and " << game6.getLoser().getGameScore() << std::endl;

    Game game7(game5.getWinner(), game6.getWinner());
    game7.fullGameSimulation();
    std::cout << "Winner is: " << game7.getWinner().getName() << " the score was " << game7.getWinner().getGameScore() << " and " << game7.getLoser().getGameScore() << std::endl;




    return 0;
}
