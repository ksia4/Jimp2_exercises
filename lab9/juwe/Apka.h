//
// Created by usuryjskij on 18.05.17.
//

#ifndef JIMP_EXERCISES_APKA_H
#define JIMP_EXERCISES_APKA_H

#include <Plecak.h>
#include <Student.h>

class Apka{
public:
    Apka();
    ~Apka();
    bool Decyzja(Plecak *plecak, Student *student, Prowiant *towar);
private:
    bool czteropak;
    int piw;
    bool wodeczka;
    int wodka;
    bool awaryjne;
    int awaryjne_piwka;
};
#endif //JIMP_EXERCISES_APKA_H
