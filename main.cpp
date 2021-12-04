#include <iostream>
#include "Player.h"
#include "Team.h"
#include "Game.h"
#include <algorithm>
#include <string>

int main()
{
    Team hawks("Hawks");
    Team thunder("Thunder");
    Game game1(hawks, thunder);
    Player test(1);
    game1.fullGameSimulation();
    std::cout << "Winner is: " << game1.getWinner().getName() << std::endl;
	return 0;
//    std::cout << "hello world";
}
