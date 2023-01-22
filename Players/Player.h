
#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include "../tool/HealthPoints.h"
#include <memory>

const int DEFAULT_FORCE = 5;
const int FIRST_LEVEL = 1;
const int STARTING_COINS = 10;
const int LAST_LEVEL = 10;
const std::string NINJA = "Ninja";
const std::string HEALER = "Healer";
const std::string WARRIOR = "Warrior";

class Player{
protected:
    std::string m_name;
    int m_level;
    int m_force;
    int m_coins;
    HealthPoints m_HP;

public:
    Player (const std::string&);
    Player (const Player&) = default;
    ~Player () = default;
    Player& operator= (const Player&) = default;
    void levelUp ();
    const int& getLevel () const;
    const int& getCoins () const;
    const std::string& getName () const;
    virtual int getAttackStrength () const;
    virtual const std::string& getType () const = 0;
    void buff (const int&);
    void weaken (const int&);
    virtual void heal (const int&);
    void damage (const int&);
    virtual void addCoins (const int&);
    bool pay (const int&);
    bool isKnockedOut() const;
    friend std::ostream& operator<<(std::ostream& os, const Player& player);

};

#endif //EX2_PLAYER_H
