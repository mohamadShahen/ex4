#ifndef EX2_Card_H
#define EX2_Card_H

#include <string>
#include "Player.h"
#include "utilities.h"

const std::string HEALER = "Healer";
const std::string NINJA = "Ninja";
const std::string WARRIOR = "Warrior";
const std::string TREASURE = "Treasure";
const std::string MERCHANT = "Merchant";
const std::string WELL = "Well";
const std::string BARFIGHT = "Barfight";
const std::string MANA = "Mana";

const int MANA_VALUE = 10;
const int BARFIGHT_DAMAGE = 10;
const int WELL_DAMAGE = 10;

const int BUY_NOTHING = 0;
const int HEALTH_POTION_PRICE = 5;
const int FORCE_BOOST_PRICE = 10;
const int HEALTH_POTION = 1;
const int FORCE_BOOST = 2;

const std::string GREMLIN = "Gremlin";
const int GREMLIN_FORCE = 5;
const int GREMLIN_LOOT = 2;
const int GREMLIN_DAMAGE = 10;

const std::string WITCH = "Witch";
const int WITCH_FORCE = 11;
const int WITCH_LOOT = 2;
const int WITCH_DAMAGE = 10;
const int WITCH_FORCE_LOSS = 1;

const std::string DRAGON = "Dragon";
const int DRAGON_FORCE = 25;
const int DRAGON_LOOT = 1000;
const int DRAGON_DAMAGE = 100;

class Card {
public:
    Card(std::string type);
    Card(const Card&) = default;

    ~Card() = default;
    Card& operator=(const Card& other) = default;
    //Card& operator[](int index);
//    virtual void applyEncounter(Player& player) const;

protected:
    std::string m_type;

private:
    Card *m_card;
    static Card* createCard(std::string type);

};

#endif //EX2_Card_H
