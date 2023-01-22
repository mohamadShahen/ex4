
#include "Gremlin.h"

Gremlin::Gremlin() : Battle(GREMLIN, GREMLIN_FORCE, GREMLIN_DAMAGE, GREMLIN_LOOT){}

//void Gremlin::applyEncounter(Player &player) const
//{
//    if (player.getAttackStrength() >= m_force){
//        player.addCoins(m_loot);
//        printWinBattle(player.m_name, m_type);
//    }
//    else{
//        printLossBattle(player.m_name, m_type);
//        player.damage(m_damage) // don't know how to use the healthpoints class
//        // might need to implement a player check after each encounter so as to end or continue the game
//    }
//}
