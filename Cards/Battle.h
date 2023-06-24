#ifndef EX4_BATTLECARD_H
#define EX4_BATTLECARD_H

#include "Card.h"
class Battle:public Card{
public:
    Battle(std::string type) : Card(type){};
    virtual void applyEncounter(Player& player) const override = 0;
    friend std::ostream& operator<<(std::ostream& os, const Battle& battle){
            printCardDetails(os,battle.m_name);
            printMonsterDetails(os,battle.m_force,battle.m_damage,battle.m_loot,battle.m_name=="Dragon");
            printEndOfCardDetails(os);
            return os;
    }

protected:
    int m_force ;
    int m_loot ;
    int m_damage ;
/*
public:

    void applyEncounter(Player& player) const override;
    void printCard(std::ostream& os) const override;
*/
};

#endif //EX4_BATTLECARD_H