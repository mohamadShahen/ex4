#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_


#include "utilities.h"
#include "Players/Player.h"
#include "Players/Ninja.h"
#include "Players/Warrior.h"
#include "Players/Healer.h"
#include "Cards/Card.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Gremlin.h"
#include "Cards/Mana.h"
#include "Cards/Merchant.h"
#include "Cards/Treasure.h"
#include "Cards/Well.h"
#include "Cards/Witch.h"
#include "tool/Queue.h"
#include "tool/HealthPoints.h"
#include "Exception.h"
#include <memory>
#include <queue>

const int MINIMUM_CARDS_NUMBER = 5;
class Mtmchkin{

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);

    ~Mtmchkin() = default;
    x
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

    int getPlayerRank(const std::shared_ptr<Player> wanted) const;


private:
    Queue<std::shared_ptr<Card>> m_deck;
    Queue<std::shared_ptr<Player>> m_team;
    int m_rounds = 0;
    std::shared_ptr<Player>* m_leaderboard;
};


#endif /* MTMCHKIN_H_ */
