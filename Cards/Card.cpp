
#include "Card.h"

using namespace std;

std::ostream& operator<<(ostream& os, Card& card)
{
    printCardDetails(os,card.getType());
    printEndOfCardDetails(os);
    return os;
}

std::ostream& operator<<(ostream& os, Battle& card)
{
    printCardDetails(os,card.getType());
    printMonsterDetails(os, card.m_force, card.m_damage, card.m_loot, (card.getType() == DRAGON));
    printEndOfCardDetails(os);
    return os;
}


Battle::Battle(const string& name, const int& force, const int& damage, const int& loot ) :
        Card(), m_force(force), m_damage(damage), m_loot(loot)
{}
