
#include "Witch.h"

Witch::Witch():
Battle(WITCH, WITCH_FORCE, WITCH_DAMAGE, WITCH_LOOT)
{}

void Witch::applyEncounter(Player& player) const
{
    if (player.getAttackStrength() >= m_force){
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), WITCH);
    }
    else{
        player.weaken(WITCH_FORCE_LOSS);
        player.damage(m_damage);
        printLossBattle(player.getName(), WITCH);
    }
}

const std::string& Witch::getType() const
{
    return WITCH;
}
