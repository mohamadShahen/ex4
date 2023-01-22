
#ifndef EX4_MANA_H
#define EX4_MANA_H

#include "Card.h"

const int MANA_VALUE = 10;

class Mana : public Card{

public:
    Mana();
    ~Mana() = default;
    void applyEncounter(Player &player) const override;
    const std::string& getType() const override;
};

#endif //EX4_MANA_H
