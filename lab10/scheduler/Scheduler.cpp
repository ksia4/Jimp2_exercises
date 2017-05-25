//
// Created by kasia on 23.05.17.
//


#include "Scheduler.h"

//---------ScheduleItem----------
academia::SchedulingItem::SchedulingItem(int course, int teacher, int room, int time_slot, int year) {
    course_id_ = course;
    teacher_id_ = teacher;
    room_id_ = room;
    time_slot_ = time_slot;
    year_ = year;
}

academia::SchedulingItem::~SchedulingItem() {}

int academia::SchedulingItem::TeacherId() const {
    return teacher_id_;
}

int academia::SchedulingItem::RoomId() const {
    return room_id_;
}

int academia::SchedulingItem::Year() const {
    return year_;
}

int academia::SchedulingItem::CourseId() const {
    return course_id_;
}

int academia::SchedulingItem::TimeSlot() const {
    return time_slot_;
}

//----------Schedule----------
academia::Schedule::Schedule() {}

academia::Schedule::~Schedule() {}

academia::Schedule::Schedule(std::vector<academia::SchedulingItem> item) {
    items_ = item;
}

academia::Schedule academia::Schedule::OfTeacher(int teacher_id) const {
    Schedule tmp ;

    for(int rewrite=0; rewrite<items_.size(); rewrite++ ){
        if(items_[rewrite].teacher_id_ == teacher_id)
            tmp.items_.emplace_back(items_[rewrite]);
    }
    return tmp;
}

academia::Schedule academia::Schedule::OfRoom(int room_id) const {
    Schedule tmp ;

    for(int rewrite=0; rewrite<items_.size(); rewrite++ ){
        if(items_[rewrite].room_id_ == room_id)
            tmp.items_.emplace_back(items_[rewrite]);
    }
    return tmp;
}

academia::Schedule academia::Schedule::OfYear(int year) const {
    Schedule tmp ;

    for(int rewrite=0; rewrite<items_.size(); rewrite++ ){
        if(items_[rewrite].year_ == year)
            tmp.items_.emplace_back(items_[rewrite]);
    }
    return tmp;
}

std::vector<int> academia::Schedule::AvailableTimeSlots(int n_time_slots) const {
    std::vector<int> temp;
    for(int i = 1; i <= n_time_slots; i++){
        int czy = 0;
        for(int j = 0; j<items_.size(); ++j){
            if(items_[j].time_slot_ == i) {
                ++czy;
            }
        }
        if(czy == 0)
            temp.push_back(i);
    }
    return temp;
}

void academia::Schedule::InsertScheduleItem(const academia::SchedulingItem &item) {
    items_.push_back(item);
}

unsigned long academia::Schedule::Size() const {
    return items_.size();
}

academia::SchedulingItem academia::Schedule::operator[](int i) const {
    return items_[i];
}

//----------Scheduler----------

academia::Schedule academia::Scheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                           const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                           const std::map<int, std::set<int>> &courses_of_year,
                                                           int n_time_slots) {
    return academia::Schedule();
}


//-----------GreedyScheduler-----------

academia::Schedule academia::GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                                int n_time_slots) {
    int subjects = 0;
    std::vector <int> teachers;
    std::vector <SchedulingItem> item; //new plan's vector
    for(auto n : teacher_courses_assignment){
        if(n_time_slots < n.second.size()) //if there is more subject for one teacher than slots it is impossiible to make schedule
            throw NoViableSolutionFound();
        subjects+=n.second.size();
        teachers.push_back(n.first);
    }
    for(auto for_one_yer : courses_of_year){
        if(n_time_slots < for_one_yer.second.size()) //if there is more subject for one year than slots it is impossiible to make schedule
            throw NoViableSolutionFound();
    }
    if(subjects > rooms.size()*n_time_slots)//if more subjects than rooms -> NoViableSolutionFound()
        throw NoViableSolutionFound();
    //create schedule
    int norooms = 0; //number of used rooms
    int koniec_pokoju = 0;
    for(auto teache_iterator : teacher_courses_assignment){ //teache_iterator - teachers' iterator
        for(auto courses_iterator : teache_iterator.second){ //courses_iterator - courses' iterator
            int year = 0;
            for(auto l : courses_of_year){ // l - years' iterator
                if ( std::find(l.second.begin(), l.second.end(), courses_iterator) != l.second.end() ) {
                    year = l.first;
                    break;
                }
            }
            if(koniec_pokoju == n_time_slots-1){
                koniec_pokoju = 0;
                ++norooms;
            }
            else
                ++koniec_pokoju;

            SchedulingItem new_item(courses_iterator,teache_iterator.first,rooms[norooms],koniec_pokoju+1,year);
            item.push_back(new_item);
        }
    }
    //------check multilocation------
    for(int i = 0; i<item.size(); ++i){
        for(int j = 0; j<item.size(); ++j){
            if(item[i].year_ == item[j].year_ && item[i].time_slot_ == item[j].time_slot_ && item[i].room_id_ != item[j].room_id_){
                throw NoViableSolutionFound();
            }
        }
    }

    return academia::Schedule(item);
}