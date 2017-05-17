//
// Created by klesjaku on 09.05.17.
//

#ifndef JIMP_EXERCISES_PLECAK_H
#define JIMP_EXERCISES_PLECAK_H

#include <vector>
#include <Prowiant.h>
class Plecak{
public:
    Plecak();
    Plecak(int objetosc);
    ~Plecak();
    bool wybor(Prowiant butelka);

private:
    std::vector<Prowiant> picie_;
    int objetosc_;
    int artefakty_;
    int dawka_;
    int maxdawka_ = 500;

};
#endif //JIMP_EXERCISES_PLECAK_H
