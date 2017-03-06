//
// Created by kasia on 05.03.17.
//

#include <iostream>
#include "Palindrome.h"
#include <string.h>

bool is_palindrome(std::string str){

    std::string tmp = "";
    std::string rev = "";
    bool pal = false;
    for(int i = 0; i<str.length(); ++i){
        if(str[i] != ' '){
            tmp += str[i];
        }
    }
    for(int i = 0; i<tmp.length(); ++i){
        if(tmp[i] >= 65 && tmp[i] <= 90){
            tmp[i] += 32;
        }
    }
    for(int i = 0; i < tmp.length(); ++i){
        rev = tmp[i] + rev;
    }
    if(tmp == rev){
        pal = true;
    }

    return pal;
}