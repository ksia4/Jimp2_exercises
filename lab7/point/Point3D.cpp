//
// Created by usuryjskij on 26.04.17.
//

#include "Point3D.h"
#include <Point.h>
#include <cmath>
#include <iostream>

Point3D::Point3D(double x, double y, double z): Point(x,y) {
    z_ = z;
    std::cout << "Tu konstruktor parametrowy Point 3D" << std::endl;
}

Point3D::Point3D(): z_(0) {
    std::cout << "Tu konstruktor bezparametrowy Point 3D" << std::endl;
}

Point3D::~Point3D() {
    std::cout << "Tu destruktor Point 3D" << std::endl;
}

double Point3D::GetZ() const{
    return z_;
}

double Point3D::Distance(const Point3D &other) const {
    return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2)+pow(GetZ()-other.GetZ(),2));
}

void Point3D::SetZ(double z) {
    z_ = z;

}
