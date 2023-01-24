
#ifndef EX4_WELL_H
#define EX4_WELL_H

#include "Card.h"

const int WELL_DAMAGE = 10;

class Well : public Card{
public:
    Well();
    virtual ~Well() = default;
    void applyEncounter(Player &player) const override;
    const std::string& getType() const override;
};

#endif //EX4_WELL_H
