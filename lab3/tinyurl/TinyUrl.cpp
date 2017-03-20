//
// Created by Kasia i Kuba on 15.03.17.
//

#include "TinyUrl.h"
#include <utility>
#include <string>
#include <array>
#include <memory>

namespace tinyurl {

    std::unique_ptr<TinyUrlCodec> Init(){
        TinyUrlCodec Linki;
        for(int i = 0; i<6; ++i){
            Linki.hash[i] = 48;
        }
        auto ret = std::make_unique<TinyUrlCodec>(Linki);
        return ret;
    }

    void NextHash(std::array<char, 6> *state){
        std::array<char,6> temp = *state;
        bool nextchar = true;
        int i = 5;
        while(nextchar){
            if((temp[i]>=48 && temp[i]<57) || (temp[i]>=65 && temp[i]<90) || (temp[i]>=97 && temp[i]<122)){
                temp[i] = temp[i] + 1;
                nextchar = false;
            }
            else if(temp[i] == 122){
                temp[i] = 48;
                i--;
            }
            else if(temp[i] == 57){
                temp[i] = temp[i] + 8;
                nextchar = false;
            }
            else if(temp[i] == 90){
                temp[i] = temp[i] + 7;
                nextchar = false;
            }
        }
        *state = temp;
    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec){
        (*codec)->tab.push_back(url);
        std::array<char,6> code = (*codec)->hash;
        NextHash(&(*codec)->hash);
        std::string scode = "";
        for(int i = 0;i<6;i++)
            scode = scode+code[i];

        return scode;
    }

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash){
        int number = 0;
        int wyniki[6];
        for(int i = 0;i<6;i++){
            if(hash[i]>=48 && hash[i]<=57)
                wyniki[i] = hash[i]-48;
            else if(hash[i]>=65 && hash[i]<=90)
                wyniki[i] = hash[i] - 55;
            else
                wyniki[i] = hash[i]-61;
        }
        number = wyniki[5] + wyniki[4]*62 + wyniki[3]*62*62 + wyniki[2]*62*62*62 + wyniki[1]*62*62*62*62 + wyniki[0]*62*62*62*62*62;
        return codec->tab[number];
    }
}