#ifndef EX4_GREMLIN_H
#define EX4_GREMLIN_H

#include "Battle.h"
class Gremlin: public Battle{
public:
    Gremlin();
    void applyEncounter(Player& player) const override;
};

#endif //EX4_GREMLIN_H