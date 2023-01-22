
#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H
#include "Card.h"

class Barfight : public Card {
    std::string m_name = "Barfight";
public:
    Barfight();
    ~Barfight() = default;
    void applyEncounter(Player &player) const override;
};

#endif //EX4_BARFIGHT_H
