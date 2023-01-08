//
// Created by Tamer Khalifa on 29/11/2022.
//

#include "Player.h"

//constructor of Player class
Player::Player(const char *name, int maxHP, int force)
{
    int size = strlen(name);
    m_name = new char[size + 1];
    strcpy(m_name, name);
    m_level = STARTING_LEVEL;
    if(force < 0)
    {
        m_force = DEFAULT_FORCE;
    }
    else
    {
        m_force = force;
    }
    if(maxHP <= 0)
    {
        m_maxHP = DEFAULT_MAX_HP;
    }
    else
    {
        m_maxHP = maxHP;
    }
    m_hp = maxHP;
    m_coins = 0;
}

//copy constructor for the Player class
Player::Player(const Player& copy):
        m_name(new char [strlen(copy.m_name) + 1]),
        m_level(copy.m_level),
        m_force(copy.m_force),
        m_maxHP(copy.m_maxHP),
        m_hp(copy.m_hp),
        m_coins(copy.m_coins)
{
    strcpy(m_name, copy.m_name);
}

//destructor for Player class
Player::~Player()
{
    delete [] m_name;
}

//print information of player
void Player::printInfo() const
{
    printPlayerInfo(m_name, m_level, m_force, m_hp, m_coins);
}

//adds level to the player
void Player::levelUp()
{
    if(m_level != MAX_LEVEL)
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
    if(value >= 0)
    {
        if (m_hp + value <= m_maxHP)
        {
            m_hp += value;
        }
        else
        {
            m_hp = m_maxHP;
        }
    }
}

//decreases player's hp with the value inserted
void Player::damage(int value)
{
    if(value >= 0)
    {
        if(m_hp >= value)
        {
            m_hp -= value;
        }
        else
        {
            m_hp = 0;
        }
    }

}

//checks if player is knocked out(hp = 0)
bool Player::isKnockedOut() const
{
    if (m_hp == 0)
    {
        return true;
    }
    return false;
}

//increses player's coins with the inserted value
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