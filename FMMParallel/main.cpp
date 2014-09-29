#include <iostream>
#include <mpi.h>
#include "helper.h"
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
    testFunctions();
    return 0;
};