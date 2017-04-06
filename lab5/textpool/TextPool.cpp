//
// Created by Kasia i Kuba on 28.03.17.
//

#include "TextPool.h"
#include <iostream>

using namespace pool;

TextPool::TextPool(): subtitles_() {
}

std::experimental::string_view TextPool::Intern(const std::string &str) {
    bool repeat = false;
    std::experimental::string_view tempsub = str;
    for(int i = 0; i<subtitles_.size();i++){
        if(subtitles_[i] == str){
            repeat = true;
            tempsub = subtitles_[i];
            break;
        }
    }
    if(!repeat)
        subtitles_.insert(subtitles_.end(),str);

    return tempsub;
}

size_t TextPool::StoredStringCount() const {
    return subtitles_.size();
}

TextPool::~TextPool() {

}

TextPool::TextPool(TextPool &&Tpool) {
    std::swap(subtitles_, Tpool.subtitles_);

}

TextPool & TextPool::operator=(TextPool &&Tpool) {
    if (this == &Tpool) {
        return *this;
    }
    std::swap(subtitles_, Tpool.subtitles_);
    return *this;
}






