#include "Treasure.h"
static const int COINS=10;
Treasure::Treasure():Card("Treasure"),m_coins(COINS){}

void Treasure::applyEncounter(Player& player) const {
    player.addCoins(m_coins);
    printTreasureMessage();
    return;
}

