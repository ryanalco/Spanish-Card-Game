//
//  cards.cpp
//  HW1-10C
//
//  Created by Ryan Alvarez-Cohen on 10/3/17.
//  Copyright © 2017 Ryan Alvarez-Cohen. All rights reserved.
//

#include "cards.hpp"

#include <cstdlib>
#include <iostream>

Card::Card(){
    int r = 1 + rand() % 4;
    switch (r) {
        case 1: suit = OROS; break;
        case 2: suit = COPAS; break;
        case 3: suit = ESPADAS; break;
        case 4: suit = BASTOS; break;
        default: break;
    }
    
    r = 1 + rand() % 10;
    switch (r) {
        case  1: rank = AS; break;
        case  2: rank = DOS; break;
        case  3: rank = TRES; break;
        case  4: rank = CUATRO; break;
        case  5: rank = CINCO; break;
        case  6: rank = SEIS; break;
        case  7: rank = SIETE; break;
        case  8: rank = SOTA; break;
        case  9: rank = CABALLO; break;
        case 10: rank = REY; break;
        default: break;
    }
}

string Card::get_spanish_suit() const {
    string suitName;
    switch (suit) {
        case OROS:
            suitName = "oros";
            break;
        case COPAS:
            suitName = "copas";
            break;
        case ESPADAS:
            suitName = "espadas";
            break;
        case BASTOS:
            suitName = "bastos";
            break;
        default: break;
    }
    return suitName;
}


string Card::get_spanish_rank() const {
    string rankName;
    switch (rank) {
        case AS:
            rankName = "As";
            break;
        case DOS:
            rankName = "Dos";
            break;
        case TRES:
            rankName = "Tres";
            break;
        case CUATRO:
            rankName = "Cuatro";
            break;
        case CINCO:
            rankName = "Cinco";
            break;
        case SEIS:
            rankName = "Seis";
            break;
        case SIETE:
            rankName = "Siete";
            break;
        case SOTA:
            rankName = "Sota";
            break;
        case CABALLO:
            rankName = "Caballo";
            break; 
        case REY: 
            rankName = "Rey"; 
            break; 
        default: break;
    }
    return rankName;
}


string Card::get_english_suit() const {
    string suitname;
    switch (suit) {
        case OROS:
            suitname = "coins";
            break;
        case COPAS:
            suitname = "cups";
            break;
        case ESPADAS:
            suitname = "spades";
            break;
        case BASTOS:
            suitname = "clubs";
            break;
        default: break;
    }
    return suitname;
}


string Card::get_english_rank() const {
    string rankname;
    switch (rank) {
        case AS:
            rankname = "One";
            break;
        case DOS:
            rankname = "Two";
            break;
        case TRES:
            rankname = "Three";
            break;
        case CUATRO:
            rankname = "Four";
            break;
        case CINCO:
            rankname = "Five";
            break;
        case SEIS:
            rankname = "Six";
            break;
        case SIETE:
            rankname = "Seven";
            break;
        case SOTA:
            rankname = "Jack";
            break;
        case CABALLO:
            rankname = "Queen";
            break;
        case REY:
            rankname = "King";
            break;
        default: break;
    }

    return rankname;
}


double Card::get_rank() const {
    if (((static_cast<int>(rank) + 1) == 8) || ((static_cast<int>(rank) + 1) == 9) || ((static_cast<int>(rank) + 1) == 10)) {
        return .5;
    }
    else {
    return static_cast<int>(rank) + 1 ;
    }
}

bool Card::operator < (Card card2) const {
    return rank < card2.rank;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

Player::Player(int in_money) {
    money = in_money;
}

int Player::get_money() const {
    return money;
}

void Player::increase_money(int bet){
    money += bet;
}

void Player::decrease_money(int bet){
    money -= bet;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

Hand::Hand() {
}

void Hand:: add_card(Card card1) {
    cards.push_back(card1);
}

string Hand:: show_hand() {
    string me = "";
    for (int i = 0; i < cards.size(); i++) {
        cout << cards[i].get_spanish_rank() << " de " << cards[i].get_spanish_suit() << ", ";
    }
    return me;
}

string Hand:: show_last() {
    string show = "";
    cout << cards[cards.size() - 1].get_spanish_rank() << " de " << cards[cards.size() - 1].get_spanish_suit() << " ";
    return show;
}

double Hand:: get_total() {
    double total = 0;
    for (int i = 0; i < cards.size(); i++) {
        total += cards[i].get_rank();
    }
    return total;
}




















