#ifndef EDGE_HPP
#define EDGE_HPP

#include "point.hpp"

class Edge{
public:
    Edge();
    Edge(Point* _p1, Point* _p2);

    double getP1X() const;
    double getP2X() const;
    double getP1Y() const;
    double getP2Y() const;
private:
    Point* p1;
    Point* p2;
};

#endif // EDGE_HPP
