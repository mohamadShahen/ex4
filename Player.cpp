
#include "Player.h"

//constructor of Player class
Player::Player(const char* name):m_name(new char [strlen(name) + 1])
{
    strcpy(m_name,name);
}

//copy constructor for the Player class
Player::Player(const Player& copy):m_name(new char [strlen(copy.m_name) + 1])
{
    strcpy(m_name, copy.m_name);
}

//destructor for Player class
Player::~Player()
{
    delete [] m_name;
}

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
void Player::buff(int value)
{
    if(value >= 0)
    {
        m_force += value;
    }
}

//increases player's hp with the value inserted
void Player::heal(int value)
{
    m_HP += value;
}

//decreases player's hp with the value inserted
void Player::damage(int value)
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
void Player::addCoins(int value)
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
bool Player::pay(int value)
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

Warrior::Warrior(const char* name): Player(name)
{}

Warrior::Warrior(const Warrior & player): Player(player.m_name)
{}

int Warrior::getAttackStrength() const
{
    return m_force*2 + m_level;
}

Ninja::Ninja(const char * name): Player(name)
{}

Ninja::Ninja(const Ninja & player): Player(player.m_name)
{}

void Ninja::addCoins(int value)
{
    m_coins += value*2;
}

Healer::Healer(const char * name): Player(name)
{}

Healer::Healer(const Healer & player): Player(player.m_name)
{}

void Healer::heal (int value)
{
    m_HP += value*2;
}
