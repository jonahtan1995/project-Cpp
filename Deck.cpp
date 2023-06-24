//
// Created by jonah on 6/17/2023.
//
#include "Card.h"
#include "Deck.h"
#include "Barfight.h"
#include "Dragon.h"
#include "Gremlin.h"
#include "Mana.h"
#include "Well.h"
#include "Merchant.h"
#include "Treasure.h"
#include "Witch.h"
#include <fstream>
#include <map>
#include <queue>
#include "Exception.h"
#include "memory"

static const int MIN_SIZE = 5;

static bool isCardKnown(std::string card) {
    if(card == "Mana" ||
       card == "Barfight" ||
       card == "Well" ||
       card == "Treasure" ||
       card == "Merchant" ||
       card == "Gremlin" ||
       card == "Witch" ||
       card == "Dragon")
    {
        return true;
    }
    return false;
}

std::exception e;

void intializeCardSet(std::map<std::string,std::shared_ptr<Card>>& cardSet){
    // Manual intialization of m_cardSet - easy to maintain.
    {
        using namespace std;
        cardSet["Gremlin"] = make_shared<Gremlin>();
        cardSet["Barfight"] = make_shared<Barfight>();
        cardSet["Dragon"] = make_shared<Dragon>();
        cardSet["Mana"] = make_shared<Mana>();
        cardSet["Merchant"] = make_shared<Merchant>();
        cardSet["Treasure"] = make_shared<Treasure>();
        cardSet["Well"] = make_shared<Well>();
        cardSet["Witch"] = make_shared<Witch>();
    }
}

void Deck::addNewCardToBottom(const std::string cardName){
    if(!isCardKnown(cardName)){
        throw badCardName();
    }
    m_deck.push_back(m_cardSet[cardName]);
}

std::shared_ptr<Card> Deck::drawAndPlaceAtBottom(){
    {
        using namespace std;
        shared_ptr<Card> temp = m_deck.front();
        m_deck.pop_front();
        m_deck.push_back(temp);
        return temp;
    }
}


Deck::Deck(const std::string fileName){
        using namespace std;
        ifstream inputFile(fileName);
        if(!inputFile){
            throw DeckFileNotFound();
        }
        intializeCardSet(m_cardSet);
        string tempCard;


        m_deckSize = 0;
        while(getline(inputFile, tempCard)){
            try{
                addNewCardToBottom(tempCard);
            }
             catch(const badCardName& e){
                 throw DeckFileFormatError(m_deckSize+1);
             }
            m_deckSize++;
        }
        if(m_deckSize < MIN_SIZE){
            throw DeckFileInvalidSize();
        }
}


