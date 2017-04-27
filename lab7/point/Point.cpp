//
// Created by Kasia i Kuba on 26.04.17.
//

#include "Point.h"
#include <cmath>
#include <iostream>


using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;

Point::Point():x_(0),y_(0){
    std::cout << "Tu konstruktor bezparametrowy Point 2D"<< endl;
}

Point::Point(double x, double y){
    std::cout << "Tu konstruktor parametrowy Point 2D" << endl;
    x_ = x;
    y_ = y;
}

Point::~Point(){
    std::cout << "Tu destruktor Point 2D";
    std::cout << endl;
}

double Point::Distance(const Point &other) const{
    return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));
}


double Point::GetX() const {
    return x_;
}

double Point::GetY() const {
    return y_;
}

void Point::ToString(std::ostream *out) const{
    (*out) << "(" << GetX() << ";" << GetY() << ")";
}

void Point::SetX(double x) {
    x_ = x;

}

void Point::SetY(double y) {
    y_ = y;

}

std::ostream &operator<<(std::ostream &wyjscie, const Point &s) {
    return wyjscie << "Coordinates: (" <<s.GetX() << ", "<< s.GetY() << ")"<<std::endl;;
}
