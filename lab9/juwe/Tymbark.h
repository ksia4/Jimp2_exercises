//
// Created by klesjaku on 09.05.17.
//

#ifndef JIMP_EXERCISES_TYMBARK_H
#define JIMP_EXERCISES_TYMBARK_H

#include <Prowiant.h>

class Tymbark: public Prowiant{
public:
    Tymbark(int pojemnosc, float procenty, float masaalko):Prowiant(pojemnosc, procenty, masaalko){};
    Tymbark():Prowiant(500,0,0){};
};

#endif //JIMP_EXERCISES_TYMBARK_H
