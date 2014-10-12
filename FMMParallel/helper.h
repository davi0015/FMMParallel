#include <cmath>
#include <iostream>
#include <vector>

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
    
    //Operator overload
    Vector3d operator-();

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
    BoundingBox(Point3d& center, Vector3d& halfDim);

    //Get values
    Point3d getCenter();
    Vector3d getHalfDim();

    //Methods
    bool containPoint(Point3d& p); //if Point intersects negative bound will be considered as false;
    bool intersectBB(BoundingBox& bb);

    void print();
};
#pragma endregion

#pragma region Point3dCollection
class Point3dCollection {
    vector<Point3d> points_;

public:
    Point3dCollection();
    Point3dCollection(vector<Point3d>& points);

    // Operations on Point3dCollection
    BoundingBox getBoundingBox();

    void print();
};
#pragma endregion

#pragma region Operator
Vector3d operator*(double f, Vector3d& v);
Vector3d operator*(Vector3d& v, double f);
#pragma endregion