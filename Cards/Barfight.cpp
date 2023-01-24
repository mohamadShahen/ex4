
#include "Barfight.h"

Barfight::Barfight() : Card(){}

void Barfight::applyEncounter(Player &player) const
{
    if (player.getType() == WARRIOR){
        printBarfightMessage(true);
        return;
    }
    player.damage(BARFIGHT_DAMAGE);
    printBarfightMessage(false);
}

const std::string& Barfight::getType() const
{
    return BARFIGHT;
}
