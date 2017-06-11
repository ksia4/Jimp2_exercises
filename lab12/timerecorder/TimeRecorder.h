//
// Created by usuryjskij on 09.06.17.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <chrono>
#include <utility>

namespace profiling{
    template <class T>
    auto TimeRecorder(T object){

        std::chrono::time_point<std::chrono::system_clock> begin;
        std::chrono::time_point<std::chrono::system_clock> end;

        begin = std::chrono::system_clock::now();
        auto newobject = object();
        end = std::chrono::system_clock::now();

        std::chrono::duration<double, std::milli> time_result = end - begin;
        double res = time_result.count();

        return std::make_pair(newobject, res);
    };
}

#endif //JIMP_EXERCISES_TIMERECORDER_H
