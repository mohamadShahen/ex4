
#include "Healer.h"

using namespace std;

Healer::Healer(const string& name):
Player(name)
{}

void Healer::heal (const int& value)
{
    m_HP += value*2;
}

const string& Healer::getType() const
{
    return HEALER;
}