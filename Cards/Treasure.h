//
// Created by Tamer Khalifa on 13/01/2023.
//

#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H
#include "Card.h"

class Treasure : public Card{
    int m_coins = 10;
public:
    Treasure();
    ~Treasure() = default;
    void applyEncounter(Player &player) const override;
};

#endif //EX4_TREASURE_H
