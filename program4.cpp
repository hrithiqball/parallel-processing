//
// Created by harith on 7/5/25.
//

#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    // Initialize two arrays for the dot product
    int a[] = {1, 2, 3, 4};
    int b[] = {4, 3, 2, 1};
    // Declare variables for process rank, size, local and global dot product, and local elements
    int rank, size, local_dot, global_dot;
    int local_a, local_b;

    // Initialize the MPI environment
    MPI_Init(&argc, &argv);
    // Get the rank (ID) of the current process
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Each process picks its corresponding element from both arrays
    local_a = a[rank];
    local_b = b[rank];
    // Compute the local dot product (product of corresponding elements)
    local_dot = local_a * local_b;

    // Reduce all local dot products to a global sum at the root process (rank 0)
    MPI_Reduce(&local_dot, &global_dot, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if(rank == 0) {
        printf("Dot product = %d\n", global_dot);
    }

    // Finalize the MPI environment
    MPI_Finalize();
    return 0;
}
