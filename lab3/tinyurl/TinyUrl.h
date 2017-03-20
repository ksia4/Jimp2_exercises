//
// Created by usuryjskij on 15.03.17.
//

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H
#include <utility>
#include <string>
#include <array>
#include <memory>
#include <vector>
namespace tinyurl{
    //std::pair<std::string, std::array<char,6>> TinyUrlCodec;
    struct TinyUrlCodec{
        std::array<char,6> hash;
        std::vector<std::string> tab;
    };
    std::unique_ptr<TinyUrlCodec> Init();
    void NextHash(std::array<char, 6> *state);
    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);
}
#endif //JIMP_EXERCISES_TINYURL_H
