//
// Created by jonah on 6/13/2023.
//
#include "Mana.h"
static const int MANA=10;
Mana::Mana():Card("Mana"),m_buff(MANA) {}



void Mana::applyEncounter(Player &player) const {
    if(player.getClass()=="Healer")
    {
        printManaMessage(true);
        player.heal(m_buff);
        return;
    }
    printManaMessage(false);
}