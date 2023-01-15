//
// Created by Tamer Khalifa on 13/01/2023.
//

#include "Dragon.h"
Dragon::Dragon() : Battle(m_name, m_force, m_damage, m_loot){}

void Dragon::applyEncounter(Player &player) const
{
    if (player.getAttackStrength() >= m_force){
        player.addCoins(m_loot);
        printWinBattle(player.m_name, m_name);
    }
    else{
        printLossBattle(player.m_name, m_name);
        player.damage(m_damage);
        // might need to implement a player check after each encounter so as to end or continue the game
    }
}