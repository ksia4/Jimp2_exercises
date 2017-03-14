//
// Created by usuryjskij on 07.03.17.
//

#include "Polybius.h"
#include <sstream>



std::string PolybiusCrypt(std::string message){
    int buf;
    std::string crypted = "";
    std::stringstream conv;
    char tab[][5] = {{65,66,67,68,69},{70,71,72,73,75},{76,77,78,79,80},{81,82,83,84,85},{86,87,88,89,90}};
    for(int i = 0;i<message.length();i++){
        buf = message[i];
        if(buf == 73 || buf == 74 || buf == 105 || buf == 106){
            crypted = crypted + "24";
            continue;
        }
        else if(buf >= 65 && buf <=90){
            for(int j = 0;j<5;j++){
                for(int k = 0;k<5;k++){
                    if(buf == tab[j][k]){
                        j = j+1;
                        k = k+1;
                        conv << j;
                        crypted = crypted + conv.str();
                        conv.str("");
                        conv << k;
                        crypted = crypted + conv.str();
                        conv.str("");
                    }
                }
            }
        }
        else if(buf >= 97 && buf <=122){
            buf = buf - 32;
            for(int j = 0;j<5;j++){
                for(int k = 0;k<5;k++){
                    if(buf == tab[j][k]){
                        j = j+1;
                        k = k+1;
                        conv << j;
                        crypted = crypted + conv.str();
                        conv.str("");
                        conv << k;
                        crypted = crypted + conv.str();
                        conv.str("");
                    }
                }
            }
        }
    }
    return crypted;
}
std::string PolybiusDecrypt(std::string crypted){
    int wiersz;
    int kolumna;
    char litera;
    char tab[][5] = {{65,66,67,68,69},{70,71,72,73,75},{76,77,78,79,80},{81,82,83,84,85},{86,87,88,89,90}};
    std::string message = "";
    for(int i = 0 ; i < crypted.length()/2 ; i++){

        wiersz = crypted[2*i]-49;
        kolumna = crypted[(2*i)+1]-49;
        litera = (tab[wiersz][kolumna]+32);
        message = message + litera;
    }
    return message;
}
