//
// Created by harith on 7/5/25.
//

#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    // Declare variables for process rank, total number of processes, and the value to broadcast
    int rank, size, value;

    // Initialize the MPI environment
    MPI_Init(&argc, &argv);
    // Get the rank (ID) of the current process
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Only the root process (rank 0) sets the value
    if(rank == 0) {
        value = 42;
    }

    // Broadcast the value from the root process to all other processes
    MPI_Bcast(&value, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Process %d received value = %d\n", rank, value);

    // Finalize the MPI environment
    MPI_Finalize();
    return 0;
}
