//
// Created by Kasia i Kuba on 26.04.17.
//

#ifndef JIMP_EXERCISES_POINT3D_H
#define JIMP_EXERCISES_POINT3D_H

#include <Point.h>

class Point3D: public Point{
public:
    Point3D();
    Point3D(double x, double y, double z);
    ~Point3D();

    double GetZ() const;
    void SetZ(double z);

    double Distance(const Point3D &other) const;
private:
    double z_;
};
#endif //JIMP_EXERCISES_POINT3D_H
