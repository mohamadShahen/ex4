
#ifndef EX4_MANA_H
#define EX4_MANA_H
#include "Card.h"

class Mana : public Card{
    std::string m_name = "Mana";

public:
    Mana();
    ~Mana() = default;
    void applyEncounter(Player &player) const override;
};

#endif //EX4_MANA_H
