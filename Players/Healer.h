
#ifndef PLAYER_CPP_HEALER_H
#define PLAYER_CPP_HEALER_H

#include "Player.h"

class Healer : public Player{
public:
    explicit Healer(const std::string&);
    Healer(const Healer&) = default;
    Healer& operator=(const Healer&) = default;
    virtual ~Healer() = default;
    void heal(const int&) override;
    const std::string& getType() const override;
};

#endif //PLAYER_CPP_HEALER_H
