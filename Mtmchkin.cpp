#include "Mtmchkin.h"

//constructor of game class
Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards):m_player(playerName)
{
    Player copy(playerName);
    m_status = GameStatus::MidGame;
    this->m_numOfCards = numOfCards;
    m_cards = new Card[numOfCards];
    for (int i = 0; i < numOfCards; ++i)
    {
        *(m_cards+i) = *(cardsArray+i);
    }
}

//destructor of game class
Mtmchkin::~Mtmchkin()
{
    delete [] m_cards;
}

//pick the next card out of the deck of card(cards' array)
//and prints its info and applies the encounter to it
void Mtmchkin::playNextCard()
{
    m_cards->printInfo();
    m_cards->applyEncounter(m_player);
    m_player.printInfo();
    if (m_player.isKnockedOut())
    {
        m_status = GameStatus::Loss;
    }
    if (m_player.getLevel() == MAX_LEVEL)
    {
        m_status = GameStatus::Win;
    }
    Card temp(*m_cards);
    for(int i=0; i < m_numOfCards - 1; i++)
    {
        m_cards[i]=m_cards[i+1];
    }
    m_cards[m_numOfCards - 1] = temp;
}

//checks if the game is over(player's level is 10 or player's hp is 0)
bool Mtmchkin::isOver() const
{
    if (m_player.getLevel() == MAX_LEVEL || m_player.isKnockedOut())
    {
        return true;
    }

    else
    {
        return false;
    }
}

//returns the status of the game
GameStatus Mtmchkin::getGameStatus() const
{
    return m_status;
}