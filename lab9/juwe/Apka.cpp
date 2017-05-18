//
// Created by usuryjskij on 18.05.17.
//

#include "Apka.h"

Apka::Apka() {
    czteropak = false;
    piw = 0;

    wodeczka = false;
    wodka = 0;

    awaryjne = false;
    awaryjne_piwka = 0;




}

Apka::~Apka() {

}

bool Apka::Decyzja(Plecak *plecak, Student *student, Prowiant *towar) {
    /* Zakladamy ze porzadny student nie pokazuje sie na miasteczku w juwenalia bez czteropaku i
     * dwoch flaszek. Jest to minimum, ktore powinien miec w swoim plecaku. Reszta jego zawartosci
     * bedzie zalezec od jego mozliwosci.
     * Po osiagnieciu pelni szczescia, czyli maksymalmej dawki jaka moze przyjac student, aplikacja
     * pozwala mu na kupno jeszcze 4 dodatkowych piw - jedno awaryjne dla kolegi, ktoremu
     * przedwczesnie skonczyl sie alkohol, drugie dla przypadkowo spotkanego kolegi/prowadzacego,
     * ktoremu TRZEBA postawic piwo i dwa na ciezki poranek...
     */
    if(plecak->artefakty_+towar->pojemnosc_ > plecak->objetosc_){
        return false; // pojemnosc kolejnego towaru nie moze przektoczyc pojemosci plecaka
    }
    else if (plecak->dawka_>student->mozliwosci_ && towar->procenty_ == 0){
        return true; //jesli ilosc alkoholu jest juz wystarczjaca, to warto uzupelnic przestrzen w plecaku woda i soczkiem
    }
    else if(towar->procenty_ == 5 && !czteropak){
        piw +=1;
        if(piw == 4)
            czteropak = true; // czteropak osiagniety!
        return true;
    }
    else if(towar->procenty_ == 40 && !wodeczka){
        wodka +=1;
        if(wodka == 2)
            wodeczka = true; // dwie flaszki juz sa!
        return true;
    }
    else if(student->mozliwosci_-plecak->dawka_ <=40 && towar->procenty_ == 5 && !awaryjne){
        awaryjne_piwka +=1;
        if(awaryjne_piwka == 4)
            awaryjne = true;
        return true; // cztery piwka awaryjne o ktorych wspomnielismy wyzej
    }
    else if(towar->masaalko_ > student->mozliwosci_-plecak->dawka_){
        return false;  // alkoholu juz wystarczy, aby student sam doszedl do domu
    }

}
