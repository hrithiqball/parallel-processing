//
// Created by harith on 7/5/25.
//

#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    // Declare variables for process rank and prefix sum result
    int rank, prefix_sum;

    // Initialize the MPI environment
    MPI_Init(&argc, &argv);
    // Get the rank (ID) of the current process
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Perform a prefix sum (inclusive scan) of the ranks across all processes
    MPI_Scan(&rank, &prefix_sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    printf("Rank %d: Prefix sum = %d\n", rank, prefix_sum);

    // Finalize the MPI environment
    MPI_Finalize();
    return 0;
}
