//
// Created by Tamer Khalifa on 13/01/2023.
//

#include "Merchant.h"

using namespace std;

Merchant::Merchant():Card("Merchant") {}

int Merchant::healthPotion() const
{
    return m_heal;
}
int Merchant::forceBoost() const
{
    return m_force;
}

void Merchant::applyEncounter(Player &player) const
{
    printMerchantInitialMessageForInteractiveEncounter(player.getName());
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
