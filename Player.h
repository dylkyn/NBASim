//
// Created by bella on 12/3/2021.
//

#ifndef NBASIM_PLAYER_H
#define NBASIM_PLAYER_H
#include <string>
class Player
{
private:
    int position; //what type of player? 1-5
    int block;
    int rebound;
    int interiorDefense;
    int perimeterDefense;
    int pass;
    int shoot;
    int threePointShot;
    int twoPointShot;

    //setting unique name
    std::string name;
    int pointGuardRange = 30;
    int shootingGuardRange = 30;
    int smallForwardRange = 30;
    int powerForwardRange = 30;
    int centerRange = 30;

    //player stats
    int numMissedTwo;
    int numMissedThree;
    int numTwo;
    int numThree;
    int numAssist;
    int numRebounds;
    int numSteals;
    int numBlocks;
public:
    Player(int playerType);
    Player();
    //getters and setters for attributes
    int getPosition();
    int getBlock();
    int getRebound();
    int getInteriorDefense();
    int getPerimeterDefense();
    int getPass();
    int getShoot();
    int getThreePointShot();
    int getTwoPointShot();

    //player totals
    void setNumMissedTwo(int newMissedTwo);
    void setNumMissedThree(int newMissedThree);
    void setNumTwo(int newNumTwo);
    void setNumThree(int newNumThree);
    void setNumAssist(int newNumAssist);
    void setNumRebounds(int newNumRebounds);
    void setNumSteals(int newNumSteals);
    void setNumBlocks(int newNumBlocks);
    int getNumMissedThree();
    std::string getName();
    int getNumMissedTwo();
    int getNumThree();
    int getNumTwo();
    int getNumAssist();
    int getNumRebounds();
    int getNumSteals();
    int getNumBlocks();

    //string array of names
    static inline std::string pointGuardNames[32] = {
        "Trae Young",
        "Jose Alvarado",
        "Stephen Curry",
        "LaMelo Ball",
        "Luka Doncic",
        "Damian Lillard",
        "Kyrie Irving",
        "Jeremy Lin",
        "Chris Paul",
        "Ja Morant",
        "Lonzo Ball",
        "Rajon Rondo",
        "Derrick Rose",
        "Ricky Rubio",
        "D'Angelo Russell",
        "Collin Sexton",
        "Ben Simmons",
        "Patrick Beverley",
        "Cade Cunningham",
        "De'Aaron Fox",
        "Shai Gilgeous-Alexander",
        "Jrue Holiday",
        "Kyle Lowry",
        "Jamal Murray",
        "Dennis Schroder",
        "John Wall",
        "Russell Westbrook",
        "Markelle Fultz",
        "Avery Bradley",
        "Jordan Clarkson",
        "Fred Vanfleet",
        "Mike Conley"
    };
    static inline std::string shootingGuardNames[32] = {
        "Bradley Beal",
        "James Harden",
        "Devin Booker",
        "Jaylen Brown",
        "RJ Barrett",
        "Alex Caruso",
        "Donte DiVincenzo",
        "Evan Fournier",
        "Jalen Green",
        "Buddy Hield",
        "Talen Horton-Tucker",
        "Kevin Huerter",
        "Joe Ingles",
        "Victor Oladipo",
        "Immanuel Quickley",
        "Josh Richardson",
        "Rodney Hood",
        "Gary Harris",
        "Josh Giddey",
        "Donovan Mitchell",
        "Austin Rivers",
        "Terry Rozier",
        "Landry Shamet",
        "Klay Thompson",
        "Lou Williams",
        "Luke Kennard",
        "Zach Lavine",
        "Caris LeVert",
        "Jalen Suggs",
        "Gary Trent Jr.",
        "CJ McCollum",
        "Jordan Poole"
    };
    static inline std::string smallForwardNames[32] = {
        "Lebron James",
        "Paul George",
        "Khris Middleton",
        "Jimmy Butler",
        "Demar Derozan",
        "OG Anunoby",
        "Trevor Ariza",
        "Anthony Edwards",
        "Rudy Gay",
        "Gordon Hayward",
        "Andre Iguodala",
        "Brandon Ingram",
        "Kawhi Leonard",
        "Josh Okogie",
        "Eric Paschall",
        "Isaac Okoro",
        "Jayson Tatum",
        "Yuta Watanabe",
        "Tony Snell",
        "Norman Powell",
        "Otto Porter Jr.",
        "Bruno Fernando",
        "Danny Green",
        "Dillon Brooks",
        "Miles Bridges",
        "Kent Bazemore",
        "Bojan Bogdanovic",
        "Tyler Cook",
        "Lugentz Dort",
        "Thanasis Antetokounmpo",
        "Kelly Oubre",
        "Dorian Finney-Smith"
    };
    static inline std::string powerForwardNames[32] = {
        "Giannis Antetokounmpo",
        "Blake Griffin",
        "Carmelo Anthony",
        "Nicholas Batum",
        "Anthony Davis",
        "Kevin Durant",
        "Jae Crowder",
        "Robert Covington",
        "Marvin Bagley III",
        "Jeff Green",
        "Rui Hachimura",
        "Jalen Mcdaniels",
        "Jaden Mcdaniels",
        "Kevin Love",
        "Paul Millsap",
        "Jabari Parker",
        "Julius Randle",
        "P.J. Tucker",
        "Jared Vanderbilt",
        "Zion Williamson",
        "Thaddeus Young",
        "Kelly Olynyk",
        "Udonis Haslem",
        "Tobias Harris",
        "John Collins",
        "Darius Bazley",
        "Nemanja Bjelica",
        "Draymond Green",
        "Aaron Gordon",
        "Isaiah Jackson",
        "Larry Nance",
        "Marcus Morris"
    };
    static inline std::string centerNames[32] = {
        "Steven Adams",
        "Bam Adebayo",
        "Lamarcus Aldridge",
        "Jarrett Allen",
        "Deandre Ayton",
        "Mo Bamba",
        "Bol Bol",
        "Moses Brown",
        "Clint Capela",
        "Demarcus Cousins",
        "Cody Zeller",
        "Nikola Vucevic",
        "Myles Turner",
        "Mitchell Robinson",
        "Dwight Powell",
        "Jakob Poetl",
        "Evan Mobley",
        "JaVale Mcgee",
        "Al Horford",
        "Serge Ibaka",
        "DeAndre Jordan",
        "Derrick Favors",
        "Tacko Fall",
        "Andre Drummond",
        "Kevon Looney",
        "Robin Lopez",
        "Brook Lopez",
        "Evan Mobley",
        "Nerlens Noel",
        "Jusuf Nurkic",
        "Hassan Whiteside",
        "Dwight Howard"
    };
};
#endif //NBASIM_PLAYER_H
