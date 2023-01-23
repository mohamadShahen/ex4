
#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H
#include "Card.h"

const int TREASURE_COINS = 10;
class Treasure : public Card{
public:
    Treasure();
    virtual ~Treasure() = default;
    void applyEncounter(Player &player) const override;
    const std::string& getType() const override;
};

#endif //EX4_TREASURE_H
