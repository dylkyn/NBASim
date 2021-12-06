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
    textureWarriors.loadFromFile(warriors.getLogo());
    Sprite spriteWarriors;
    spriteWarriors.setTexture(textureWarriors);
    teams.push_back(warriors);

    Team rockets("Rockets", "graphics/rockets.png");
    Texture textureRockets;
    textureRockets.loadFromFile(rockets.getLogo());
    Sprite spriteRockets;
    spriteRockets.setTexture(textureRockets);
    teams.push_back(rockets);

    Team pacers("Pacers", "graphics/pacers.png");
    Texture texturePacers;
    texturePacers.loadFromFile(pacers.getLogo());
    Sprite spritePacers;
    spritePacers.setTexture(texturePacers);
    teams.push_back(pacers);

    Team lakers("Lakers", "graphics/lakers.png");
    Texture textureLakers;
    textureLakers.loadFromFile(lakers.getLogo());
    Sprite spriteLakers;
    spriteLakers.setTexture(textureLakers);
    teams.push_back(lakers);

    Team grizzlies("Grizzlies", "graphics/grizzlies.png");
    Texture textureGrizzlies;
    textureGrizzlies.loadFromFile(grizzlies.getLogo());
    Sprite spriteGrizzlies;
    spriteGrizzlies.setTexture(textureGrizzlies);
    teams.push_back(grizzlies);

    Team bucks("Bucks", "graphics/bucks.png");
    Texture textureBucks;
    textureBucks.loadFromFile(bucks.getLogo());
    Sprite spriteBucks;
    spriteBucks.setTexture(textureBucks);
    teams.push_back(bucks);

    Team timberwolves("Timberwolves", "graphics/timberwolves.png");
    Texture textureTimberwolves;
    textureTimberwolves.loadFromFile(timberwolves.getLogo());
    Sprite spriteTimberwolves;
    spriteTimberwolves.setTexture(textureTimberwolves);
    teams.push_back(timberwolves);

    Team pelicans("Pelicans", "graphics/pelicans.png");
    Texture texturePelicans;
    texturePelicans.loadFromFile(pelicans.getLogo());
    Sprite spritePelicans;
    spritePelicans.setTexture(texturePelicans);
    teams.push_back(pelicans);

    Team knicks("Knicks", "graphics/knicks.png");
    Texture textureKnicks;
    textureKnicks.loadFromFile(knicks.getLogo());
    Sprite spriteKnicks;
    spriteKnicks.setTexture(textureKnicks);
    teams.push_back(knicks);

    Team magic("Magic", "graphics/magic.png");
    Texture textureMagic;
    textureMagic.loadFromFile(magic.getLogo());
    Sprite spriteMagic;
    spriteMagic.setTexture(textureMagic);
    teams.push_back(magic);

    Team the76ers("76ers", "graphics/76ers.png");
    Texture texture76ers;
    texture76ers.loadFromFile(the76ers.getLogo());
    Sprite sprite76ers;
    sprite76ers.setTexture(texture76ers);
    teams.push_back(the76ers);

    Team suns("Suns", "graphics/suns.png");
    Texture textureSuns;
    textureSuns.loadFromFile(suns.getLogo());
    Sprite spriteSuns;
    spriteSuns.setTexture(textureSuns);
    teams.push_back(suns);

    Team blazers("Blazers", "graphics/blazers.png");
    Texture textureBlazers;
    textureBlazers.loadFromFile(blazers.getLogo());
    Sprite spriteBlazers;
    spriteBlazers.setTexture(textureBlazers);
    teams.push_back(blazers);

    Team spurs("Spurs", "graphics/spurs.png");
    Texture textureSpurs;
    textureSpurs.loadFromFile(spurs.getLogo());
    Sprite spriteSpurs;
    spriteSpurs.setTexture(textureSpurs);
    teams.push_back(spurs);

    Team raptors("Raptors", "graphics/raptors.png");
    Texture textureRaptors;
    textureRaptors.loadFromFile(raptors.getLogo());
    Sprite spriteRaptors;
    spriteRaptors.setTexture(textureRaptors);
    teams.push_back(raptors);

    Team jazz("Jazz", "graphics/jazz.png");
    Texture textureJazz;
    textureJazz.loadFromFile(jazz.getLogo());
    Sprite spriteJazz;
    spriteJazz.setTexture(textureJazz);
    teams.push_back(jazz);

    Team heat("Heat", "graphics/heat.png");
    Texture textureHeat;
    textureHeat.loadFromFile(heat.getLogo());
    Sprite spriteHeat;
    spriteHeat.setTexture(textureHeat);
    teams.push_back(heat);

    Team wizards("Wizards", "graphics/wizards.png");
    Texture textureWizards;
    textureWizards.loadFromFile(wizards.getLogo());
    Sprite spriteWizards;
    spriteWizards.setTexture(textureWizards);
    teams.push_back(wizards);

    Team clippers("Clippers", "graphics/clippers.png");
    Texture textureClippers;
    textureClippers.loadFromFile(clippers.getLogo());
    Sprite spriteClippers;
    spriteClippers.setTexture(textureClippers);
    teams.push_back(clippers);

    Team kings("Kings", "graphics/kings.png");
    Texture textureKings;
    textureKings.loadFromFile(kings.getLogo());
    Sprite spriteKings;
    spriteKings.setTexture(textureKings);
    teams.push_back(kings);

    Team buzz("Buzz", "graphics/buzz.png");
    Texture textureBuzz;
    textureBuzz.loadFromFile(buzz.getLogo());
    Sprite spriteBuzz;
    spriteBuzz.setTexture(textureBuzz);
    teams.push_back(buzz);

    Team wreck("Ramblin' Wreck", "graphics/wreck.png");
    Texture textureWreck;
    textureWreck.loadFromFile(wreck.getLogo());
    Sprite spriteWreck;
    spriteWreck.setTexture(textureWreck);
    teams.push_back(wreck);

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
