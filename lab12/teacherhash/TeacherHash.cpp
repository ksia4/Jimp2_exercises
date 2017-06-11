//
// Created by usuryjskij on 09.06.17.
//

#include "TeacherHash.h"

academia::TeacherId::TeacherId() {
    id_ = 0;

}

academia::TeacherId::TeacherId(int id) {
    id_ = id;

}

academia::TeacherId::~TeacherId() {

}

academia::Teacher::Teacher() {
    id_ = 0;
    name_ = "";
    dep_ = "";

}

academia::Teacher::Teacher( const academia::TeacherId &id, std::string name, std::string dep) {
    id_ = id;
    name_ = name;
    dep_ = dep;
}

academia::Teacher::~Teacher() {

}

academia::TeacherId academia::Teacher::Id() const {
    return id_;
}

std::string academia::Teacher::Name() const {
    return name_;
}

std::string academia::Teacher::Department() const {
    return dep_;
}

bool academia::Teacher::operator==(const academia::Teacher &teach2) const {
    if(id_ == teach2.id_ && name_ == teach2.name_ && dep_ == teach2.dep_)
        return true;
    else
        return false;
}

bool academia::Teacher::operator!=(const academia::Teacher &teach2) const {
    if(id_ == teach2.id_ && name_ == teach2.name_ && dep_ == teach2.dep_)
        return false;
    else
        return true;
}
