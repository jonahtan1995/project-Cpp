//
// Created by jonah on 6/12/2023.
//

#ifndef EX4_NINJA_H
#define EX4_NINJA_H
#include "Player.h"

class Ninja:public Player{
public:
  explicit Ninja(std::string name);
  ~Ninja()=default;

    void addCoins(int coins) override;

};




#endif //EX4_NINJA_H
