//
// Created by klesjaku on 09.05.17.
//

#include "Prowiant.h"

Prowiant::Prowiant() {
    procenty_ = 0;
    pojemnosc_ = 0;
    masaalko_ = 0;
}

Prowiant::Prowiant(int pojemnosc, float procenty, float masaalko) {
    pojemnosc_ = pojemnosc;
    procenty_ = procenty;
    masaalko_ = masaalko;

}

Prowiant::~Prowiant() {

}
