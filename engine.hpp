#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "Edge.hpp"
#include "Polygon.hpp"
#include <cmath>

void calculBase(double camera[]);
void calculPoint(double camera[], Point *p);

double calculAngle(double const& x, double const& y);

double calculAngleReal(double const& x, double const& y);

double calculLength(double const& x, double const& y);// en 2D
double calculLength(double const& x, double const& y, double const& z);//en 3D

void cartRotate(double const& x, double const& y, double const& a, double b[]);

void calculPolygon(double camera[], Polygon *p);

#endif // ENGINE_HPP
