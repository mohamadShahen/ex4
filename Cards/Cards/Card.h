
#ifndef EX2_Card_H
#define EX2_Card_H

#include <string>
#include "../utilities.h"
const int WITCH_FORCE_LOSS = 1;

const std::string TREASURE = "Treasure";
const std::string MERCHANT = "Merchant";
const std::string WELL = "Well";
const std::string BARFIGHT = "Barfight";
const std::string MANA = "Mana";
const std::string GREMLIN = "Gremlin";
const std::string WITCH = "Witch";
const std::string DRAGON = "Dragon";

class Card {
public:
    Card() = default;
    Card(const Card&) = default;
    virtual ~Card() = default;
    Card& operator=(const Card& other) = default;
    virtual void applyEncounter(Player& player) const = 0;
    virtual const std::string& getType() const = 0;
    friend std::ostream& operator<<(std::ostream& os, Card& card);

};

class Battle : public Card {


public:
    Battle(const std::string& name, const int& force, const int& damage, const int& loot);
    ~Battle() = default;

protected:
    int m_force;
    int m_damage;
    int m_loot;
    friend std::ostream& operator<<(std::ostream& os, Battle& card);

};

#endif //EX2_Card_H
