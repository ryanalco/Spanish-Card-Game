//
//  cards.hpp
//  HW1-10C
//
//  Created by Ryan Alvarez-Cohen on 10/3/17.
//  Copyright © 2017 Ryan Alvarez-Cohen. All rights reserved.
//

#include <string>
#include <vector>
#include <fstream>

#ifndef cards_hpp
#define cards_hpp

#include <stdio.h>

using namespace std;

enum suit_t {OROS, COPAS, ESPADAS, BASTOS};

enum rank_t {AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA=9, CABALLO=10, REY=11};

class Card {
public:
    Card();
    string get_spanish_suit() const;
    string get_spanish_rank() const;
    string get_english_suit() const;
    string get_english_rank() const;
    double get_rank() const;
    bool operator < (Card card2) const;
    
private:
    suit_t suit;
    rank_t rank;
};


class Hand {
public:
    Hand();
    void add_card(Card card);
    string show_hand();
    string show_last();
    double get_total();
private:
    vector<Card> cards;
    
};

class Player{
public:
    Player();
    Player(int m);
    int get_money() const;
    void increase_money(int bet);
    void decrease_money(int bet);
private:
    int money;
};




#endif /* cards_hpp */
