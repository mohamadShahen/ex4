
#include "Ninja.h"

using namespace std;

Ninja::Ninja(const string& name): Player(name)
{}

Ninja::Ninja(const Ninja& player): Player(player.m_name)
{}

void Ninja::addCoins(const int value)
{
    m_coins += value*2;
}