//
// Created by kasia on 23.05.17.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include<algorithm>
#include<iostream>
#include <vector>
#include <map>
#include <set>

namespace academia{

    //----------single element----------
    class SchedulingItem{
    public:
        SchedulingItem(int course, int teacher, int room, int time_slot, int year);
        ~SchedulingItem();
        int TeacherId() const ;
        int RoomId() const ;
        int Year() const ;
        int CourseId() const ;
        int TimeSlot() const ;

        int course_id_;
        int teacher_id_;
        int room_id_;
        int time_slot_;
        int year_;
    };

    //----------all schedule---------------
    class Schedule{
    public:
        Schedule();
        ~Schedule();
        Schedule (std::vector <SchedulingItem> item);

        Schedule OfTeacher(int teacher_id) const; //returns part of schedules for choosen teacher
        Schedule OfRoom(int room_id) const; //returns part of schedules for choosen room
        Schedule OfYear(int year) const; //returns part of schedules for choosen year
        std::vector<int> AvailableTimeSlots(int n_time_slots) const; //returns vector free tima_slots in schedule
        void InsertScheduleItem(const SchedulingItem &item); //insetrs new element to schedule
        size_t Size() const; //returns schedule's size(number of elements)

        std::vector<SchedulingItem> items_;
        SchedulingItem operator[](int i) const;
    };

    //-----------schedule maker-----------
    class Scheduler{
    public:

        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) = 0;
    /*
    rooms - available rooms
    teacher_courses_assignment - key - teachers' ID, value - their courses
    courses_of_year - key - year, value - their courses
    n_time_slots - number of available slots
    */
    };

    //---------Exception - No solution is available----------
    class NoViableSolutionFound{
    public:

    };

    //---------greedy version of algorithm to make schedule---------
    class GreedyScheduler : public Scheduler{
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots);
    };
}
#endif //JIMP_EXERCISES_SCHEDULER_H
