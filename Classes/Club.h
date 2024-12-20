#ifndef CLUB_H
#define CLUB_H

#include <iostream>
#include <vector>
#include <map>

class Club
{
public:
    int id[2] = {0, 1};
    std::string name;
    std::map<std::string, std::map<std::string, int>> members;
    std::string description;
    int badge;
    int region;
    int type;
    int trophiesRequired;
    bool familyFriendly;
    std::vector<std::string> chat;
};

#endif