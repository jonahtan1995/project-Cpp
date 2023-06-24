//
// Created by jonah on 6/13/2023.
//
#include "Warrior.h"

Warrior::Warrior(std::string name) : Player(name)
{
    m_class="Warrior";
}
Warrior::~Warrior(){};

int Warrior::getAttackStrength()
{
    return((m_force*2)+m_level);
}