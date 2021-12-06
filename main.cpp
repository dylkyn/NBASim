#include <iostream>
#include "Player.h"
#include "Team.h"
#include "Game.h"
#include <algorithm>
#include <string>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    Team hawks("Hawks");
    Team thunder("Thunder");
    Team heat("Heat");
    Team lakers("Lakers");
    Team wizards("Wizards");
    Team nets("Nets");
    Team clippers("Clippers");
    Team kings("Kings");
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
