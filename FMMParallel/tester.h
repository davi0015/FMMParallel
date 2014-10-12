#include <stdlib.h>
#include <vector>

using namespace std;

void testPoint3d() {
    cout << "//////////////////////////////////////////////////////" << endl;
    cout << "Test for Point3d" << endl;

    cout << "Print Point3d" << endl;
    cout << "Test print: ";
    Point3d(1, 2.5, 3).print();
    cout << endl;
    cout << "//////////////////////////////////////////////////////"<< endl;
    cout << endl;
}

void testVector3d() {
    cout << "//////////////////////////////////////////////////////" << endl;
    cout << "Test for Vector3d" << endl << endl;
    
    cout << "Test constructor and print Vector3d" << endl;
    Point3d p1(1.4, 2.5, 3.0);
    Point3d p2(2.1, 5.3, 1.5);
    Vector3d(p1, p2).print();
    cout << endl << endl;

    cout << "Test getPositiveVector3d" << endl;
    Vector3d v1(-2.3, 4, -5.7);
    cout << "Initial vector: ";
    v1.print();
    cout << endl;
    cout << "After applying getPositiveVector3d:";
    v1.getPositiveVector3d().print();
    cout << endl;
    cout << "//////////////////////////////////////////////////////"<< endl;
    cout << endl;
}

void testBoundingBox() {
    cout << "//////////////////////////////////////////////////////" << endl;
    cout << "Test for BoundingBox" << endl << endl;

    cout << "Test constructor and print BoundingBox" << endl;
    Point3d p(1.2, 3.5, 4.7);
    Vector3d v(-2.5, 3.5, 2.6);
    BoundingBox bb(p, v);
    bb.print();
    cout << endl << endl;

    cout << "Test containPoint" << endl;
    Point3d pIn(0.0, 1.2, 2.5);
    Point3d pOut(10, 10, 10);
    cout << "Point: ";
    pIn.print();
    cout << ", is inside: " << bb.containPoint(pIn);
    cout << endl << "Point: ";
    pOut.print();
    cout << ", is inside: " << bb.containPoint(pOut);
    cout << endl << endl;

    cout << "Test intersectBB" << endl;
    Point3d p2(5, 5, 5);
    Vector3d v2(3, 3, 3);
    BoundingBox bb2(p2, v2);
    cout << "BB1: ";
    bb.print();
    cout << endl;
    cout << "BB2: ";
    bb2.print();
    cout << endl;
    cout << "is intersect: " << bb.intersectBB(bb2) << endl;
    Point3d p3(10, 10, 10);
    Vector3d v3(1, 1, 1);
    BoundingBox bb3(p3, v3);
    cout << "BB1: ";
    bb.print();
    cout << endl;
    cout << "BB3: ";
    bb3.print();
    cout << endl;
    cout <<"is intersect: " << bb.intersectBB(bb3) << endl;
    cout << "//////////////////////////////////////////////////////"<< endl;
    cout << endl;
}

Point3d getRandomPoint3d() {
    Point3d p(rand() / 777.0, rand() / 777.0, rand() / 777.0);
    return p;
}

void testPoint3dCollection() {
    cout << "//////////////////////////////////////////////////////" << endl;
    cout << "Test for Point3dCollection" << endl << endl;

    cout << "Test constructor and print Point3dCollection" << endl;
    vector<Point3d> pts;
    for(int i=0; i<10; i++) {
        pts.push_back(getRandomPoint3d());
    }
    Point3dCollection pointCollection(pts);
    pointCollection.print();
    cout << endl;
    pointCollection.getBoundingBox().print();
    cout << endl;
    cout << "//////////////////////////////////////////////////////"<< endl;
    cout << endl;
}

void testOctree() {
    cout << "//////////////////////////////////////////////////////" << endl;
    cout << "Test for Octree" << endl << endl;

    cout << "Test constructor and print Octree" << endl;
    vector<Point3d> pts;
    for(int i=0; i<100; i++) {
        pts.push_back(getRandomPoint3d());
    }
    Point3dCollection pointCollection(pts);
    pointCollection.print();
    cout << endl;
    pointCollection.getBoundingBox().print();
    cout << endl;
    Octree octree(pointCollection.getBoundingBox(), pts);
    cout << "Octree:" << endl;
    octree.print();
    cout << endl;
    cout << "//////////////////////////////////////////////////////"<< endl;
    cout << endl;
}

void testFunctions() {
    testPoint3d();
    testVector3d();
    testBoundingBox();
    testPoint3dCollection();
    testOctree();
}