//
// Created by Tamer Khalifa on 13/01/2023.
//

#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H
#include "Card.h"

class Merchant : public Card{
    int m_heal = 1;
    int m_force = 1;

public:
    Merchant();
    ~Merchant() = default ;
    void applyEncounter(Player &player) const override;
    int healthPotion() const;
    int forceBoost() const;
};

#endif //EX4_MERCHANT_H
