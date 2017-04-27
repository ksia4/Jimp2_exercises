//
// Created by usuryjskij on 27.04.17.
//

#include "Kwadrat.h"
#include <iostream>

Kwadrat::Kwadrat() {
    bok_ = 1;

}

Kwadrat::Kwadrat(int bok) {
    bok_ = bok;

}

Kwadrat::~Kwadrat() {

}

void Kwadrat::rysuj() {
    for(int i = 0 ; i<bok_ ; ++i){
        for(int j = 0 ; j<bok_ ; ++j){
            if(i==0 || i==bok_-1 || j == 0 || j == bok_-1){
                std::cout << "* ";
            }
            else
                std::cout << "  ";
        }
        std::cout<<std::endl;
    }

}
