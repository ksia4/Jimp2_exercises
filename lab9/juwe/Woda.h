//
// Created by klesjaku on 09.05.17.
//

#ifndef JIMP_EXERCISES_WODA_H
#define JIMP_EXERCISES_WODA_H
#include <Prowiant.h>

class Woda: public Prowiant{
public:
    Woda(int pojemnosc, float procenty, float masaalko):Prowiant(pojemnosc, procenty, masaalko){};
    Woda():Prowiant(500,0,0){};
};
#endif //JIMP_EXERCISES_WODA_H
