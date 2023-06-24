//
// Created by jonah on 6/13/2023.
//

#ifndef EX4_WELL_H
#define EX4_WELL_H

#include "Card.h"
class Well: public Card{
public:
    Well();
    void applyEncounter(Player& player) const override;
private:
    int m_hpLoss;
};

#endif //EX4_WELL_H
