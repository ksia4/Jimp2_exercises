//
// Created by Kasia i Kuba on 27.04.17.
//

#ifndef JIMP_EXERCISES_TROJKAT_H
#define JIMP_EXERCISES_TROJKAT_H

#include <iostream>
#include "Ksztalt.h"

class Trojkat: public Ksztalt{
public:
    Trojkat();
    Trojkat(int bok);
    ~Trojkat();
    virtual void rysuj();

private:
    int bok_;
};
#endif //JIMP_EXERCISES_TROJKAT_H
