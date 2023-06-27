//
// Created by jonah on 6/16/2023.
//

#include "Mtmchkin.h"
#include "iostream"
#include "queue"
#include "string"
#include "memory"
#include "map"
#include "Barfight.h"
#include "Dragon.h"
#include "Gremlin.h"
#include "Mana.h"
#include "Well.h"
#include "Treasure.h"
#include "Merchant.h"
#include "Witch.h"
#include <fstream>
#include "Exception.h"
#include "Deck.h"
#include "Warrior.h"
#include "Healer.h"
#include "Ninja.h"


static const int LOOSE_HP=0;
static const int WIN_LEVEL=10;

enum class PlayerStatus {LOSE,WIN,TIE};
/*
void nameAndJobErrorCorrection(std::string input, std::string& name, std::string& job){
    while
}
*/

//this function take care of exception
static bool charCheker(std::string name)
{
    // this is iterator that checks char char to see if it is really a valid letter
    for(char ch: name){
        if((ch>=65&&ch<=90)||(ch>=97&&ch<=122))
        {
            continue;
        }
        else{
            return false;
        }
    }
    return true;

}


static bool checkInputOfPlayers(int numOfPlayers)
{
    if(numOfPlayers>=2 && numOfPlayers<=6)
    {
        return true;
    }
    return false;

}
static bool checkNameAndJob(std::string name,std::string job)
{
    // this is name checks
    if(name.size()>15 || name.empty())
    {
        printInvalidName();
        return false;
    }
    if(!charCheker(name))
    {
        printInvalidName();
        return false;
    }

    //this is job check
    if(!charCheker(job))
    {
        printInvalidClass();
        return false;
    }

    if(job!="Ninja" && job!="Healer" && job!="Warrior")
    {
        printInvalidClass();
        return false;
    }
    return true;

}
/*
static bool validCardCheck(std::string card) {
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
 */
/*
static void inputMap(std::map<std::string,std::shared_ptr<Card>>cardSet)
{
    cardSet["Mana"] = std::shared_ptr<Card>(new Mana());
    cardSet["Barfight"] = std::shared_ptr<Card>(new Barfight());
    cardSet["Well"] = std::shared_ptr<Card>(new Well());
    cardSet["Treasure"] = std::shared_ptr<Card>(new Treasure());
    cardSet["Merchant"] = std::shared_ptr<Card>(new Merchant());
    cardSet["Gremlin"] = std::shared_ptr<Card>(new Gremlin());
    cardSet["Witch"] = std::shared_ptr<Card>(new Witch());
    cardSet["Dragon"] = std::shared_ptr<Card>(new Dragon());
}
*/
/*
static void inputFromFileToDeck(const std::string &fileName, std::queue<std::shared_ptr<Card>>& q,std::map<std::string,std::shared_ptr<Card>>cardSet)
{
    std::ifstream file (fileName);
    if(!file)
    {
        //throw something
    }
    std::string cardName;
    while(std::getline(file,cardName))
    {
        q.push(cardSet[cardName]);
    }
}
 */

/*
static void inputFromPlayerQueueToLeaderQueue(std::deque<std::shared_ptr<Player>>& listPlayers,  std::deque<std::shared_ptr<std::shared_ptr<Player>>> listLeaderBored)
{
   for(std::shared_ptr<Player>& player1:listPlayers)
   {
       //std::shared_ptr<std::shared_ptr<Player>>temp (new std::shared_ptr<Player>(player1));
       std::shared_ptr<std::shared_ptr<Player>> temp = std::make_shared<std::shared_ptr<Player>>(player1);
       listLeaderBored.push_back(temp);

   }
}
*/
/*
static PlayerStatus checkPlayerStatus(const Player& player)
{
    //first check lose
    if(player.getHp()==LOOSE_HP)
    {
        return PlayerStatus::LOSE;
    }
   else if(player.getLevel()==WIN_LEVEL)
    {
        return PlayerStatus::WIN;
    }
   else{
       return PlayerStatus::TIE;
   }
}
 */

/*
void restoreLeaderboard(std::deque<std::shared_ptr<Player>>&listPlayers,std::deque<std::shared_ptr<Player>>& listLeaderBored)
{
    for(int i=0;i<listPlayers.size();i++)
    {
        if(listLeaderBored[i]->getLevel()==WIN_LEVEL||listLeaderBored[i]->getHp()==LOOSE_HP)
        {
            continue;
        }
        else{

        }
    }
}

 void insertPlayerToLeaderboard(

*/

void insertPlayerToLeaderboard(std::deque<std::shared_ptr<Player>>& leaderboard, const std::shared_ptr<Player>& toEnqueue){
    bool hasWon = toEnqueue->getLevel() == WIN_LEVEL;
    unsigned long i = 0;
    for(; i < leaderboard.size(); i++){
        if(leaderboard[i] == toEnqueue){
            leaderboard[i] = NULL;
            break;
        }
    }
    i += hasWon ? -1: 1;//is this the soultion ??
    while((i >= 0 && i < leaderboard.size()) && !leaderboard[i]->hasFinished()){
        leaderboard[hasWon ? i+1 : i-1] = leaderboard[i];
        i += hasWon ? -1: 1;
    }
    leaderboard[hasWon ? i+1 : i-1] = toEnqueue;

}


/*void insertWinnerPlayerInLeaderBorad(std::deque<std::shared_ptr<Player>>&listPlayers,std::deque<std::shared_ptr<Player>>& listLeaderBored)
{
    std::shared_ptr<Player> winnerPlayer=listPlayers.front();
    for(int winner=0;winner<listPlayers.size();winner++) {
        if(listLeaderBored[winner]==winnerPlayer)
        {
            for(int j=0;j<listLeaderBored.size();j++)
            {
                if(listLeaderBored[j]->getLevel()==WIN_LEVEL)
                {
                    continue;
                }
                else{
                    std::shared_ptr<Player> temp=listLeaderBored[winner];


                }
            }
        }
        else
        {
            continue;
        }
    }
}


void insertLooserPlayerInLeaderBorad(std::deque<std::shared_ptr<Player>>&listPlayers,std::deque<std::shared_ptr<Player>>& listLeaderBored)
{
    std::shared_ptr<Player> loserPlayer=listPlayers.front();
    for(int i=) {
        if(player1==loserPlayer)
        {
            for(std::shared_ptr<Player>& player2:listLeaderBored)
            {
                if((listLeaderBored.front())->getHp()==LOOSE_HP)
                {
                    continue;
                }
                else{
                    swap(player1,player2);
                }
            }
        }
        else
        {
            continue;
        }
    }
}
*/
/*
static void appliyChangeToLeaderboard(PlayerStatus check,std::deque<std::shared_ptr<Player>>&listPlayers,std::deque<std::shared_ptr<Player>>& listLeaderBored)
{
    if(check==PlayerStatus::WIN)
    {
        insertWinnerPlayerInLeaderBorad(listPlayers,listLeaderBored);
    }
    else if(check==PlayerStatus::LOSE)
    {
        //insertPlayerInLeaderBorad(listPlayers,listLeaderBored);
    }
    else{
        return;
    }
}

*/
std::shared_ptr<Player> inputCorrectPlayer(std::string name,std::string job)
{
    if(job=="Warrior")
    {
        std::shared_ptr<Player> player(new Warrior(name));
        return player;
    }
    else if(job=="Ninja")
    {
        std::shared_ptr<Player> player(new Ninja(name));
        return player;
    }
    else{
        std::shared_ptr<Player> player(new Healer(name));
        return player;
    }
}



Mtmchkin::Mtmchkin(const std::string &fileName):m_mtmDeck(fileName) {
    m_count=0;
    m_playedTurns=0;
    printStartGameMessage();
    printEnterTeamSizeMessage();
    std::string userInput;
    int numOfPlayers;
    bool inputValid = false;
    while(!inputValid){
        try{
            std::getline(std::cin, userInput);
            numOfPlayers = std::stoi(userInput);
            if(!checkInputOfPlayers(numOfPlayers)){
                throw badUserInput();
            }
            else{
                inputValid = true;
            }
            inputValid = true;
        }
        catch(...){
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
        }
    }
    //int numOfPlayers = 0;
    /*
    std::getline(std::cin, numOfPlayers);
    while (!(checkInputOfPlayers(std::stoi(numOfPlayers)))) {
        printInvalidTeamSize();
        std::cin >> numOfPlayers;
    }
     */
    std::string name;
    std::string job;
    for (int i = 0; i < numOfPlayers; i++) {
        printInsertPlayerMessage();
        std::cin >> name;
        std::cin >> job;
        while (!checkNameAndJob(name,job)) {
            std::cin >> name;
            std::cin >> job;
        }
        std::shared_ptr<Player> player= inputCorrectPlayer(name,job);
        m_listPlayers.push_back(player);
    }
    m_numOfPlayers=m_listPlayers.size();
    m_listLeaderBored=m_listPlayers;

}



void Mtmchkin::playRound()
{
    using namespace std;
    printRoundStartMessage((m_count+1));
    for(int i = 1; i <= m_numOfPlayers; i++){
        shared_ptr<Player> currentPlayer = m_listPlayers.front();
        if(currentPlayer->hasFinished()){ // Landed on player that has already finished.
            m_listPlayers.pop_front();
            m_listPlayers.push_back(currentPlayer);
            continue;
        }
        printTurnStartMessage(m_listPlayers.front()->getName());
        m_mtmDeck.drawAndPlaceAtBottom()->applyEncounter(*currentPlayer);
        if(isGameOver())
        {
            printGameEndMessage();
            //maybe need brake to stop the game
        }
        insertPlayerToLeaderboard(m_listLeaderBored,currentPlayer);

        m_listPlayers.pop_front();
        m_listPlayers.push_back(currentPlayer);
    }
    m_count++;

/*
    if(m_playedTurns % m_numOfPlayers == 0){
        printRoundStartMessage((m_count+1));
    }
    m_playedTurns++;
    if(m_listPlayers.front()->hasFinished()){
        std::shared_ptr<Player>temp=m_listPlayers.front();
        m_listPlayers.pop_front();
        m_listPlayers.push_back(temp);
        return;
    }
    printTurnStartMessage(m_listPlayers.front()->getName());
    //1.2 we play the card
    m_mtmDeck.drawAndPlaceAtBottom()->applyEncounter(*(m_listPlayers.front()));
    if(isGameOver())
    {
        printGameEndMessage();
    }
    insertPlayerToLeaderboard(m_listLeaderBored,m_listPlayers.front());

    //this pushing back method might do a bug jonah
    std::shared_ptr<Player>temp=m_listPlayers.front();
    m_listPlayers.pop_front();
    m_listPlayers.push_back(temp);

*/
}


int Mtmchkin::getNumberOfRounds() const
{
  return m_count;
}



bool Mtmchkin::isGameOver() const
{
    for(std::shared_ptr<Player> currentPlayer:m_listLeaderBored){
        if(!(currentPlayer->isKnockedOut() || currentPlayer->getLevel() == WIN_LEVEL)){
            return false;
        }
    }
    return true;
}

void Mtmchkin::printLeaderBoard() const{
        printLeaderBoardStartMessage();
        unsigned long i=0;
        for(;i<m_listLeaderBored.size();i++) {
            printPlayerLeaderBoard(i + 1, *(m_listLeaderBored[i]));
        }
}


std::ostream& operator<<(std::ostream& os, const  Player& player)
{
    printPlayerDetails(os,player.getName(),player.getClass(),player.getLevel(),player.getForce(),player.getHp(),player.getCoins());
    return os;
}







    
