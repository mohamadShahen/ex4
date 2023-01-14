
#ifndef PLAYER_CPP_NINJA_H
#define PLAYER_CPP_NINJA_H

#include "Player.h"

class Ninja : public Player{
public:
    Ninja(const std::string&);
    Ninja(const Ninja&);
    Ninja& operator=(const Ninja&) = default;
    ~Ninja() = default;
    void addCoins(const int) override;
    std::string getType() const override;
};

#endif //PLAYER_CPP_NINJA_H
