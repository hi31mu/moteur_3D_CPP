#include "point.hpp"

Point::Point(){}

Point::Point(Point3D *p1, Point2D *p2){
    pos3D = p1;
    pos2D = p2;
}

Point::Point(double _x3D, double _y3D, double _z3D, double _x2, double _y2, double _dist){
    pos3D = new Point3D(_x3D, _y3D, _z3D);
    pos2D = new Point2D(_x2, _y2, _dist);
}

Point::~Point(){
    pos2D->~Point2D();
    pos3D->~Point3D();

    //delete pos2D;
    //delete pos3D;

    pos2D = 0;
    pos3D = 0;
}

void Point::set2D(double _x2D, double _y2D, double _dist){
    pos2D->setX(_x2D);
    pos2D->setY(_y2D);

    pos2D->setDist(_dist);
}

void Point::set3D(double _x3D, double _y3D, double _z3D){
    pos3D->setX(_x3D);
    pos3D->setY(_y3D);
    pos3D->setZ(_z3D);
}

void Point::operator=(Point rhs){
    pos2D = new Point2D(rhs.getX2D(), rhs.getY2D());
    pos3D = new Point3D(rhs.getX3D(), rhs.getY3D(), rhs.getZ3D());
}

double Point::getX3D() const{ return pos3D->getX(); }

double Point::getY3D() const{ return pos3D->getY(); }

double Point::getZ3D() const{ return pos3D->getZ(); }

double Point::getX2D() const{ return pos2D->getX(); }

double Point::getY2D() const{ return pos2D->getY(); }

double Point::getDist() const{ return pos2D->getDist(); }
