#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <mpi.h>
#include "global.h"
#include "octree.h"
#include "tester.h"

using namespace std;

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
    testFunctions();
    return 0;
};