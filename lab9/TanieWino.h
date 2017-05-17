//
// Created by klesjaku on 09.05.17.
//

#ifndef JIMP_EXERCISES_TANIEWINO_H
#define JIMP_EXERCISES_TANIEWINO_H

#include <Prowiant.h>

class TanieWino: public Prowiant{
    TanieWino(int pojemnosc, float procenty, float masaalko):Prowiant(pojemnosc, procenty,masaalko){};
    TanieWino():Prowiant(1000,15,96){};
};

#endif //JIMP_EXERCISES_TANIEWINO_H
