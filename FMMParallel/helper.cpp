#include "helper.h"

#pragma region Point3d
Point3d::Point3d() {
    x_ = 0; y_ = 0; z_ = 0;
}

Point3d::Point3d(double x, double y, double z) {
    x_ = x; y_ = y; z_ = z;
}

double Point3d::getX() {
    return x_;
}

double Point3d::getY() {
    return y_;
}

double Point3d::getZ() {
    return z_;
}

Point3d Point3d::shift(Vector3d& v) {
    return Point3d(x_ + v.getX(), y_ + v.getY(), z_ + v.getZ());
}

void Point3d::print() {
    cout << "Point3d(" << x_ << ", " << y_ << ", " << z_ << ")";
}
#pragma endregion

#pragma region Vector3d
Vector3d::Vector3d() {
    x_ = 0; y_ = 0; z_ = 0;
}

Vector3d::Vector3d(double x, double y, double z) {
    x_ = x; y_ = y; z_ = z;
}

Vector3d::Vector3d(Point3d& p1, Point3d& p2) {
    x_ = p2.getX() - p1.getX();
    y_ = p2.getY() - p1.getY();
    z_ = p2.getZ() - p1.getZ();
}

double Vector3d::getX() {
    return x_;
}

double Vector3d::getY() {
    return y_;
}

double Vector3d::getZ() {
    return z_;
}

Vector3d Vector3d::getPositiveVector3d() {
    return Vector3d(x_ >= 0 ? x_ : -x_,
        y_ >= 0 ? y_ : -y_,
        z_ >= 0 ? z_ : -z_);
}

void Vector3d::print() {
    cout << "Vector3d(" << x_ << ", " << y_ << ", " << z_ << ")";
}

#pragma endregion

#pragma region BoundingBox
BoundingBox::BoundingBox() {
    center_ = Point3d();
    halfDim_ = Vector3d();
}

BoundingBox::BoundingBox(Point3d center, Vector3d halfDim) {
    center_ = center;
    halfDim_ = halfDim.getPositiveVector3d();
}

void BoundingBox::print() {
    //cout << "BoundingBox(x:["
}
#pragma endregion