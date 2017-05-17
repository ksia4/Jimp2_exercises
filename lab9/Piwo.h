//
// Created by klesjaku on 09.05.17.
//

#ifndef JIMP_EXERCISES_PIWO_H
#define JIMP_EXERCISES_PIWO_H

#include <Prowiant.h>

class Piwo: public Prowiant{
    Piwo(int pojemnosc, float procenty, float masaalko):Prowiant(pojemnosc, procenty, masaalko){};
    Piwo():Prowiant(500,5,18){};
};

#endif //JIMP_EXERCISES_PIWO_H
