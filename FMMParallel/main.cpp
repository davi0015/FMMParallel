#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <mpi.h>
#include "global.h"
#include "octree.h"
#include "tester.h"

using namespace std;

void testOctreeTimer() {
    cout << "//////////////////////////////////////////////////////" << endl;
    cout << "Test for Octree" << endl << endl;

    //Generate random points
    clock_t begin_time = clock();
    vector<Point3d> pts;
    for(int i=0; i<10000000; i++) {
        pts.push_back(getRandomPoint3d());
    }
    Point3dCollection pointCollection(pts);
    clock_t mid_time = clock();

    //Octree construction
    Octree octree(pointCollection.getBoundingBox(), pts);
    clock_t end_time = clock();
    
    //Timer output
    cout << "Clock per sec: " << CLOCKS_PER_SEC << endl;
    cout << "Begin Time: " << (float) begin_time << endl;
    cout << "Mid Time: " << (float) mid_time << endl;
    cout << "End Time: " << (float) end_time << endl;
    cout << "Point Generation: " << (float) (mid_time - begin_time) / CLOCKS_PER_SEC << endl;
    cout << "Octree Creation: " << (float) (end_time - mid_time) / CLOCKS_PER_SEC << endl;
    cout << "Total execution: " << (float) (end_time - begin_time) / CLOCKS_PER_SEC << endl;
    cout << "//////////////////////////////////////////////////////"<< endl;
    cout << endl;
}

int main(int argc, char *argv[])
{
    //Sample of MPI
    /*int rank, nproc;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);
    printf("hellow rold from MPI process %d of %d\n", rank, nproc);
    MPI_Finalize();*/
    srand((int)time(NULL));
    //testFunctions();
    testOctreeTimer();
    return 0;
};