#ifndef POINT3D_HPP
#define POINT3D_HPP


class Point3D
{
public:
    Point3D();
    Point3D(double _x, double _y, double _z);
    ~Point3D();

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(double _x);
    void setY(double _x);
    void setZ(double _x);
private:
    double x, y, z;
};

#endif // POINT3D_HPP
