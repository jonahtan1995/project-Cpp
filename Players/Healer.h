//
// Created by jonah on 6/13/2023.
//

#ifndef EX4_HEALER_H
#define EX4_HEALER_H

#include "Player.h"

class Healer:public Player{
public:
     explicit Healer(std::string name);
    ~Healer()=default;
    void heal(int hp) override;

};

#endif //EX4_HEALER_H
