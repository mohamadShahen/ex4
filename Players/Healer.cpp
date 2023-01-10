
#include "Healer.h"

using namespace std;

Healer::Healer(const string& name): Player(name)
{}

Healer::Healer(const Healer& player): Player(player.m_name)
{}

void Healer::heal (const int value)
{
    m_HP += value*2;
}