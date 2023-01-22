
#include "Card.h"

using namespace std;

Battle::Battle(const string& name, const int& force, const int& damage, const int& loot ) :
        Card(), m_force(force), m_damage(damage), m_loot(loot)
{}
