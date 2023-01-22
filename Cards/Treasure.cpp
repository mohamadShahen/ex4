
#include "Treasure.h"

Treasure::Treasure() : Card(TREASURE){}


void Treasure::applyEncounter(Player &player) const
{
    player.addCoins(m_coins);
}
