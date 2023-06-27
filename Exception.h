//
// Created by jonah on 6/13/2023.
//

#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H
#include "iostream"
#include "string"
#include "exception"
#include "utilities.h"



class DeckFileNotFound:public std::exception
{
public:
    const char* what() const noexcept override
    {
       const char* s1="Deck File Error: File not found";
       return s1;
    }
};

class DeckFileFormatError:public std::exception
{
private:
    int m_index;
    std::string m_message;
public:
    DeckFileFormatError(int index):m_index(index)
    {
        m_message ="Deck File Error: File format error in line "+ std::to_string(m_index);// + "\n
    }
    const char* what() const noexcept override
    {
        //std::cout <<"Deck File Error: File format error in line"<<" "<<m_index<<std::endl;
        return m_message.c_str();
    }
};

class DeckFileInvalidSize:public std::exception
{
public:
    const char* what() const noexcept override
    {
        const char* s1="Deck File Error: Deck size is invalid";
        return s1;
    }
};

class badCardName:public std::exception
{
    const char* what() const noexcept override
    {
        const char* s1="Bad card name";
        return s1;
    }
};

class badUserInput:public std::exception
{};


/*
class badDeckSize:public std::exception
{
    const char* what() const noexcept override
    {
        const char* s1="Bad deck size";
        return s1;
    }
};
*/
/*
class Exception:public std::exception{

public:
    bool checkInputOfPlayers(int numOfPlayers);
    bool checkNameAndJob(std::string name,std::string job)
    bool charCheker(std::string name);
    bool validCardCheck(std::string Card);

};

<<<<<<< HEAD
bool Exception::charCheker(std::string name)
=======
class DeckFileNotFound:public Exception
>>>>>>> ecdb3b5d4455f5dcecbf5a802e6bcc54006fd2a9
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

bool Exception::checkInputOfPlayers(int numOfPlayers)
{
    if(numOfPlayers>=2 && numOfPlayers<=6)
    {
        return true;
    }
    return false;

}
bool Exception::checkNameAndJob(std::string name,std::string job)
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

<<<<<<< HEAD
bool Exception::validCardCheck(std::string card) {
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

bool Exception::charCheker(std::string name)
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

 bool Exception::checkInputOfPlayers(int numOfPlayers)
{
    if(numOfPlayers>=2 && numOfPlayers<=6)
    {
        return true;
    }
    return false;

}
 bool Exception::checkNameAndJob(std::string name,std::string job)
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

bool Exception::validCardCheck(std::string card) {
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
#endif //EX4_EXCEPTION_H