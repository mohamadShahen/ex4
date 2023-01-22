
#ifndef EX4_GREMLIN_H
#define EX4_GREMLIN_H

#include "Battle.h"

const int GREMLIN_FORCE = 5;
const int GREMLIN_LOOT = 2;
const int GREMLIN_DAMAGE = 10;

class Gremlin : public Battle{
public:
    Gremlin();
    ~Gremlin() = default;
    void applyEncounter(Player& player) const override;
    const std::string& getType() const override;
};
#endif //EX4_GREMLIN_H
