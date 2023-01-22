
#include "Well.h"

Well::Well() : Card(WELL){}

void Well::applyEncounter(Player &player) const
{
    if (player.getType() == NINJA){
        printWellMessage(true);
        return;
    }
    player.damage(WELL_DAMAGE);
    printWellMessage(false);
}
