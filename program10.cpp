//
// Created by harith on 7/5/25.
//

#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    // Declare and initialize a 4x4 matrix
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    // Declare variables for process rank, size, and row sum
    int rank, size, sum = 0;

    // Initialize the MPI environment
    MPI_Init(&argc, &argv);
    // Get the rank (ID) of the current process
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Each process sums the elements of its corresponding row
    for(int j = 0; j < 4; j++) {
        sum += matrix[rank][j];
    }

    printf("Process %d: Row sum = %d\n", rank, sum);

    // Finalize the MPI environment
    MPI_Finalize();
    return 0;
}

