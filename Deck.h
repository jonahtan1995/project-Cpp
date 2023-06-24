//
// Created by jonah on 6/17/2023.
//

#ifndef EX4_DECK_H
#define EX4_DECK_H

#include <stdio.h>
#include "Card.h"
#include <string.h>
#include <map>
#include <memory>
#include <deque>


class Deck{
    
public:

    /* 
    * @return Empty deck with just a card set.
    */
    // Deck(); NTS: This is probably not needed...

    /*
    * @param Name of text file specifying deck. Format is one card name per line.
    *
    * @return Parsed deck.
    */
    Deck(const std::string fileName);

    /*
    * @param Name of requested card.
    */
    void addNewCardToBottom(const std::string cardName);

    std::shared_ptr<Card> drawAndPlaceAtBottom();

private:

    std::map<std::string,std::shared_ptr<Card>> m_cardSet;
    int m_deckSize;
    std::deque<std::shared_ptr<Card>> m_deck;
       
};


#endif //EX4_DECK_H
