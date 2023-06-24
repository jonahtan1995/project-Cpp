//
// Created by jonah on 6/13/2023.
//
#include "Healer.h"

Healer::Healer(std::string name) : Player(name)
{
    m_class="Healer";
}

void Healer::heal(int hp) {
    if(hp<=0)
    {
        return;
    }
    int healerHp=(2*hp)+m_hp;
    if(healerHp>=m_maxHp)
    {
        m_hp=m_maxHp;
        return;
    }
    m_hp=healerHp;
}