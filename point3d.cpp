#include "point3d.hpp"

Point3D::Point3D(){}

Point3D::Point3D(double _x, double _y, double _z){
    x = _x;
    y = _y;
    z = _z;
}

Point3D::~Point3D(){}

double Point3D::getX() const{ return x; }

double Point3D::getY() const{ return y; }

double Point3D::getZ() const{ return z; }

void Point3D::setX(double _x){
    x = _x;
}

void Point3D::setY(double _y){
    y = _y;
}

void Point3D::setZ(double _z){
    z = _z;
}
