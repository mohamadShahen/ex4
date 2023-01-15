//
// Created by Tamer Khalifa on 14/01/2023.
//

#include "Well.h"

Well::Well() : Card(m_name){}

void Well::applyEncounter(Player &player) const
{
    if (player.getType() == NINJA){
        printWellMessage(true);
        return;
    }
    player.damage(WELL_DAMAGE);
    printWellMessage(false);
}
