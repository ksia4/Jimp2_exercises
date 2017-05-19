//
// Created by klesjaku on 09.05.17.
//

#ifndef JIMP_EXERCISES_WODKA_H
#define JIMP_EXERCISES_WODKA_H
#include <Prowiant.h>

class Wodka: public Prowiant{
public:
    Wodka(int pojemnosc, int procenty, float masaalko):Prowiant(pojemnosc, procenty,masaalko){};
    Wodka():Prowiant(500,40,160){};
};

#endif //JIMP_EXERCISES_WODKA_H
