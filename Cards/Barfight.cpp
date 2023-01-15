//
// Created by Tamer Khalifa on 14/01/2023.
//

#include "Barfight.h"

Barfight::Barfight() : Card(m_name){}

void Barfight::applyEncounter(Player &player) const
{
    if (player.getType() == WARRIOR){
        printBarfightMessage(true);
        return;
    }
    player.damage(BARFIGHT_DAMAGE);
    printBarfightMessage(false);
}
