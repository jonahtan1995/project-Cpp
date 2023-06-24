#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H

#include "Card.h"
class Treasure: public Card{
public:
    Treasure();
    void applyEncounter(Player& player) const override;
private:
    int m_coins;
};

#endif //EX4_TREASURE_H