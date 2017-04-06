//
// Created by Kasia i Kuba on 28.03.17.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include<vector>
#include <iostream>

namespace pool{
    class TextPool{

    public:
        TextPool();
        TextPool(TextPool &&Tpool);
        TextPool(const TextPool &TPool) = delete;
        TextPool & operator=(const TextPool &TPool) = delete;
        TextPool & operator=(TextPool &&Tpool);
        ~TextPool();
        TextPool(const std::initializer_list<std::string> &element) : subtitles_(element){
            for(int i = 0 ; i<subtitles_.size()-1;i++){
                for(int j = i+1 ; j<subtitles_.size() ; j++){
                    if(subtitles_[i] == subtitles_[j]){
                        subtitles_.erase(subtitles_.begin()+j);
                        --j;
                    }
                }
            }
        }
        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;

    private:
        std::vector<std::string> subtitles_;
    };
}
#endif //JIMP_EXERCISES_TEXTPOOL_H
