
#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "Battle.h"

const int DRAGON_FORCE = 25;
const int DRAGON_LOOT = 1000;
const int DRAGON_DAMAGE = 100;

class Dragon : public Battle{
public:
    Dragon();
    ~Dragon() = default;
    void applyEncounter(Player& player) const override;
    const std::string& getType() const override;
};

#endif //EX4_DRAGON_H
