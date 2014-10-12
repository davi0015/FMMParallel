#include <iostream>
#include <vector>
#include "helper.h"

using namespace std;

class Octree {
    bool isLeaf_;
    int level_;
    BoundingBox boundingBox_;
    vector<Point3d> points_;
    vector<Octree*> nodes_; // +++, ++-, +-+, +--, -++, -+-, --+, ---
public:
    Octree();
    Octree(BoundingBox& bb);
    Octree(BoundingBox& bb, vector<Point3d>& pts);
    Octree(BoundingBox& bb, int level);

    void setBoundingBox(BoundingBox& bb);
    
    // Operations on Octree
    bool insertPoint3d(Point3d& p);
    void subdivideOctree();

    void print();
};