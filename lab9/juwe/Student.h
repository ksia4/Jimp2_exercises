//
// Created by usuryjskij on 18.05.17.
//

#ifndef JIMP_EXERCISES_STUDENT_H
#define JIMP_EXERCISES_STUDENT_H

#include <Plecak.h>


class Student{
public:
    Student();
    ~Student();
    void Pakuj(Plecak &plecak, Prowiant &towar);
    void Sortuj(Plecak *wszystko);
    double mozliwosci_;

private:
    int masa_;

};
#endif //JIMP_EXERCISES_STUDENT_H
