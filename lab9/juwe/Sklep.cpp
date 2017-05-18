//
// Created by usuryjskij on 18.05.17.
//

#include "Sklep.h"
#include <ctime>


Sklep::Sklep() {
    Piwo piwo;
    TanieWino winko;
    Tymbark tymbark;
    Woda woda;
    Wodka wodka;
    asortyment_.push_back(piwo);
    asortyment_.push_back(winko);
    asortyment_.push_back(tymbark);
    asortyment_.push_back(woda);
    asortyment_.push_back(wodka);
    srand(time(NULL));

}

Sklep::~Sklep() {

}

Prowiant Sklep::Wystaw() {
    int los = std::rand()%5;
    return this->asortyment_[los];
}
