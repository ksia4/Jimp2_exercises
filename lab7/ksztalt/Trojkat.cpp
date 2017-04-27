//
// Created by Kasia i Kuba on 27.04.17.
//

#include "Trojkat.h"

Trojkat::Trojkat() {
    bok_ = 2;
}

Trojkat::Trojkat(int bok) {
    bok_ = bok;
}

Trojkat::~Trojkat() {

}

void Trojkat::rysuj() {
    for(int i = 0 ; i<bok_ ; ++i){
        for(int j = 0 ; j<bok_ ; ++j){
            if(j==0 || j == i || i ==bok_-1){
                std::cout<<"* ";
            }
            else
                std::cout<<"  ";
        }
        std::cout<<std::endl;
    }

}
