
#include "Merchant.h"

using namespace std;

Merchant::Merchant():
Card()
{}

void Merchant::applyEncounter(Player &player) const
{
    printMerchantInitialMessageForInteractiveEncounter(cout ,player.getName(), player.getCoins());
    int i = -1;
    cin >> i;
    while(i < BUY_NOTHING || i > FORCE_BOOST){
        printInvalidInput();
        cin >> i;
    }
    if (i == HEALTH_POTION && player.pay(HEALTH_POTION_PRICE)){
        player.heal(HEALTH_POTION);
        printMerchantSummary(cout, player.getName(), HEALTH_POTION, HEALTH_POTION_PRICE);
        return;
    }
    else{
        printMerchantInsufficientCoins(cout);
    }
    if(i == FORCE_BOOST && player.pay(FORCE_BOOST_PRICE)){
        player.buff(FORCE_BOOST);
        printMerchantSummary(cout, player.getName(), FORCE_BOOST, FORCE_BOOST_PRICE);
        return;
    }
    else{
        printMerchantInsufficientCoins(cout);
    }
}

const string& Merchant::getType() const
{
    return MERCHANT;
}
