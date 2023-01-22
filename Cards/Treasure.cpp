
#include "Treasure.h"

Treasure::Treasure() :
Card()
{}


void Treasure::applyEncounter(Player &player) const
{
    printTreasureMessage();
    player.addCoins(TREASURE_COINS);
}

const std::string& Treasure::getType() const
{
    return TREASURE;
}
