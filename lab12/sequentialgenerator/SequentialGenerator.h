//
// Created by usuryjskij on 09.06.17.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H


template <class id, class objtype>
class SequentialIdGenerator {
public:
    SequentialIdGenerator(const objtype &counter = objtype()) : counter_{counter} {}
    id NextValue();
private:
    objtype counter_;
};

template <class IdType, class SimpleType>
IdType SequentialIdGenerator<IdType, SimpleType>::NextValue() {
    IdType newid = IdType(counter_);
    ++counter_;
    return newid;
}


#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
