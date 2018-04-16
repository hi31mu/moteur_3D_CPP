#include "Polygon.hpp"

Polygon::Polygon(){}

Polygon::Polygon(Point *_p1, Point *_p2, Point *_p3){
    p1 = _p1;
    p2 = _p2;
    p3 = _p3;
}

Point Polygon::getP1() const{ return *p1; }
Point Polygon::getP2() const{ return *p2; }
Point Polygon::getP3() const{ return *p3; }

bool Polygon::printResult() const{ return print; }

void Polygon::setBackFaceResult(bool _print){ print = _print; }
