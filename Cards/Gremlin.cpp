//
// Created by Tamer Khalifa on 13/01/2023.
//
#include "Gremlin.h"

Gremlin::Gremlin() : Battle(GREMLIN, GREMLIN_FORCE, GREMLIN_DAMAGE, GREMLIN_LOOT){}

void Gremlin::applyEncounter(Player &player) const
{
    if (player.getAttackStrength() >= m_force){
        player.addCoins(m_loot);
        printWinBattle(player.m_name, m_name);
    }
    else{
        printLossBattle(player.m_name, m_name);
        player.damage(m_damage) // don't know how to use the healthpoints class
        // might need to implement a player check after each encounter so as to end or continue the game
    }
}

#include "Gremlin.h"