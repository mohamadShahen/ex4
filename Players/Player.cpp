
#include "Player.h"

using namespace std;

//constructor of Player class
Player::Player(const string& name):
m_name(name)
{}

//adds level to the player
void Player::levelUp()
{
    if(m_level != LAST_LEVEL)
    {
        m_level++;
    }
}

//returns which level is the player at
int Player::getLevel() const
{
    return m_level;
}

//increases player's force with the inserted value
void Player::buff(const int value)
{
    if(value >= 0)
    {
        m_force += value;
    }
}

//decreases player's force with the inserted value
void Player::weaken(const int value)
{
    if(value >= 0)
    {
        m_force -= value;
    }
    if(m_force < 0)
    {
        m_force = 0;
    }
}

//increases player's hp with the value inserted
void Player::heal(const int value)
{
    m_HP += value;
}

//decreases player's hp with the value inserted
void Player::damage(const int value)
{
    m_HP -= value;
}

//checks if player is knocked out(hp = 0)
bool Player::isKnockedOut() const
{
    if (m_HP == 0)
    {
        return true;
    }
    return false;
}

//increases player's coins with the inserted value
void Player::addCoins(const int value)
{
    if(value >= 0)
    {
        m_coins += value;
    }
}

//checks if the player have the value inserted
//returns true if he has the value and decreases
//the inserted value and returns false if he doesn't
//have the needed amount and doesn't do anything
bool Player::pay(const int value)
{
    if(m_coins >= value)
    {
        if(value >= 0)
        {
            m_coins -= value;
        }
        return true;
    }
    return false;
}

//returns player's attack strength(force + level)
int Player::getAttackStrength() const
{
    return (m_level + m_force);
}

string Player::getName() const
{
    return m_name;
}
