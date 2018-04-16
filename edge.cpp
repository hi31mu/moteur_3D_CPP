#include "edge.hpp"

Edge::Edge(){}

Edge::Edge(Point *_p1, Point *_p2){
    p1 = _p1;
    p2 = _p2;
}


double Edge::getP1X() const{ return p1->getX2D(); }
double Edge::getP1Y() const{ return p1->getY2D(); }

double Edge::getP2X() const{ return p2->getX2D(); }
double Edge::getP2Y() const{ return p2->getY2D(); }
