#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "Battle.h"
class Dragon: public Battle{
public:
    Dragon();
    void applyEncounter(Player& player) const override;
};

#endif //EX4_DRAGON_H