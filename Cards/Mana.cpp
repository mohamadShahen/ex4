
#include "Mana.h"

Mana::Mana() :
Card()
{}

void Mana::applyEncounter(Player &player) const
{
    if (player.getType() == HEALER){
        player.heal(MANA_VALUE);
        printManaMessage(true);
        return;
    }
    printManaMessage(false);
}

const std::string& Mana::getType() const
{
    return MANA;
}
