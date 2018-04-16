#include "vector.hpp"

vector::vector(double _x, double _y){
    x = _x;
    y = _y;
}

double vector::getX() const{
    return x;
}

double vector::getY() const{
    return y;
}

bool vector::isNullVector(){
    return (x == 0.0 && y == 0.0);
}

void vector::operator-=(double k){
    x -= k;
    y -= k;
}

vector vector::operator *(double k){
    return vector(x * k, y * k);
}

Point2D vector::translate(Point2D _input){
    return Point2D(_input.getX() + x, _input.getY() + y);
}
