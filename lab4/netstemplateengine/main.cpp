//
// Created by kasia on 25.03.17.
//

#include<iostream>
#include<regex>

int main(){
    std::regex podstaw {R"(\w+)"};
    std::string test = "blabla cokolwiek";
    std::smatch matches;
    if(std::regex_match(test, matches, podstaw)){
        std::cout<<test;
    }

    return 0;
}