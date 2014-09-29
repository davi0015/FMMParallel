#include <cmath>
#include <iostream>

using namespace std;

#pragma region Point3d
class Vector3d;
class Point3d {
    double x_, y_, z_;

public:
    //Constructor
    Point3d();
    Point3d(double x, double y, double z);

    //Get values
    double getX();
    double getY();
    double getZ();

    //Operation
    Point3d shift(Vector3d& v);

    //Print
    void print();
};
#pragma endregion

#pragma region Vector3d
class Vector3d {
    double x_, y_, z_;

public:
    //Constructor
    Vector3d();
    Vector3d(double x, double y, double z);
    Vector3d(Point3d& p1, Point3d& p2);

    //Get values
    double getX();
    double getY();
    double getZ();
    Vector3d getPositiveVector3d();

    //Print
    void print();
};
#pragma endregion

#pragma region BoundingBox
class BoundingBox {
    Point3d center_;
    Vector3d halfDim_;

public:
    //Constructor
    BoundingBox();
    BoundingBox(Point3d center, Vector3d halfDim);

    void print();
};
#pragma endregion

#pragma region OperatorOverride

#pragma endregion