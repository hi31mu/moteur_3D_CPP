#include "paintcomponent.hpp"

int drawLine(QImage &input, QColor color, Edge segment, double precision){
    int error = 0;

    double facteur = 1.0;
    vector AB(segment.getP2X() - segment.getP1X(), segment.getP2Y() - segment.getP1Y());

    Point2D current(segment.getP1X(), segment.getP1Y());
    while(facteur >= 0){
        if(input.width() > current.getX() && input.height() > current.getY() && -1 < current.getX() && -1 < current.getY())
            input.setPixelColor(std::round(current.getX()), std::round(current.getY()), color);
        facteur -= precision;
        current = (AB * facteur).translate(Point2D(segment.getP1X(), segment.getP1Y()));
    }

    return error;
}

int drawPoint(QImage &input, QColor color, Point2D depart, double size){
    int error = 0;

    for(int i = depart.getX() - size / 2; i < depart.getX() + size / 2; i++)
        for(int j = depart.getY() - size / 2; j < depart.getY() + size / 2; j++)
            if(input.width() > i && input.height() > j && -1 < i && -1 < j)
                input.setPixelColor(i, j, color);

    return error;
}

int drawPolygon(QImage &input, QColor color, Polygon draw, double precision){
    int error = 0;

    Point2D A(draw.getP1().getX2D(), draw.getP1().getY2D());
    Point2D B(draw.getP2().getX2D(), draw.getP2().getY2D());
    Point2D C(draw.getP3().getX2D(), draw.getP3().getY2D());

    double facteur = 1.0;
    vector AB(B.getX() - A.getX(), B.getY() - A.getY());
    vector CB(B.getX() - C.getX(), B.getY() - C.getY());

    Point3D empty(0.0, 0.0, 0.0);

    Point2D current1 = B;
    Point2D current2 = B;
    while(facteur >= 0){
        Point p1 (&empty, &current1);
        Point p2 (&empty, &current2);

        drawLine(input, color, Edge(&p1, &p2));

        facteur -= precision;
        current1 = (AB * facteur).translate(A);
        current2 = (CB * facteur).translate(C);
    }

    draw.~Polygon();
    return error;
}

QColor moyenne(int x, int y, QImage input){
    int pos[8][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-2, 0}, {0, 2}, {2, 0}, {0, -2}};
    int result[4] = {input.pixelColor(x, y).red(), input.pixelColor(x, y).green(), input.pixelColor(x, y).blue(), input.pixelColor(x, y).alpha()};
    int cmpt = 1;
    for(int i=0; i<4; i++){
        int nX = x + pos[i][1], nY = y + pos[i][0];
        if(nX > -1 && nX < input.width() && nY > -1 && nY < input.height()){
            result[0] += input.pixelColor(nX, nY).red();
            result[1] += input.pixelColor(nX, nY).green();
            result[2] += input.pixelColor(nX, nY).blue();
            result[3] += input.pixelColor(nX, nY).alpha();
            cmpt++;
        }
    }

    return QColor(result[0] / cmpt, result[1] / cmpt, result[2] / cmpt, result[3] / cmpt);
}

int antiAliasing(QImage &input){
    int error = 0;
    QImage sv = input;
    for(int i=0; i<input.height(); i++)
        for(int j=0; j<input.width(); j++)
            input.setPixelColor(j, i, moyenne(j, i, sv));

    return error;
}
