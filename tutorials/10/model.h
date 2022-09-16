#ifndef _MODEL_H_
#define _MODEL_H_

#include "info.h"
#include "view.h"
#include "controller.h"
#include <vector>

class Command;

// A model holds the details of a blackjack game
class Model {
    int currentPlayer;              // who is currently acting?
    int dealerScore;
    std::vector<int> playerScore;
     
    std::vector< Controller* > controllers;
    std::vector< View* > views;

    // Not actually how it works, but enough for our example
    int getCard() {
        return rand() % 10 + 1;
    }

    // Views observe a model
    void notifyViews(const Info &i) {
        for (auto v : views)
            v->notify(i); 
    }

public:
    Model(std::vector<Controller*> c, std::vector<View*> v) : currentPlayer{0},
        dealerScore{0}, controllers{c}, views{v} {
        playerScore.resize(controllers.size());
        for (auto &x : playerScore) x = 0;
    }

    Command *handleInput() {
        return controllers[currentPlayer]->handleInput();
    }

    void hit() {
        int card = getCard();
        playerScore[currentPlayer] += card;
        notifyViews(Info{currentPlayer, card, playerScore[currentPlayer]});
        if (playerScore[currentPlayer] > 21)
            stand();
    }

    void stand() {
        ++currentPlayer;
        if (currentPlayer == controllers.size()) {
            while (dealerScore < 17) {
                int card = getCard();
                dealerScore += card;
                notifyViews(Info{-1, card, dealerScore});
            }
        }
    }

    bool finished() { return currentPlayer == controllers.size(); } 
};

#endif
