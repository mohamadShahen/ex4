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

Card* Card::createCard(std::string type)
{
    if (type == GREMLIN) {
        return dynamic_cast<Card*> (new Gremlin());
    }
    if (type == WITCH){
        return dynamic_cast<Card*> (new Witch());
    }
    if (type == DRAGON){
        return dynamic_cast<Card*> (new Dragon());
    }
    if (type == TREASURE){
        return dynamic_cast<Card*> (new Treasure());
    }
    if (type == MERCHANT){
        return dynamic_cast<Card*> (new Merchant());
    }
    if (type == WELL){
        return dynamic_cast<Card*> (new Well());
    }
    if (type == BARFIGHT){
        return dynamic_cast<Card*> (new Barfight());
    }
    if (type == MANA){
        return dynamic_cast<Card*> (new Mana());
    }
}

Card::Card(const std::string type)
{
    m_card = createCard(type);
}





