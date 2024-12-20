#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <random>
#include <ctime>
#include "Player.h"

Player::Player()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 9); // Random number from 0-9

    id[0] = dis(gen);
    for (int i = 0; i < 8; ++i)
    {
        id[1] = id[1] * 10 + dis(gen); // Random eight digit number
    }

    // Generate random token that is 40 characters Aa-Zz and 0-9
    const std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::uniform_int_distribution<> char_dis(0, charset.size() - 1);

    for (int i = 0; i < 40; ++i)
    {
        token += charset[char_dis(gen)];
    }
}
