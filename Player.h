
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

class Warrior : public Player{
public:
    Warrior(const std::string&);
    Warrior(const Warrior&);
    Warrior& operator=(const Warrior&) = default;
    ~Warrior() = default;
    int getAttackStrength() const override;
};

class Ninja : public Player{
public:
    Ninja(const std::string&);
    Ninja(const Ninja&);
    Ninja& operator=(const Ninja&) = default;
    ~Ninja() = default;
    void addCoins(const int) override;
};

class Healer : public Player{
public:
    Healer(const std::string&);
    Healer(const Healer&);
    Healer& operator=(const Healer&) = default;
    ~Healer() = default;
    void heal(const int) override;
};
#endif //EX2_PLAYER_H
