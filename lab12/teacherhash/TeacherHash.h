//
// Created by usuryjskij on 09.06.17.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <string>

namespace academia{
    class TeacherId{
    public:
        TeacherId();
        TeacherId(int id);
        ~TeacherId();
        operator int() const{return id_;}
    private:
        int id_;
    };

    class Teacher{
    public:
        Teacher();
        Teacher(const TeacherId &id, std::string name, std::string dep);
        ~Teacher();
        TeacherId Id() const;
        std::string Name() const;
        std::string Department() const;

        bool operator==(const Teacher &teach2) const;
        bool operator!=(const Teacher &teach2) const;

    private:
        TeacherId id_;
        std::string name_;
        std::string dep_;

    };



    struct TeacherHash {
    public:
        std::size_t operator()(const Teacher &x) const
        {
            return std::hash<int>()(x.Id()) ^ std::hash<std::string>()(x.Name()) ^ std::hash<std::string>()(x.Department());
        }
    };
}

#endif //JIMP_EXERCISES_TEACHERHASH_H
