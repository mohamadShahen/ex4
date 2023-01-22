
#include "Dragon.h"

Dragon::Dragon() :
Battle(DRAGON, DRAGON_FORCE, DRAGON_DAMAGE, DRAGON_LOOT)
{}

void Dragon::applyEncounter(Player& player) const
{
    if (player.getAttackStrength() >= m_force){
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), DRAGON);
    }
    else{
        player.damage(m_damage);
        printLossBattle(player.getName(), DRAGON);
    }
}

const std::string& Dragon::getType() const
{
    return DRAGON;
}
