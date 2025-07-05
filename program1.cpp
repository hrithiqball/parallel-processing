//
// Created by harith on 7/5/25.
//

#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    // Declare variables for process rank, total number of processes, and array size
    int rank, size, n = 4;
    // Initialize an array of 4 integers
    int data[] = {1, 2, 3, 4};
    // Variables to hold local and total sum
    int local_sum = 0, total_sum = 0;

    // Initialize the MPI environment
    MPI_Init(&argc, &argv);
    // Get the rank (ID) of the current process
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    // Get the total number of processes
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Each process picks its corresponding element from the data array
    int local_data = data[rank];
    // Assign the local data to local_sum
    local_sum = local_data;

    // Reduce all local sums to a total sum at the root process (rank 0)
    MPI_Reduce(&local_sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if(rank == 0) {
        printf("Total sum is %d\n", total_sum);
    }

    // Finalize the MPI environment
    MPI_Finalize();
    return 0;
}
