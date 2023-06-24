//
// Created by jonah on 6/13/2023.
//

#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H
#include "Card.h"

class Barfight:public Card{
public:
    Barfight();
    void applyEncounter(Player& player) const override;
    //void printCard(std::ostream& os)const override;//maybe will not need it here
private:
    int m_hpLoss;
};

#endif //EX4_BARFIGHT_H
