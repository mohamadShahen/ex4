
#include "Card.h"
#include "Gremlin.h"
#include "Witch.h"
#include "Dragon.h"
#include "Treasure.h"
#include "Merchant.h"
#include "Well.h"
#include "Barfight.h"
#include "Mana.h"

using namespace std;

//constructor for Card class


//method to apply encounter depending on each card type

unique_ptr<Card> Card::createCard(std::string type)
{
    if (type == GREMLIN) {
        return unique_ptr<Card>(new Gremlin());
    }
    if (type == WITCH){
        return unique_ptr<Card>(new Witch());
    }
    if (type == DRAGON){
        return unique_ptr<Card>(new Dragon());
    }
    if (type == TREASURE){
        return unique_ptr<Card> (new Treasure());
    }
    if (type == MERCHANT){
        return unique_ptr<Card> (new Merchant());
    }
    if (type == WELL){
        return unique_ptr<Card>(new Well());
    }
    if (type == BARFIGHT){
        return unique_ptr<Card>(new Barfight());
    }
    if (type == MANA){
        return unique_ptr<Card>(new Mana());
    }
}

Card::Card(const std::string type)
{
    m_card = createCard(type);
}





