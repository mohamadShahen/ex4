//
// Created by Tamer Khalifa on 29/11/2022.
//

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H
#define DEFAULT_MAX_HP 100
#define STARTING_LEVEL 1
#define DEFAULT_FORCE 5
#define MAX_LEVEL 10


#include <string.h>
#include "utilities.h"

class Player{
    char *m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_hp;
    int m_coins;

public:
    Player(const char *name, int maxHP = DEFAULT_MAX_HP, int force = DEFAULT_FORCE);
    Player(const Player&);
    ~Player();
    void printInfo() const;
    void levelUp();
    int getLevel() const;
    void buff(int value);
    void heal (int value);
    void damage (int value);
    bool isKnockedOut() const;
    void addCoins(int value);
    bool pay(int value);
    int getAttackStrength() const;

};

#endif //EX2_PLAYER_H
