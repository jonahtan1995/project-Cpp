#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include "Card.h"
class Merchant: public Card{
public:
    Merchant();
    void applyEncounter(Player& player) const override;
private:
    int m_buff;
    int m_hp;
};

#endif //EX4_MERCHANT_H