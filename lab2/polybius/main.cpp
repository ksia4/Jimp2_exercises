//
// Created by usuryjskij on 07.03.17.
//

#include <iostream>
#include <fstream>
#include "Polybius.h"

int main(int argc, char ** argv){

    char message[256];

    if (argc != 4) {
        std::cout << "Nieprawidlowa liczba argumentow..." << std::endl;
        return 0;
    }
    std::ifstream myfile(argv[1]);
    if(!myfile)
        std::cout << "Nie mozna otworzyc pliku" << std::endl;

    while(!myfile.eof()){
        myfile.getline(message,256);
        if(argv[3] == "0") {
            std::fstream outfile(argv[2], std::ios::out);
            outfile << PolybiusDecrypt(message);
            outfile.close();
        }
        else if (argv[3] == "1") {
            std::fstream outfile(argv[2], std::ios::out);
            outfile << PolybiusCrypt(message);
            outfile.close();
        }
    }
    myfile.close();
    return 0;
}
