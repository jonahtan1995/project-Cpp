//
// Created by jonah on 5/16/2023.
//

#ifndef EX2_Player_H
#define EX2_Player_H

#include <iostream>
#include <string>
#include <stdbool.h>


class Player{
protected:
    std::string m_name;
    std::string m_class;
    int m_level;
    int m_force;
    int m_maxHp;
    int m_hp;
    int m_coins;

    friend std::ostream& operator<<(std::ostream& os, const Player& player);

public:
    Player(std::string name);
    virtual ~Player();
    Player(const Player&);
    Player& operator=(const Player&);
    //
    void printInfo() const;
    void levelUp();
    int getLevel() const;
    void buff(int force);
    void debuff(int damage);
    virtual void heal(int hp);
    void damage(int damage);
    bool isKnockedOut() const;
    virtual void addCoins(int coins);
    bool pay(int coins);
    virtual int getAttackStrength();
    std::string getName() const; //Is this needed?
    int getCoins() const; //Is this needed?
    int getHp() const; //Is this needed?
    bool hasFinished() const;
    int getForce() const;

    //methodas i added
    class InvalidParam{};
    std::string getClass() const;

};

#endif //EX2_PLAYER_H