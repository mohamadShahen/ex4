//
// Created by Tamer Khalifa on 29/11/2022.
//

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

const int DEFAULT_FORCE = 5;
const int FIRST_LEVEL = 1;
const int STARTING_COINS = 10;
const int LAST_LEVEL = 10;


#include <string.h>
#include "utilities.h"
#include "HealthPoints.h"

class Player{
protected:
    char* m_name;
    int m_level = FIRST_LEVEL;
    int m_force = DEFAULT_FORCE;
    int m_coins = STARTING_COINS;
    HealthPoints m_HP = HealthPoints();

public:
    Player (const char*);
    Player(const Player&);
    ~Player();
    Player& operator=(const Player&) = default;
    void levelUp();
    int getLevel() const;
    void buff(int);
    virtual void heal (int);
    void damage (int);
    bool isKnockedOut() const;
    virtual void addCoins(int);
    bool pay(int);
    virtual int getAttackStrength() const;
};

class Warrior : public Player{
public:
    Warrior(const char*);
    Warrior(const Warrior&);
    Warrior& operator=(const Warrior&) = default;
    ~Warrior() = default;
    int getAttackStrength() const override;
};

class Ninja : public Player{
public:
    Ninja(const char*);
    Ninja(const Ninja&);
    Ninja& operator=(const Ninja&) = default;
    ~Ninja() = default;
    void addCoins(int) override;
};

class Healer : public Player{
public:
    Healer(const char*);
    Healer(const Healer&);
    Healer& operator=(const Healer&) = default;
    ~Healer() = default;
    void heal(int) override;
};
#endif //EX2_PLAYER_H
