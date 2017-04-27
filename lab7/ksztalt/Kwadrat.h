//
// Created by Kasia i Kuba on 27.04.17.
//

#ifndef JIMP_EXERCISES_KWADRAT_H
#define JIMP_EXERCISES_KWADRAT_H

#include <Ksztalt.h>
class Kwadrat: public Ksztalt{
public:
    Kwadrat();
    Kwadrat(int bok);
    ~Kwadrat();
    virtual void rysuj();
private:
    int bok_;
};
#endif //JIMP_EXERCISES_KWADRAT_H
