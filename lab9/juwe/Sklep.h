//
// Created by usuryjskij on 18.05.17.
//

#ifndef JIMP_EXERCISES_SKLEP_H
#define JIMP_EXERCISES_SKLEP_H

#include <Prowiant.h>
#include <iostream>
#include <vector>
#include <Piwo.h>
#include <TanieWino.h>
#include <Tymbark.h>
#include <Woda.h>
#include <Wodka.h>
#include <cstdlib>

class Sklep{
public:
    Sklep();
    ~Sklep();
    Prowiant Wystaw();
private:
    std::vector<Prowiant> asortyment_;
};

#endif //JIMP_EXERCISES_SKLEP_H
