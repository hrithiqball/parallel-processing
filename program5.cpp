//
// Created by harith on 7/5/25.
//

#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    // Declare variables for process rank, total number of processes, and the message value
    int rank, size, msg = 10;

    // Initialize the MPI environment
    MPI_Init(&argc, &argv);
    // Get the rank (ID) of the current process
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    // Get the total number of processes
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(rank == 0) {
        // Process 0 sends the initial message to process 1
        MPI_Send(&msg, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        // Process 0 waits to receive the final message from the last process
        MPI_Recv(&msg, 1, MPI_INT, size - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        // Print the final received message
        printf("Process 0 received final message = %d\n", msg);
    } else {
        // All other processes receive a message from the previous process
        MPI_Recv(&msg, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        // Increment the message value
        msg++;
        // Send the updated message to the next process (wraps around to 0)
        MPI_Send(&msg, 1, MPI_INT, (rank + 1) % size, 0, MPI_COMM_WORLD);
    }

    // Finalize the MPI environment
    MPI_Finalize();
    return 0;
}
