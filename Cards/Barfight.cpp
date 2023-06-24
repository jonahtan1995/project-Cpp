//
// Created by jonah on 6/13/2023.
//

#include "Barfight.h"
static const int LOSE_LIFE=10;
Barfight::Barfight():Card("Barfight"),m_hpLoss(LOSE_LIFE) {}

void Barfight::applyEncounter(Player& player) const
{
    if(player.getClass()=="Warrior")
    {
        printBarfightMessage(true);
        return;
    }
    player.damage(m_hpLoss);
    printBarfightMessage(false);
}

/*
void Barfight::printCard(std::ostream& os)const
{

}
*/