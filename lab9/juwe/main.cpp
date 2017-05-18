//
// Created by klesjaku on 09.05.17.
//

#include<Student.h>
#include <Sklep.h>
#include <Apka.h>

int main(){
    Student rysiek;
    Plecak torba;
    Sklep lewiatan;
    Apka studentapp;

    for(int i=0 ; i<20 ; i++){
        Prowiant towar = lewiatan.Wystaw();
        if(studentapp.Decyzja(&torba, &rysiek, &towar)){
            rysiek.Pakuj(torba,towar);
        }
    }
    rysiek.Sortuj(&torba);

    for(auto n : torba.picie_){
        std::cout << n.procenty_ << std::endl;
    }

    std::cout << "Objetosc " << torba.artefakty_ << std::endl;
    std::cout << "Alkohol " << torba.dawka_ << std::endl;
    return 0;
}
