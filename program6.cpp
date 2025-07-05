//
// Created by harith on 7/5/25.
//

#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    // Declare variables for process rank, total number of processes, and the local number
    int rank, size, number;
    // Variable to store the global maximum
    int global_max;

    // Initialize the MPI environment
    MPI_Init(&argc, &argv);
    // Get the rank (ID) of the current process
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Each process calculates its number as (rank + 1) * 3
    number = (rank + 1) * 3;

    // Reduce all numbers to find the maximum at the root process (rank 0)
    MPI_Reduce(&number, &global_max, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

    if(rank == 0) {
        printf("Maximum value is %d\n", global_max);
    }

    // Finalize the MPI environment
    MPI_Finalize();
    return 0;
}
