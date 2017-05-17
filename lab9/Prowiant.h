//
// Created by klesjaku on 09.05.17.
//

#ifndef JIMP_EXERCISES_PROWIANT_H
#define JIMP_EXERCISES_PROWIANT_H

class Prowiant{
public:
    //pojemnosc, procenty
    Prowiant();
    Prowiant(int pojemnosc, float procenty, float masaalko);
    ~Prowiant();

    int pojemnosc_;
    float procenty_;
    float masaalko_;

};
#endif //JIMP_EXERCISES_PROWIANT_H
