//
// Created by Tamer Khalifa on 13/01/2023.
//

#include "Treasure.h"

Treasure::Treasure() : Card("Treasure"){}


void Treasure::applyEncounter(Player &player) const
{
    player.addCoins(m_coins);
}
