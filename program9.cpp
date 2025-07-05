//
// Created by harith on 7/5/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char** argv) {
    // Declare variables for process rank, local value, and global minimum
    int rank, value, global_min;

    // Initialize the MPI environment
    MPI_Init(&argc, &argv);
    // Get the rank (ID) of the current process
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Each process generates a random value (0-99) and adds its rank
    value = rand() % 100 + rank;

    // Find the minimum value among all processes and store it in global_min (all processes get the result)
    MPI_Allreduce(&value, &global_min, 1, MPI_INT, MPI_MIN, MPI_COMM_WORLD);
    printf("Process %d had value = %d, Global Min = %d\n", rank, value, global_min);

    // Finalize the MPI environment
    MPI_Finalize();
    return 0;
}

