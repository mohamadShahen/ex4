//
// Created by Tamer Khalifa on 14/01/2023.
//

#include "Mana.h"

Mana::Mana() : Card(m_name){}

void Mana::applyEncounter(Player &player) const
{
    if (player.getType = HEALER){
        player.heal(MANA);
        printManaMessage(true);
        return;
    }
    printManaMessage(false);
    return;
}

