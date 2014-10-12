#include "helper.h"
#include <cassert>

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

Vector3d Vector3d::operator-() {
    return Vector3d(-x_, -y_, -z_);
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

BoundingBox::BoundingBox(Point3d& center, Vector3d& halfDim) {
    center_ = center;
    halfDim_ = halfDim.getPositiveVector3d();
}

Point3d BoundingBox::getCenter() {
    return center_;
}

Vector3d BoundingBox::getHalfDim() {
    return halfDim_;
}

bool BoundingBox::containPoint(Point3d& p) {
    Point3d p1 = center_.shift(-halfDim_);
    Point3d p2 = center_.shift(halfDim_);
    if(p1.getX() < p.getX() && p2.getX() >= p2.getX() &&
        p1.getY() < p.getY() && p2.getY() >= p.getY() &&
        p1.getZ() < p.getZ() && p2.getZ() >= p.getZ()) {
            return true;
    }
    return false;
}

bool BoundingBox::intersectBB(BoundingBox& bb) {
    Point3d p1 = center_.shift(-halfDim_);
    Point3d p2 = center_.shift(halfDim_);
    Point3d p1Ext = bb.getCenter().shift(-bb.getHalfDim());
    Point3d p2Ext = bb.getCenter().shift(bb.getHalfDim());

    if((p1.getX() < p2Ext.getX() && p2.getX() > p1Ext.getX() && p1.getY() < p2Ext.getY() && p2.getY() > p1Ext.getY() &&
        p1.getZ() < p2Ext.getZ() && p2.getZ() > p1Ext.getZ()) ||
        (p1Ext.getX() < p2.getX() && p2Ext.getX() > p1.getX() && p1Ext.getY() < p2.getY() && p2Ext.getX() > p1.getY() &&
        p1Ext.getZ() < p2.getZ() && p2Ext.getZ() > p1.getZ())) {
            return true;
    }
    return false;
}

void BoundingBox::print() {
    Point3d p1 = center_.shift(-halfDim_);
    Point3d p2 = center_.shift(halfDim_);
    cout << "BoundingBox(x:[" << p1.getX() << ", " << p2.getX() << "], y:[" << p1.getY() << ", " << p2.getY() << "], z:[" <<
        p1.getZ() << ", " << p2.getZ() << "])";
}
#pragma endregion

#pragma region Point3dCollection
Point3dCollection::Point3dCollection() {
}

Point3dCollection::Point3dCollection(vector<Point3d>& points) {
    points_ = points;
}

BoundingBox Point3dCollection::getBoundingBox() {
    assert(points_.size() > 0);
    if (points_.size() > 0) {
        double xmin = points_[0].getX();
        double xmax = xmin;
        double ymin = points_[0].getY();
        double ymax = ymin;
        double zmin = points_[0].getZ();
        double zmax = zmin;

        for(int i=1; i<(int)points_.size(); i++) {
            if(xmin > points_[i].getX()) {
                xmin = points_[i].getX();
            }
            else if(xmax < points_[i].getX()) {
                xmax = points_[i].getX();
            }
            if(ymin > points_[i].getY()) {
                ymin = points_[i].getY();
            }
            else if(ymax < points_[i].getY()) {
                ymax = points_[i].getY();
            }
            if(zmin > points_[i].getZ()) {
                zmin = points_[i].getZ();
            }
            else if(zmax < points_[i].getZ()) {
                zmax = points_[i].getZ();
            }
        }

        double offsetX = (xmax - xmin) * 1e-4;
        double offsetY = (ymax - ymin) * 1e-4;
        double offsetZ = (zmax - zmin) * 1e-4;

        xmin -= offsetX;
        ymin -= offsetY;
        zmin -= offsetZ;

        Point3d p((xmin + xmax) / 2, (ymin + ymax) / 2, (zmin + zmax) / 2);
        Point3d pcorner(xmax + offsetX, ymax + offsetY, zmax + offsetZ);
        Vector3d v(p, pcorner);
        return BoundingBox(p, v);
    }
    else {
        return BoundingBox();
    }
}

void Point3dCollection::print() {
    cout << "Point3dCollection({";
    for(int i=0; i<(int)points_.size(); i++) {
        points_[i].print();
        if(i < (int)points_.size() - 1) {
            cout << ", ";
        }
    }
    cout << "})";
}
#pragma endregion

#pragma region Operator
Vector3d operator*(double f, Vector3d& v) {
    return Vector3d(f * v.getX(), f * v.getY(), f * v.getZ());
}

Vector3d operator*(Vector3d& v, double f) {
    return Vector3d(f * v.getX(), f * v.getY(), f * v.getZ());
}