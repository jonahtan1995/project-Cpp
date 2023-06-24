//
// Created by jonah on 5/16/2023.
//
#include "Player.h"
static const int LEVEL=1;
static const int FORCE=5;
static const int HP=100;
static const int COINS=10;
static const int MAX_LEVEL = 10;

Player::Player(std::string name ):
m_name(name),m_level(LEVEL),m_force(FORCE),m_maxHp(HP),m_hp(HP),m_coins(COINS) {


    if(m_force<=0)
    {
        m_force=5;
    }
    if(m_maxHp<=0)
    {
        m_maxHp = 100;
        m_hp = 100;
    }
}

//defult d'ctor
Player::~Player(){};

//copy c'tor maybe will change it to list
Player::Player(const Player& player){
    m_name=player.m_name;
    m_level=player.m_level;
    m_force=player.m_force;
    m_maxHp=player.m_maxHp;
    m_hp=player.m_hp;
    m_coins=player.m_coins;
}

Player& Player::operator=(const Player& player)
{
    //this prevents for p1=p1;
    if(this==&player)
    {
        return *this;
    }
    m_name=player.m_name;
    m_level=player.m_level;
    m_force=player.m_force;
    m_maxHp=player.m_maxHp;
    m_hp=player.m_hp;
    m_coins=player.m_coins;
    return *this;
}

/*
void Player::printInfo() const
{
    printPlayerInfo(m_name.c_str(),m_level,m_force,m_hp,m_coins);
}
*/
void Player::levelUp()
{
    if(m_level>=10)
    {
        return;
    }
    m_level++;
}

int Player::getLevel() const
{
    return m_level;
}

void Player::buff(int force)
{
    if(force<=0){
        return;
    }
    m_force+=force;
}

void Player::heal(int hp)
{
    if(hp<=0)
    {
        return;
    }
    int fullHp=hp+m_hp;
    if(fullHp>=m_maxHp)
    {
        m_hp=m_maxHp;
        return;
    }
    m_hp+=hp;
}

void Player::damage(int damage)
{
    if(damage<=0)
    {
        return;
    }
    if(damage>=m_hp)
    {
        m_hp=0;
        return;
    }
    m_hp-=damage;
}

bool Player::isKnockedOut ()const
{
    if(m_hp==0)
    {
        return true;
    }
    return false;
}

void Player::addCoins(int coins)
{
    if(coins<=0)
    {
        return;
    }
    m_coins+=coins;
}

bool Player::pay(int coins)
{
    if(coins<0)
    {
        return false;
    }
    if(m_coins<coins)
    {
        return false;
    }
    m_coins-=coins;
    return true;
}

int Player::getAttackStrength()
{
    return (m_force+m_level);
}
std::string Player::getClass()const
{
    return m_class;
}

/*
std::ostream& operator<<(std::ostream& os, const Player& player)
{
    printPlayerDetails(os,player.m_name,player.m_class,player.m_level,player.m_force,player.m_hp,player.m_coins);
    return os;
}
*/
std::string Player::getName() const{ //Is this needed?
    return m_name;
}

int Player::getCoins() const{
    return m_coins;
}

int Player::getHp() const{
    return m_hp;
}

bool Player::hasFinished() const{
    return (m_level == MAX_LEVEL || isKnockedOut());
}

int Player::getForce() const
{
    return m_force;
}

void Player::debuff(int damage){
    m_force -= damage;
    if(m_force < 0){
        m_force = 0;
    }
}