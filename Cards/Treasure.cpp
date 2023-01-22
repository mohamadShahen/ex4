
#include "Treasure.h"

Treasure::Treasure() :
Card()
{}


void Treasure::applyEncounter(Player &player) const
{
    player.addCoins(TREASURE_COINS);
}

const std::string& Treasure::getType() const
{
    return TREASURE;
}
