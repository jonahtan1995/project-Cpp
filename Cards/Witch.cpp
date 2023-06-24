#include "Witch.h"

static const int FORCE = 10;
static const int LOOT = 2;
static const int HP_LOSS = 10;
static const int FORCE_LOSS = 1;


Witch::Witch(): Battle("Witch"){
    m_force = FORCE;
    m_loot = LOOT;
    m_damage = HP_LOSS;
}

void Witch::applyEncounter(Player &player) const {
    if(player.getLevel() + player.getAttackStrength() >= FORCE){
        player.levelUp();
        player.addCoins(LOOT);
        printWinBattle(player.getName(), this->m_name);
        return;
    }

    player.damage(HP_LOSS);
    player.debuff(FORCE_LOSS);
    printLossBattle(player.getName(), this->m_name);
    return;
}

