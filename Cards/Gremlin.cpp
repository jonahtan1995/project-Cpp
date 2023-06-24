#include "Gremlin.h"

static const int FORCE = 6;
static const int LOOT = 2;
static const int HP_LOSS = 10;

Gremlin::Gremlin() : Battle("Gremlin"){
    m_force = FORCE;
    m_loot = LOOT;
    m_damage = HP_LOSS;
}

void Gremlin::applyEncounter(Player &player) const {
    if(player.getLevel() + player.getAttackStrength() >= FORCE){
        player.levelUp();
        player.addCoins(LOOT);
        printWinBattle(player.getName(), this->m_name);
        return;
    }

    player.damage(HP_LOSS);
    printLossBattle(player.getName(), this->m_name);
    return;
}

