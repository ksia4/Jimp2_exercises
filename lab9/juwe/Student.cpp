//
// Created by usuryjskij on 18.05.17.
//

#include "Student.h"
#include <iostream>
#include <Plecak.h>

Student::Student() {
    double death = 0.5; //0,5 to wg Wikipedii dawka smiertelna, ale przeciez sa juwenalia :)
    int hours = 12;
    masa_ = 70;
    mozliwosci_ =(((0.017*hours)+death)*0.58*masa_)*10/(0.806*1.2);
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
    int piwa = 0;
    int wina = 0;
    int wodki = 0;
    int bezalko = 0;
    std::vector<Prowiant> posortowany;

    for(auto n : wszystko->picie_){
        if(n.procenty_ == 5)
            piwa +=1;
        else if(n.procenty_ == 15)
            wina +=1;
        else if(n.procenty_ == 40)
            wodki +=1;
        else
            bezalko += 1;
    }
    int piwaa = piwa;
    int winaa = wina;
    int wodkia = wodki;
    int bezalkoa = bezalko;
    int alles = piwa + wina + wodki + bezalko;
    Prowiant tab[20];
    for(auto n : wszystko->picie_){
        switch (n.procenty_){
            case 5:
                tab[piwa-1] = n;
                piwa--;
                break;
            case 15:
                tab[piwaa+wina-1] = n;
                wina--;
                break;
            case 40:
                tab[piwaa+winaa+wodki-1] = n;
                wodki--;
                break;
            case 0:
                tab[piwaa+winaa+wodkia+bezalko-1] = n;
                bezalko--;
                break;
        }
    }
    for(int i=0 ; i<alles ; ++i){
        posortowany.push_back(tab[i]);
    }
    wszystko->picie_ = posortowany;

}
