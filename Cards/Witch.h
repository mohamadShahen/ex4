
#ifndef EX4_WITCH_H
#define EX4_WITCH_H

#include "Card.h"

const int WITCH_FORCE = 11;
const int WITCH_LOOT = 2;
const int WITCH_DAMAGE = 10;

class Witch : public Battle{
public:
    Witch();
    virtual ~Witch() = default;
    const std::string& getType() const override;
    void applyEncounter(Player& player) const override;
};


#endif //EX4_WITCH_H
