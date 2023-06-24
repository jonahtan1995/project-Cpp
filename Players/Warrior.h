//
// Created by jonah on 6/13/2023.
//

#ifndef EX4_WARRIOR_H
#define EX4_WARRIOR_H

#include "Player.h"

class Warrior:public Player{
public:
  explicit Warrior(std::string name);
    ~Warrior();

    int getAttackStrength() override;
};

#endif //EX4_WARRIOR_H
