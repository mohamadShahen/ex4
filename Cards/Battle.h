//
// Created by Tamer Khalifa on 13/01/2023.
//

#ifndef EX4_BATTLE_H
#define EX4_BATTLE_H
#include "Card.h"


class Battle : public Card{

public:
    Battle(std::string name, int force, int damage, int loot);
    ~Battle() = default;
    void applyEncounter(Player& player) const override;

protected:
    int m_force;
    int m_damage;
    int m_loot;

};


#endif //EX4_BATTLE_H
