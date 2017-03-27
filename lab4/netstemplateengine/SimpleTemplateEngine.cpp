//
// Created by kasia on 25.03.17.
//

#include "SimpleTemplateEngine.h"
#include <string>
#include <unordered_map>
#include <regex>
#include<iostream>

namespace nets{
    View::View() {

    }

    View::View(std::string text) {
        text_ = text;
    }

    View::~View() {

    }

    std::string View::Render(const std::unordered_map<std::string, std::string> &model) const {

        std::regex wzor ("\\{{2}([^{}]{1,})\\}{2}");
        std::smatch matches;
        std::string newtext = text_;
        int wons = -1;
        for(const auto & mapel : model) {
            std::string help = "";
            int beg = 0;
            int end = 0;
            for (int i = 0; i < newtext.length(); ++i) {
                if (newtext[i] == '{' && newtext[i + 1] == '{' && newtext[i + 2] != '{' && i!=wons) {
                    std::cout<<"bo wons wynosi: "<<wons<<std::endl;
                    beg = i;
                }
                if (newtext[i] == '}' && newtext[i - 1] == '}' && newtext[i - 2] != '}') {
                    end = i;
                }
                if (end > beg) {
                    help = "";
                    for (int i = beg + 2; i <= end - 2; ++i) {
                        if (newtext[i] == ' ') {
                            end = 0;
                            beg = 0;
                            help = "";
                            break;
                        }
                        else{
                            help = help + newtext[i];
                        }
                    }
                }
                if(end > beg && help == mapel.first){
                    for(int i =0; i<end - beg + 1; ++i){
                    }
                    newtext.erase(beg, end - beg + 1);
                    newtext.insert(beg, mapel.second);
                    help = "";
                    wons = beg;
                    std::cout<<"Ustawilem wonsa na: "<<wons<<std::endl;
                }



            }
            std::cout << "A to jest aktualny tekst: " << newtext << std::endl;
        }
        std::cout<<"dla upewnienia nasz tekst: "<<newtext << std::endl;
        int beg = 0;
        int end = 0;
        for (int i = 0; i < newtext.length(); ++i) {
            if (newtext[i] == '{' && newtext[i + 1] == '{' && newtext[i + 2] != '{') {
                beg = i;
                std::cout<<"Znalazlem poczatek! beg = "<<beg<<std::endl;
            }
            if (newtext[i] == '}' && newtext[i - 1] == '}' && newtext[i - 2] != '}') {
                end = i;
                std::cout<<"Znalazlem koniec! end = "<<end<<std::endl;
            }
            if (end > beg) {
                std::cout<<"Sprawdzam co ma w srodku"<<std::endl;
                for (int i = beg + 2; i <= end - 2; ++i) {
                    if (newtext[i] == ' ') {
                        end = 0;
                        beg = 0;
                        std::cout<<"O nie! to spacja. Ustawilem end = "<<end<<" i beg = "<<beg<<std::endl;
                        break;
                    }
                }
            }
            if(end > beg){
                std::cout<<"Teraz wytne od "<<beg<<"o tyle znakow "<<end-beg+1<<std::endl;
                newtext.erase(beg, end - beg + 1);
                beg = 0;
                end = 0;
                std::cout<<"Wyciolem! to ja: "<<newtext<<std::endl;
            }
        }
        return newtext;
    }


}
