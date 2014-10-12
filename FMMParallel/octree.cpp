#include "octree.h"
#include "global.h"

Octree::Octree() {
    isLeaf_ = true;
    level_ = 1;
}

Octree::Octree(BoundingBox& bb) {
    isLeaf_ = true;
    level_ = 1;
    boundingBox_ = bb;
}

Octree::Octree(BoundingBox& bb, vector<Point3d>& pts) {
    isLeaf_ = true;
    level_ = 1;
    boundingBox_ = bb;
    for(int i=0; i<(int)pts.size(); i++) {
        insertPoint3d(pts[i]);
    }
}

Octree::Octree(BoundingBox& bb, int level) {
    isLeaf_ = true;
    level_ = level;
    boundingBox_ = bb;
}

void Octree::setBoundingBox(BoundingBox& bb) {
    boundingBox_ = bb;
}

bool Octree::insertPoint3d(Point3d& p) {
    if (!boundingBox_.containPoint(p))
        return false;
    if (isLeaf_) {
        if((int)points_.size() < OT_POINTS_CAPACITY) {
            points_.push_back(p);
            return true;
        }
        else {
            subdivideOctree();
            isLeaf_ = false;
            for(int i=0; i<(int)points_.size(); i++) {
                for(int j=0; j<8; j++) {
                    if(nodes_[j]->insertPoint3d(points_[i])) {
                        break;
                    }
                }
            }
            points_.clear();
        }
    }

    for(int i=0; i<8; i++) {
        nodes_[i]->insertPoint3d(p);
    }

    //if not successful, which is unlikely to occur
    return false;
}

void Octree::subdivideOctree() {
    nodes_.resize(8);

    Vector3d vShift = 0.5 * boundingBox_.getHalfDim();

    // +++
    Point3d p0 = boundingBox_.getCenter().shift(vShift);
    nodes_[0] = new Octree(BoundingBox(p0, vShift), level_ + 1);

    // ++-
    Point3d p1 = boundingBox_.getCenter().shift(Vector3d(vShift.getX(), vShift.getY(), -vShift.getZ()));
    nodes_[1] = new Octree(BoundingBox(p1, vShift), level_ + 1);

    // +-+
    Point3d p2 = boundingBox_.getCenter().shift(Vector3d(vShift.getX(), -vShift.getY(), vShift.getZ()));
    nodes_[2] = new Octree(BoundingBox(p2, vShift), level_ + 1);

    // +--
    Point3d p3 = boundingBox_.getCenter().shift(Vector3d(vShift.getX(), -vShift.getY(), -vShift.getZ()));
    nodes_[3] = new Octree(BoundingBox(p3, vShift), level_ + 1);

    // -++
    Point3d p4 = boundingBox_.getCenter().shift(Vector3d(-vShift.getX(), vShift.getY(), vShift.getZ()));
    nodes_[4] = new Octree(BoundingBox(p4, vShift), level_ + 1);

    // -+-
    Point3d p5 = boundingBox_.getCenter().shift(Vector3d(-vShift.getX(), vShift.getY(), -vShift.getZ()));
    nodes_[5] = new Octree(BoundingBox(p5, vShift), level_ + 1);

    // --+
    Point3d p6 = boundingBox_.getCenter().shift(Vector3d(-vShift.getX(), -vShift.getY(), vShift.getZ()));
    nodes_[6] = new Octree(BoundingBox(p6, vShift), level_ + 1);

    // ---
    Point3d p7 = boundingBox_.getCenter().shift(-vShift);
    nodes_[7] = new Octree(BoundingBox(p7, vShift), level_ + 1);
}

void Octree::print() {
    for (int i=1; i<level_; i++) {
        cout << "  ";
    }
    cout << "(Octree level " << level_ << ": ";
    if(isLeaf_) {
        for(int i=0; i<(int)points_.size(); i++) {
            points_[i].print();
            if(i < (int)points_.size() - 1) {
                cout << ", ";
            }
        }
    }
    else if((int)nodes_.size() > 0) {
        cout << endl;
        for(int i=0; i<(int)nodes_.size(); i++) {
            nodes_[i]->print();
            cout << endl;
        }
    }
    cout << ")";
}