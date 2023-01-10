
#ifndef PLAYER_CPP_WARRIOR_H
#define PLAYER_CPP_WARRIOR_H

#include "Player.h"

class Warrior : public Player{
public:
    Warrior(const std::string&);
    Warrior(const Warrior&);
    Warrior& operator=(const Warrior&) = default;
    ~Warrior() = default;
    int getAttackStrength() const override;
};

#endif //PLAYER_CPP_WARRIOR_H