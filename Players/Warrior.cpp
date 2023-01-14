
#include "Warrior.h"
using namespace std;

Warrior::Warrior(const string& name): Player(name)
{}

Warrior::Warrior(const Warrior& player): Player(player.m_name)
{}

int Warrior::getAttackStrength() const
{
    return m_force*2 + m_level;
}

std::string Warrior::getType() const
{
    return WARRIOR;
}