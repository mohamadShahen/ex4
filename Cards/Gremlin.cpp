
#include "Gremlin.h"

Gremlin::Gremlin() :
Battle(GREMLIN, GREMLIN_FORCE, GREMLIN_DAMAGE, GREMLIN_LOOT)
{}

void Gremlin::applyEncounter(Player& player) const
{
    if (player.getAttackStrength() >= m_force){
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), GREMLIN);
    }
    else{
        player.damage(m_damage);
        printLossBattle(player.getName(), GREMLIN);
    }
}

const std::string& Gremlin::getType() const
{
    return GREMLIN;
}
