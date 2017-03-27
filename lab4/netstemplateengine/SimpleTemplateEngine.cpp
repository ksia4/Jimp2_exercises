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
        int napis_len;
        double roznica = 0;
        int last_beg;
        std::string newtext = text_;
        std::vector<int> zmienione;
        bool achtung = true;
        for(const auto & mapel : model) {
            std::string help = "";
            int beg = 0;
            int end = 0;
            achtung = true;
            for (int i = 0; i < newtext.length(); ++i) {
                for(auto k : zmienione){
                    if(k>last_beg)
                        zmienione[0] = k + roznica;
                }
                last_beg = 999;
                roznica = 0;
                if (newtext[i] == '{' && newtext[i + 1] == '{' && newtext[i + 2] != '{') {
                    beg = i;
                    achtung = true;
                    for(auto j : zmienione){
                        if(j == beg)
                            achtung = false;
                    }
                }
                if (newtext[i] == '}' && newtext[i - 1] == '}' && newtext[i - 2] != '}') {
                    end = i;
                }
                if (end > beg && achtung == true) {
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
                    napis_len = newtext.length();
                    newtext.erase(beg, end - beg + 1);
                    newtext.insert(beg, mapel.second);
                    last_beg = beg;
                    zmienione.push_back(beg);
                    help = "";
                    roznica = newtext.length()- napis_len;
                }



            }
        }
        int beg = 0;
        int end = 0;
        for (int i = 0; i < newtext.length(); ++i) {
            if (newtext[i] == '{' && newtext[i + 1] == '{' && newtext[i + 2] != '{') {
                beg = i;
                achtung = true;
                for(auto j : zmienione) {
                    if (j == beg)
                        achtung = false;
                }
            }
            if (newtext[i] == '}' && newtext[i - 1] == '}' && newtext[i - 2] != '}') {
                end = i;
            }
            if (end > beg) {
                for (int i = beg + 2; i <= end - 2; ++i) {
                    if (newtext[i] == ' ') {
                        end = 0;
                        beg = 0;
                        break;
                    }
                }
            }
            if(end > beg && achtung != false){
                newtext.erase(beg, end - beg + 1);
                beg = 0;
                end = 0;
            }
        }
        return newtext;
    }


}
