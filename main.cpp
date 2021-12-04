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
    Game game1(hawks, thunder);
    std::cout << hawks.getGameScore() << " " << thunder.getGameScore() << std::endl;
    Player test(1);
    std::cout << test.getName() << std::endl;
    game1.fullGameSimulation();
    std::cout << "Winner is: " << game1.getWinner().getName() << " the score was " << game1.getWinner().getGameScore() << " and " << game1.getLoser().getGameScore() << std::endl;

	return 0;
}
