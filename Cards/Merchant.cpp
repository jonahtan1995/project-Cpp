#include "Merchant.h"

static const int NO_ACTION = 0;
static const int HP = 1;
static const int POWER = 2;
static const int FORCE = 1;

static const int HP_COST = 5;
static const int POWER_COST = 10;

Merchant::Merchant() : Card("Merchant"),m_buff(FORCE),m_hp(HP){}

void Merchant::applyEncounter(Player &player) const {
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    std::string request;
    int requestNum;
    while(true){
        std::getline(std::cin, request);
        requestNum = std::stoi(request);
        if(requestNum == NO_ACTION || requestNum == HP || requestNum == POWER){
            break;
        }
        printInvalidInput();
    }

    if(requestNum == NO_ACTION){
        printMerchantSummary(std::cout, player.getName(), 0, 0);
        return;
    }

    if(requestNum == HP){
        if(player.pay(HP_COST)){
            player.heal(m_hp);
            printMerchantSummary(std::cout, player.getName(), HP, HP_COST);
            return;
        }
        else{
            printMerchantInsufficientCoins(std::cout);
            return;
        }
    }

    if(player.pay(POWER_COST)){
        player.buff(m_buff);
        printMerchantSummary(std::cout, player.getName(), POWER, POWER_COST);
        return;
    }
    else{
        printMerchantInsufficientCoins(std::cout);
        return;
    }
}

