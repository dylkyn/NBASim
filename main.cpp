#include <iostream>

void gameSimulation(Team offense, Team defense)
{
    bool assist = false;
    Player offender = offense.getPlayer();
    Player assister = offense.getPlayer();
    Player defender = defense.getPlayer()
    while(offender.position == assist.position)
    {
        assist = offense.getPlayer(); //This while loop makes sure that two different players are selected
    }
    srand (time(NULL));
//	v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014

    int pass = rand() % offender.getPass() + 1;
    int shoot = rand() % offender.getShoot() + 1;

    if (pass >= shoot)
    {
        assist = true;
        swap(offender, assister); //https://www.cplusplus.com/reference/algorithm/swap/ need to include <algorithms>
    }

    int twoPoint = rand() % offender.getTwoPoint() + 1;
    int threePoint = rand() % offender.getThreePoint() + 1;

    if (twoPoint >= threePoint)
    {
        int block = rand() % defender.getBlock() + 1;
        int rebound = rand() % defender.getRebound() + 1;
        if(block >= rebound)
        {
            twoPoint = rand() % offender.getTwoPoint() + 1; //This is ran for a second time due to the bias that would be created from it winning against the three point in the first time. This will be same logic for block being re-ran.

            block = rand() % defender.getBlock() + 1;

            if (block <= twoPoint)
            {
                offense.setScore(offense.getScore + 2); //I do not know how we are doing and setting up the game but this is lowkey pseudocode here
                offender.setNumTwo(offender.getNumTwo + 1);
                if (assist)
                {
                    assister.setNumAssist(assister.getAssist + 1); //this is just updating how many assists the player has. We can also do this by updating something within the Game file where its like the number of assists the player pos has
                }
            }
            else
            {
                defender.setNumBlocks(defender.getNumBlocks() + 1);
            }
        }
        else
        {
            twoPoint = rand() % offender.getTwoPoint() + 1; //This is ran for a second time due to the bias that would be created from it winning against the three point in the first time. This will be same logic for block being re-ran.

            rebound = rand() % defender.getBlock() + 1;

            if (rebound <= twoPoint)
            {
                offense.setScore(offense.getScore + 2); //I do not know how we are doing and setting up the game but this is lowkey pseudocode here
                offender.setNumTwo(offender.getNumTwo + 1);
                if (assist)
                {
                    assister.setNumAssist(assister.getAssist + 1); //this is just updating how many assists the player has. We can also do this by updating something within the Game file where its like the number of assists the player pos has
                }
            }
            else
            {
                defender.setNumRebounds(defender.getNumRebounds() + 1);
            }
        }
    }
    else
    {
        int perimeterD = rand() % defender.getPerimeterDefense() + 1;
        threePoint = rand() % offender.getThreePoint() + 1;

        if (threePoint >= perimeterD)
        {
            offense.setScore(offense.getScore + 3); //I do not know how we are doing and setting up the game but this is lowkey pseudocode here
            offender.setNumThree(offender.getNumThree + 1);
            if (assist)
            {
                assister.setNumAssist(assister.getAssist + 1); //this is just updating how many assists the player has. We can also do this by updating something within the Game file where its like the number of assists the player pos has
            }
        }
        else
        {
            defender.setNumSteals(defender.getNumSteals() + 1);

        }
    }
}

int main()
{
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
