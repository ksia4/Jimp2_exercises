//
// Created by klesjaku on 09.05.17.
//

#ifndef JIMP_EXERCISES_PROWIANT_H
#define JIMP_EXERCISES_PROWIANT_H

class Prowiant{
public:
    //pojemnosc, procenty
    Prowiant();
    Prowiant(int pojemnosc, int procenty, float masaalko);
    ~Prowiant();

    int pojemnosc_;
    int procenty_;
    float masaalko_;

};
#endif //JIMP_EXERCISES_PROWIANT_H
