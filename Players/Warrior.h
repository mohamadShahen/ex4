
#ifndef PLAYER_CPP_WARRIOR_H
#define PLAYER_CPP_WARRIOR_H

#include "Player.h"

class Warrior : public Player{
public:
    explicit Warrior(const std::string&);
    Warrior(const Warrior&) = default;
    Warrior& operator=(const Warrior&) = default;
    virtual ~Warrior() = default;
    int getAttackStrength() const override;
    const std::string& getType() const override;
};

#endif //PLAYER_CPP_WARRIOR_H
