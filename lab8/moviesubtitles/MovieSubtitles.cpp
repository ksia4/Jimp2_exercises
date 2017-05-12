//
// Created by Kasia i Kuba on 10.05.17.
//

#include "MovieSubtitles.h"
#include <iostream>
#include <sstream>

moviesubs::MicroDvdSubtitles::MicroDvdSubtitles() {

}

moviesubs::MicroDvdSubtitles::~MicroDvdSubtitles() {

}

void moviesubs::MicroDvdSubtitles::ShiftAllSubtitlesBy(int ms, int fps, std::stringstream *in, std::stringstream *out) {
    int offset = static_cast<int>(floor((static_cast<double>(ms)/1000)*fps));

    bool ok = false;
    std::string empty = "";
    std::string Kasia = in->str();
    if(fps<0)
        throw NegativeFrameRateThrowsIlegalArgument(Kasia);
    for(int i = 0 ; i<Kasia.length();++i){
        if(Kasia[i] == '\n'){
            if(ok){
                ok = false;
            }
            else
                throw InvalidSubtitleLineFormat(Kasia);
        }
        if(Kasia[i] == '{'){
            int ile = sprawdz(Kasia,i);


            if(ile){
                ok = true;
                std::string Mis = zmien(Kasia,i,offset);
                empty = empty + Mis ;
                i+=ile;
                continue;
            }
            else{
                empty += Kasia[i];

            }
        }
        else{
            empty += Kasia[i];

        }
    }
    *out << empty;

}

int moviesubs::MicroDvdSubtitles::sprawdz(std::string Kasia, int i) {
    ++i;
    int wynik=0;
    while(Kasia[i]>='0' && Kasia[i]<='9'){
        wynik++;
        i++;
    }
    if(Kasia[i] != '}'){
        return 0;
    }
    if(Kasia[i+1] == '{' && Kasia[i+2]=='}')
        throw InvalidSubtitleLineFormat(Kasia);
    ++i;
    ++wynik;
    if(Kasia[i] != '{'){
        return 0;
    }
    ++wynik;
    ++i;
    while(Kasia[i]>='0' && Kasia[i]<='9'){
        ++i;
        ++wynik;
    }
    if(Kasia[i] != '}'){
        return 0;
    }
    ++wynik;
    return wynik;

    return 0;
}

std::string moviesubs::MicroDvdSubtitles::zmien(std::string Kasia, int i, int offset) {
    std::string wynik = "{";
    std::string temp = "";
    std::stringstream conv2;
    int dodatnik;
    int pocz = 0;
    int konc = 0;
    i++;
    while(Kasia[i]!='}'){
        temp = temp + Kasia [i];
        i++;
    }
    std::istringstream conv1(temp);
    conv1 >> dodatnik;
    pocz = dodatnik;
    dodatnik += offset;
    if(dodatnik<0){
        throw NegativeFrameAfterShift(Kasia);
    }
    conv2 << dodatnik;
    wynik = wynik + conv2.str();
    conv2.str("");
    wynik = wynik + "}{";
    i +=2;
    temp = "";
    dodatnik = 0;
    while(Kasia[i]!='}'){
        temp = temp + Kasia [i];
        i++;
    }
    std::istringstream conv3(temp);
    conv3 >> dodatnik;
    konc = dodatnik;
    if(pocz>=konc){
        throw SubtitleEndBeforeStart(Kasia);
    }
    dodatnik += offset;
    conv2 << dodatnik;
    wynik = wynik + conv2.str();
    conv2.str("");

    wynik = wynik + "}";


    return wynik;
}


moviesubs::InvalidSubtitleLineFormat::~InvalidSubtitleLineFormat() {

}


moviesubs::NegativeFrameAfterShift::~NegativeFrameAfterShift() {

}


moviesubs::SubtitleEndBeforeStart::~SubtitleEndBeforeStart() {

}

int moviesubs::SubtitleEndBeforeStart::LineAt() const{
    return 2;
}
