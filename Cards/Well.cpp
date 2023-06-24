//
// Created by jonah on 6/13/2023.
//

#include "Well.h"
static const int LOSE_LIFE=10;
Well::Well() : Card("Well"),m_hpLoss(LOSE_LIFE){}

void Well::applyEncounter(Player &player) const {
    if(player.getClass()== "Ninja")
    {
        printWellMessage(true);
        return;
    }
    player.damage(m_hpLoss);
    printWellMessage(false);
}


