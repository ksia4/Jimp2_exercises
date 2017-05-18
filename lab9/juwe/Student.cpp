//
// Created by usuryjskij on 18.05.17.
//

#include "Student.h"
#include <iostream>

Student::Student() {
    double death = 0.5; //0,5 to wg Wikipedii dawka smiertelna, ale przeciez sa juwenalia :)
    int hours = 12;
    masa_ = 70;
    mozliwosci_ =(((0.017*hours)+death)*0.58*masa_)*10/(0.806*1.2);
    std::cout << "Mozliwosci studenta " << mozliwosci_ << " gramow czystego alkoholu" << std::endl;
}

Student::~Student() {

}

void Student::Pakuj(Plecak &plecak, Prowiant &towar) {
    plecak.picie_.push_back(towar);
    plecak.artefakty_ += towar.pojemnosc_;
    if(towar.procenty_ == 40){
        plecak.dawka_ += towar.masaalko_/3;     //student jest kulturalny i bedzie pil wodke z co najmniej czterema swoimi kumplami
    }
    else if(towar.procenty_ == 15){
        plecak.dawka_ += towar.masaalko_/2;     //tanie wino obali ze swoim najlepszym przyjacielem na pol
    }
    else{
        plecak.dawka_ += towar.masaalko_;  // piwami nie dzieli sie z nikim!
    }


}

void Student::Sortuj(Plecak *wszystko) {


}
