//
// Created by kasia on 05.03.17.
// Zadanie - DoublePalindromes - Katarzyna Rugiełło, Jakub Kleszcz
//

#include "DoubleBasePalindromes.h"
#include<iostream>


int doublepalindrome(int value){
    int tmp = value;
    int result = 0;
    std::string bin = "";
    std::string rev = "";
    while(value>0){
        if(value%2 == 1){
            bin = '1' + bin;
        }
        if(value%2 == 0){
            bin = '0' + bin;
        }
        value = (value/2);
    }
    if(bin[bin.length() - 1] == 0){
        result = 0;
    }
    else{
        for(int i = 0; i<bin.length(); ++i){
            rev = bin[i] + rev;
        }
    }

    if(bin == rev && rev != ""){
        result = tmp;
    }

    return result;
}

uint64_t DoubleBasePalindromes(int max_vaule_exculsive){
    uint64_t suma = 0;
    std::string rev = "";
    if(max_vaule_exculsive > 0){
        for(int i = 1; i<= max_vaule_exculsive; ++i){
            if(i%10 == 0){
                continue;
            }
            std::string val = std::to_string(i);
            rev = "";
            for(int i = 0; i<val.length(); ++i){
                rev = val[i] + rev;
            }
            if(rev == val){
                suma += doublepalindrome(i);
            }
        }
    }

    return suma;
}