
#include "Mana.h"

Mana::Mana() : Card(MANA){}

void Mana::applyEncounter(Player &player) const
{
    if (player.getType() == HEALER){
        player.heal(MANA_VALUE);
        printManaMessage(true);
        return;
    }
    printManaMessage(false);
    return;
}

