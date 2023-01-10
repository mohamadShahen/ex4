
#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

const int DEFAULT_FORCE = 5;
const int FIRST_LEVEL = 1;
const int STARTING_COINS = 10;
const int LAST_LEVEL = 10;


#include "utilities.h"
#include "HealthPoints.h"

class Player{
protected:
    std::string m_name;
    int m_level = FIRST_LEVEL;
    int m_force = DEFAULT_FORCE;
    int m_coins = STARTING_COINS;
    HealthPoints m_HP = HealthPoints();

public:
    Player (const std::string&);
    Player(const Player&) = default;
    ~Player() = default;
    Player& operator=(const Player&) = default;
    void levelUp();
    int getLevel() const;
    void buff(const int);
    void weaken(const int);
    virtual void heal (const int);
    void damage (const int);
    bool isKnockedOut() const;
    virtual void addCoins(const int);
    bool pay(const int);
    virtual int getAttackStrength() const;
};

#endif //EX2_PLAYER_H
