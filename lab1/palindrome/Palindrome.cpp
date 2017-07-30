//
// Created by kasia on 05.03.17.
//

#include "Palindrome.h"

#include <algorithm>

bool is_palindrome(std::string str){
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    std::string rev = str;
    std::reverse(rev.begin(), rev.end());
    return str == rev;
}