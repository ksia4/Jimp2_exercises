//
// Created by klesjaku on 09.05.17.
//

#ifndef JIMP_EXERCISES_TANIEWINO_H
#define JIMP_EXERCISES_TANIEWINO_H

#include <Prowiant.h>

class TanieWino: public Prowiant{
public:
    TanieWino(int pojemnosc, int procenty, float masaalko):Prowiant(pojemnosc, procenty,masaalko){};
    TanieWino():Prowiant(700,15,67){};
};

#endif //JIMP_EXERCISES_TANIEWINO_H
