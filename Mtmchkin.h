#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include "Card.h"
#include "Player.h"
#include "CardPath.h"
#include "queue"
#include "memory"
#include "map"
#include "deque"
#include "Deck.h"


class Mtmchkin{

public:

    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

    /*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;
    Mtmchkin(const Mtmchkin&) = delete;
    Mtmchkin& operator=(const Mtmchkin& other) = delete;

private:
    int m_count;
    //std::map<std::string, std::shared_ptr<Card>> cardSet;
    //std::queue<std::shared_ptr<Card>> deck;
    Deck m_mtmDeck;
    std::deque<std::shared_ptr<Player>> m_listPlayers;
    std::deque<std::shared_ptr<Player>> m_listLeaderBored;
    int m_playedTurns;
    int m_numOfPlayers;

};



#endif /* MTMCHKIN_H_ */