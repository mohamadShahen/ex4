
#include "Battle.h"
using namespace std;


Battle::Battle(const string name, const int force, const int damage, const int loot ) : Card(name){
    m_force = force;
    m_damage = damage;
    m_loot = loot;
}

void Battle::applyEncounter(Player &player) const {
    if (player.getAttackStrength() >= m_force){
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(), m_type);
    }
    else{
        if (m_type == WITCH){
            player.weaken(WITCH_FORCE_LOSS);
        }
        player.damage(m_damage);
        printLossBattle(player.getName(), m_type);
    }
}