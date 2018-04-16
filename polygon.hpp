#ifndef POLYGON_HPP
#define POLYGON_HPP

#include "point.hpp"
#include <QImage>

class Polygon{
public:
    Polygon();
    Polygon(Point *_p1, Point *_p2, Point *_p3);

    Point getP1() const;// optimiser pointeurs ?
    Point getP2() const;
    Point getP3() const;

    bool printResult() const;

    void setBackFaceResult(bool _print);
private:
    Point* p1;
    Point* p2;
    Point* p3;
    QImage texture;

    bool print;
};

#endif // POLYGON_HPP
