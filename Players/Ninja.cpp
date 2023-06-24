//
// Created by jonah on 6/12/2023.
//
#include "Ninja.h"

Ninja::Ninja(std::string name): Player(name)
{
    m_class="Ninja";
}

void Ninja::addCoins(int coins) {
    if(coins<0){
         throw InvalidParam();
    }
    m_coins=m_coins+(coins*2);
}