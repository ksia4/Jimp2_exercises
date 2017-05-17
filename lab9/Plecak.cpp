//
// Created by klesjaku on 09.05.17.
//

#include "Plecak.h"

Plecak::Plecak() {
    objetosc_ = 10000;
    dawka_ = 0;
    artefakty_ = 0;

}

Plecak::Plecak(int objetosc) {
    objetosc_ = objetosc;
    dawka_ = 0;
    artefakty_ = 0;

}

Plecak::~Plecak() {

}

bool Plecak::wybor(Prowiant butelka) {
    if(artefakty_+butelka.pojemnosc_ > objetosc_){
        return false;
    }
    if // sprawdzanie dawki alko

}
