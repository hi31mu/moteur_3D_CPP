#include "paintcomponent.cpp"
#include <QApplication>
#include "engine.hpp"
#include <QPixmap>
#include <QWidget>
#include <vector>
#include <QLabel>
#include <QImage>
#include <QColor>
#include <QSize>

void process(QImage &input){
    double size = (input.width() + input.height()) / 2.0;
    double camera[6] = {20.0, 40.0, -80.0, 0.0, 0.0, 0.0};

    std::vector<Point> points;
    std::vector<Edge> edges;
    std::vector<Polygon> polygons;

    points.push_back(Point(0.0, 0.0, 0.0));
    points.push_back(Point(0.0, 0.0, 10.0));
    points.push_back(Point(0.0, 10.0, 0.0));
    points.push_back(Point(0.0, 10.0, 10.0));
    points.push_back(Point(10.0, 0.0, 0.0));
    points.push_back(Point(10.0, 10.0, 0.0));
    points.push_back(Point(10.0, 0.0, 10.0));
    points.push_back(Point(10.0, 10.0, 10.0));

    edges.push_back(Edge(&points[0], &points[4]));
    edges.push_back(Edge(&points[0], &points[2]));
    edges.push_back(Edge(&points[2], &points[5]));
    edges.push_back(Edge(&points[4], &points[5]));

    edges.push_back(Edge(&points[4], &points[6]));
    edges.push_back(Edge(&points[6], &points[7]));
    edges.push_back(Edge(&points[7], &points[5]));

    edges.push_back(Edge(&points[3], &points[2]));
    edges.push_back(Edge(&points[3], &points[7]));

    polygons.push_back(Polygon(&points[3], &points[7], &points[2]));
    polygons.push_back(Polygon(&points[2], &points[7], &points[5]));
    polygons.push_back(Polygon(&points[0], &points[2], &points[4]));
    polygons.push_back(Polygon(&points[5], &points[4], &points[2]));
    polygons.push_back(Polygon(&points[5], &points[7], &points[4]));
    polygons.push_back(Polygon(&points[7], &points[6], &points[4]));

    calculBase(camera);
    for(size_t i=0; i<points.size(); i++){
        calculPoint(camera, &points[i]);
        points[i].set2D(points[i].getX2D() * size + input.width() / 2.0, points[i].getY2D() * size + input.height() / 2.0, points[i].getDist());
    }
    for(size_t i=0; i<polygons.size(); i++){
        calculPolygon(camera, &polygons[i]);
        if(polygons[i].printResult())
            ;//
    }

    for(size_t i=0; i<polygons.size(); i++)
        if(polygons[i].printResult())
            drawPolygon(input, QColor(255, 0, 0), polygons[i]);
    for(size_t i=0; i<edges.size(); i++)
        drawLine(input, QColor(0, 0, 0), edges[i]);
    for(size_t i=0; i<points.size(); i++)
        drawPoint(input, QColor(0, 0, 0), Point2D(points[i].getX2D(), points[i].getY2D()));
    antiAliasing(input);
}

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    QWidget mainFrame;
    mainFrame.setFixedSize(1260, 700);

    QLabel* lbl = new QLabel(&mainFrame);
    QImage a(QSize(1260, 700), QImage::Format_ARGB32);

    // insert here
    process(a);
    // ***********

    lbl->setPixmap(QPixmap::fromImage(a));
    mainFrame.show();
    return app.exec();
}
