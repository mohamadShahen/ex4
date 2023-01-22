
#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include "Card.h"

const int BUY_NOTHING = 0;
const int HEALTH_POTION_PRICE = 5;
const int FORCE_BOOST_PRICE = 10;
const int HEALTH_POTION = 1;
const int FORCE_BOOST = 2;

class Merchant : public Card{
public:
    Merchant();
    ~Merchant() = default ;
    void applyEncounter(Player &player) const override;
    const std::string& getType() const override;
};

#endif //EX4_MERCHANT_H
