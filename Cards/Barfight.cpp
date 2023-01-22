
#include "Barfight.h"

Barfight::Barfight() : Card(BARFIGHT){}

void Barfight::applyEncounter(Player &player) const
{
    if (player.getType() == WARRIOR){
        printBarfightMessage(true);
        return;
    }
    player.damage(BARFIGHT_DAMAGE);
    printBarfightMessage(false);
}
