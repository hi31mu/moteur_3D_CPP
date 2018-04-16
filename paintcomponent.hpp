#ifndef PAINTCOMPONENT_HPP
#define PAINTCOMPONENT_HPP

#include "Polygon.hpp"
#include "vector.hpp"
#include <algorithm>
#include "edge.hpp"
#include <stdio.h>
#include <QImage>
#include <cmath>

const double DEFAULT_PRECISION = 0.0005;

const double DEFAULT_VARIATION_PRECISION = 0.0001;
const double DEFAULT_SIZE = 6.0;

int drawLine(QImage &input, QColor color, Edge segment, double precision = DEFAULT_PRECISION);
int drawPoint(QImage &input, QColor color, Point2D position, double size = DEFAULT_SIZE);
int drawPolygon(QImage &input, QColor color, Polygon draw, double precision = DEFAULT_VARIATION_PRECISION);

int antiAliasing(QImage &input);

#endif // PAINTCOMPONENT_HPP
