#ifndef POINT_HPP
#define POINT_HPP

#include "point2d.hpp"
#include "point3d.hpp"

class Point
{
public:
    Point();
    Point(Point3D* p1, Point2D* p2);
    Point(double _x, double _y, double _z, double _x2 = 0.0, double _y2 = 0.0, double _dist = -1.0);
    ~Point();

    void set3D(double _x3D, double _y3D, double _z3D);
    void set2D(double _x2, double _y2, double _dis);

    void operator=(Point rhs);

    double getX3D() const;
    double getY3D() const;
    double getZ3D() const;

    double getX2D() const;
    double getY2D() const;

    double getDist() const;

private:
    Point3D* pos3D=0;
    Point2D* pos2D=0;
};

#endif // POINT_HPP
