#include "engine.hpp"

double v1=0;
double v2=0;

void calculBase(double camera[]){
    double c1x = camera[3] - camera[0];
    double c1y = camera[4] - camera[1];
    double c1z = camera[5] - camera[2];

    v1=calculAngle(c1x, c1z);

    double b[2];
    cartRotate(c1x, c1z, v1, b);

    //double c2x=b[0];// inutile
    double c2y=c1y;
    double c2z=b[1];

    v2=calculAngle(c2z, c2y);
}

void calculPoint(double camera[], Point *p){
    bool euclidian = false;

    double focale = 0.6;
    double focaleE = 70.0;

    double b[2];

    double p1x = p->getX3D() - camera[0];
    double p1y = p->getY3D() - camera[1];
    double p1z = p->getZ3D() - camera[2];

    cartRotate(p1x, p1z, v1, b);

    double p2x = b[0];
    double p2y = p1y;
    double p2z = b[1];

    cartRotate(p2z, p2y, v2, b);

    double p3x = p2x;
    double p3y = b[1];
    double p3z = b[0];

    if(euclidian){
        p->set2D(p3x / focaleE, p3z / focaleE, calculLength(p1x,p1y,p1z));
        //p.setX2D(p3x/focaleE);
        //p.setY2D(p3z/focaleE);
    }else{
        p->set2D(calculAngleReal(p3x,p3y) / focale, calculAngleReal(p3z,p3y) / focale, calculLength(p1x,p1y,p1z));
        //p.setX2D(calculAngleReal(p3x,p3y)/focale);
        //p.setY2D(calculAngleReal(p3z,p3y)/focale);
    }
}

double calculAngle(double const& x, double const& y){
    double a = 0.0;

    if(x > 0.0 && y > 0.0)        a = std::atan(std::fabs(x) / std::fabs(y));
    else if(x > 0.0 && y < 0.0)   a = std::atan(std::fabs(y) / std::fabs(x)) + M_PI / 2.0;
    else if(x < 0.0 && y < 0.0)   a = std::atan(std::fabs(x) / std::fabs(y)) + M_PI;
    else if(x < 0.0 && y > 0.0)   a = std::atan(std::fabs(y) / std::fabs(x)) + 3.0 * M_PI / 2.0;
    else if (x == 0.0 && y > 0.0) a = 0.0;
    else if (x == 0.0 && y < 0.0) a = M_PI ;
    else if (x > 0.0 && y == 0.0) a = M_PI / 2.0;
    else if (x < 0.0 && y == 0.0) a = 3.0 * M_PI * 2.0;
    else a = 0.0;


    return a;
}

double calculAngleReal(double const& x, double const& y){
    double a = 0.0;
    if(x > 0.0 && y > 0.0)      a = std::atan(std::fabs(x) / std::fabs(y));
    else if (x > 0.0 && y<0.0)  a = std::atan(std::fabs(y) / std::fabs(x)) + M_PI / 2.0;
    else if (x < 0.0 && y<0.0)  a = - (std::atan(std::fabs(y) / std::fabs(x)) + M_PI / 2.0);
    else if (x < 0.0 && y>0.0)  a = - (std::atan(std::fabs(x) / std::fabs(y)));
    else if (x == 0.0 && y>0.0) a = 0.0;
    else if (x == 0.0 && y<0.0) a = M_PI;
    else if (x > 0.0 && y==0.0) a = M_PI / 2.0;
    else if (x < 0.0 && y==0.0) a= - (M_PI * 2.0);
    else a = 0.0;

    return a;
}

void cartRotate(double const& x, double const& y, double const& a, double b[]){
    double a2 = calculAngle(x, y);
    double l = calculLength(x, y);

    a2 -= a;

    b[0] = sin(a2) * l;
    b[1] = cos(a2) * l;
}


double calculLength(double const& x, double const& y){
    return sqrt(pow(fabs(x), 2.0) + pow(fabs(y), 2.0));
}

double calculLength(double const& x, double const & y,double const& z){
    return sqrt(pow(fabs(x), 2.0) + pow(fabs(calculLength(y, z)), 2.0));
}

void calculPolygon(double camera[], Polygon *p){
    double X1 = p->getP1().getX3D();
    double Y1 = p->getP1().getY3D();
    double Z1 = p->getP1().getZ3D();

    double X2 = p->getP2().getX3D();
    double Y2 = p->getP2().getY3D();
    double Z2 = p->getP2().getZ3D();

    double X3 = p->getP3().getX3D();
    double Y3 = p->getP3().getY3D();
    double Z3 = p->getP3().getZ3D();

    double U[3];// premier vecteur 1 vers 2
    U[0] = X2 - X1;
    U[1] = Y2 - Y1;
    U[2] = Z2 - Z1;

    double V[3];//  second vecteur 1 vers 3
    V[0] = X3 - X1;
    V[1] = Y3 - Y1;
    V[2] = Z3 - Z1;

    double N[3];// produit vectorielle
    N[0] = U[1] * V[2] - U[2] * V[1];
    N[1] = U[2] * V[0] - U[0] * V[2];
    N[2] = U[0] * V[1] - U[1] * V[0];

    double M[3];
    M[0] = X1 - camera[0];
    M[1] = Y1 - camera[1];
    M[2] = Z1 - camera[2];

    double P[3];
    P[0] = X1 + N[0];
    P[1] = Y1 + N[1];
    P[2] = Z1 + N[2];

    double O[3];
    O[0] = P[0] - camera[0];
    O[1] = P[1] - camera[1];
    O[2] = P[2] - camera[2];

    double l1 = calculLength(M[0], M[1], M[2]);
    double l2 = calculLength(N[0], N[1], N[2]);
    double l3 = calculLength(O[0], O[1], O[2]);

    double a1 = acos((pow(l1, 2.0) + pow(l2, 2.0) - pow(l3, 2.0)) / (2.0 * l1 * l2));

    if(a1 < M_PI / 2.0)
        p->setBackFaceResult(true);
    else
        p->setBackFaceResult(false);
}
