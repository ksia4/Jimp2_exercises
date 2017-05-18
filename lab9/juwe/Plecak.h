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
    std::vector<Prowiant> picie_;

    int objetosc_; // stale!!!
    int artefakty_;
    int dawka_;

private:

};
#endif //JIMP_EXERCISES_PLECAK_H
