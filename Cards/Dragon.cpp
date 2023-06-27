//
// Created by jonah on 6/17/2023.
//
#include "Dragon.h"

static const int FORCE = 25;
static const int LOOT = 1000;

Dragon::Dragon() : Battle("Dragon"){
    m_force=FORCE;
    m_loot=LOOT;
    m_damage=0;
};

void Dragon::applyEncounter(Player &player) const {
    if(player.getAttackStrength() >= FORCE){
        player.levelUp();
        player.addCoins(LOOT);
        printWinBattle(player.getName(), this->m_name);
        return;
    }

    player.damage(player.getHp());
    printLossBattle(player.getName(), this->m_name);
    return;
}

/*
void Dragon::printCard(std::ostream& os) const{
    printMonsterDetails(std::cout,FORCE,0, LOOT, true);
}
 */