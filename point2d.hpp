#ifndef POINT2D_HPP
#define POINT2D_HPP

class Point2D
{
public:
    Point2D();
    Point2D(double _x, double _y, double _dist=-1);
    ~Point2D();

    double getX() const;
    double getY() const;

    double getDist() const;

    void setX(double _x);
    void setY(double _y);

    void setDist(double _dist);

    void operator=(Point2D rhs);
private:
    double x, y;
    double dist;
};

#endif // POINT2D_HPP
