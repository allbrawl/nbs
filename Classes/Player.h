#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <map>

struct Brawler
{
    int CardID;
    std::vector<int> Skins;
    int Trophies;
    int HighestTrophies;
    int PowerLevel;
    int PowerPoints;
    int State;

    Brawler(int cardID, std::vector<int> skins, int trophies, int highestTrophies,
            int powerLevel, int powerPoints, int state)
        : CardID(cardID), Skins(skins), Trophies(trophies), HighestTrophies(highestTrophies),
          PowerLevel(powerLevel), PowerPoints(powerPoints), State(state) {}
};

class Player
{
public:
    std::string ClientVersion = "1.0";
    int id[2] = {0, 1};
    std::vector<int> AllianceID = {0, 0};
    std::string token;
    std::string name = "NBS";
    bool registered = false;
    int nameColor, thumbnail, coins, gems, starpoints, trophies, highestTrophies, trophyRoadTier, xp, level, tokens, tokenDoublers;
    std::string region = "PL";
    std::string supportedCreator = "Natesworks";
    std::map<int, int> SelectedSkins;
    std::vector<int> selectedBrawlers;
    std::vector<std::string> randomiserSelectedSkins;
    std::vector<int> ownedPins;
    std::map<int, Brawler> OwnedBrawlers = {
        {0, Brawler( // Brawler ID
                0,   // CardID
                {},  // Skins
                0,   // Trophies
                0,   // HighestTrophies
                1,   // PowerLevel
                0,   // PowerPoints
                2    // State
                )}};
};


#endif