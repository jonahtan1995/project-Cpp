#include <iostream>
#include "Card.h"
#include "utilities.h"



Card::Card(std::string name): m_name(name) {}

std::ostream& operator<<(std::ostream& os, const Card& card)//cout << card
{
    card.printCard(os);
    return os;
}

void Card::printCard(std::ostream& os)const
{
    printCardDetails(os,m_name);
    printEndOfCardDetails(os);
}



