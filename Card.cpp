#include "Card.h"

//constructer for Card class
Card::Card(CardType type, const CardStats &stats)
{
    m_effect = type;
    m_stats = stats;
}

//method to apply encounter depending on each card type
void Card::applyEncounter(Player& player) const
{
    if(m_effect == CardType::Battle)
    {
        if(player.getAttackStrength() >= m_stats.force)
        {
            player.levelUp();
            player.addCoins(m_stats.loot);
            printBattleResult(true);
            return;
        }
        else
        {
            player.damage(m_stats.hpLossOnDefeat);
            printBattleResult(false);
            return;
        }
    }

    if(m_effect == CardType::Buff)
    {
        if(player.pay(m_stats.cost))
        {
            player.buff(m_stats.buff);
        }
        return;
    }

    if(m_effect == CardType::Heal)
    {
        if(player.pay(m_stats.cost))
        {
            player.heal(m_stats.heal);
        }
        return;
    }

    if(m_effect == CardType::Treasure)
    {
        player.addCoins(m_stats.loot);
        return;
    }


}

//method to print the info of the card encountered
void Card::printInfo() const
{
    switch (m_effect)
    {
        case CardType::Battle:
            printBattleCardInfo(m_stats);
            break;
        case CardType::Buff:
            printBuffCardInfo(m_stats);
            break;
        case CardType::Heal:
            printHealCardInfo(m_stats);
            break;
        case CardType::Treasure:
            printTreasureCardInfo(m_stats);
            break;
    }
}
