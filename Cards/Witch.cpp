//
// Created by Tamer Khalifa on 13/01/2023.
//

#include "Witch.h"

Witch::Witch() : Battle(WITCH, WITCH_FORCE, WITCH_DAMAGE, WITCH_LOOT){
    m_forceLoss = WITCH_FORCE_LOSS;
}

//void Witch::applyEncounter(Player &player) const
//{
//    if (player.getAttackStrength() >= m_force){
//        player.addCoins(m_loot);
//        printWinBattle(player.m_name, m_name);
//    }
//    else{
//        printLossBattle(player.m_name, m_name);
//        player.damage(m_damage) // don't know how to use the healthpoints class
//        player.weaken(WITCH_FORCE_LOSS);
//        // might need to implement a player check after each encounter so as to end or continue the game
//    }
//}