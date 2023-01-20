//
// Created by Tamer Khalifa on 13/01/2023.
//

#ifndef EX4_WITCH_H
#define EX4_WITCH_H
#include "Battle.h"


class Witch : public Battle{
    int m_forceLoss ;
public:
    Witch();
    ~Witch() = default;
    //void applyEncounter(Player& player) const override;
};


#endif //EX4_WITCH_H
