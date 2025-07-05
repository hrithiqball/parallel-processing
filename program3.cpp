//
// Created by harith on 7/5/25.
//

#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    // Declare variables for process rank and total number of processes
    int rank, size;
    // Initialize an array of 4 integers (used by root process)
    int data[4] = {10, 20, 30, 40};
    // Variable to receive scattered data
    int recv_data;

    // Initialize the MPI environment
    MPI_Init(&argc, &argv);
    // Get the rank (ID) of the current process
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    // Get the total number of processes
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Scatter one element of data array to each process
    MPI_Scatter(data, 1, MPI_INT, &recv_data, 1, MPI_INT, 0, MPI_COMM_WORLD);
    // Each process doubles its received value
    recv_data *= 2;

    // Gather the doubled values from all processes back to the root process
    MPI_Gather(&recv_data, 1, MPI_INT, data, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if(rank == 0) {
        printf("Gathered result: ");
        for(int i = 0; i < size; i++)
            printf("%d ", data[i]);
        printf("\n");
    }

    // Finalize the MPI environment
    MPI_Finalize();
    return 0;
}
