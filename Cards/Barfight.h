
#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include "Card.h"

const int BARFIGHT_DAMAGE = 10;

class Barfight : public Card {
    std::string m_name = "Barfight";
public:
    Barfight();
    virtual ~Barfight() = default;
    void applyEncounter(Player &player) const override;
    const std::string& getType() const override;
};

#endif //EX4_BARFIGHT_H
