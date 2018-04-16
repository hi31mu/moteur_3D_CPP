#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "point.hpp"

class vector
{
public:
    vector(double _x, double _y);

    double getX() const;
    double getY() const;

    bool isNullVector();
    void operator-=(double x);
    vector operator *(double x);

    Point2D translate(Point2D _input);
private:
    double x, y;
};

#endif // VECTOR_HPP
