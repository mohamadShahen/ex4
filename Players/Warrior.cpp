
#include "Warrior.h"
using namespace std;

Warrior::Warrior(const string& name):
Player(name)
{}

const int& Warrior::getAttackStrength() const
{
    return (m_force*2 + m_level);
}

const string& Warrior::getType() const
{
    return WARRIOR;
}