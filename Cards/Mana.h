//
// Created by jonah on 6/13/2023.
//

#ifndef EX4_MANA_H
#define EX4_MANA_H
#include "Card.h"

class Mana:public Card{
public:
    void applyEncounter(Player& player) const override;
    Mana();
private:
    int m_buff;
};

#endif //EX4_MANA_H
