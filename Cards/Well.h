//
// Created by Tamer Khalifa on 14/01/2023.
//

#ifndef EX4_WELL_H
#define EX4_WELL_H
#include "Card.h"

class Well : public Card{
    std::string m_name = "Well";

public:
    Well();
    ~Well();
    void applyEncounter(Player &player) const override;
}
#endif //EX4_WELL_H
