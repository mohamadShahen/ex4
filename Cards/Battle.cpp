//
// Created by Tamer Khalifa on 13/01/2023.
//
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
        printWinBattle(player.m_name, m_type);
    }
    else{
        if (m_type == WITCH){
            player.weaken();
        }
        player.damage(m_damage);
        printLossBattle(player.m_name, m_type);

    }
}