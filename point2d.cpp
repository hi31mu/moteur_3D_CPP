#include "point2d.hpp"

Point2D::Point2D(){}

Point2D::Point2D(double _x, double _y, double _dist){
    x = _x;
    y = _y;
    dist = _dist;
}

Point2D::~Point2D(){}

double Point2D::getX() const{ return x; }

double Point2D::getY() const{ return y; }

double Point2D::getDist() const{ return dist; }

void Point2D::operator=(Point2D rhs){
    x = rhs.getX();
    y = rhs.getY();
}

void Point2D::setX(double _x){
    x = _x;
}

void Point2D::setY(double _y){
    y = _y;
}

void Point2D::setDist(double _dist){
    dist = _dist;
}
