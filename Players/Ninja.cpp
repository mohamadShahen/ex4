
#include "Ninja.h"

using namespace std;

Ninja::Ninja(const string& name):
Player(name)
{}

void Ninja::addCoins(const int& value)
{
    m_coins += value*2;
}

const string& Ninja::getType() const
{
    return NINJA;
}