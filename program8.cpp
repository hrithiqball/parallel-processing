//
// Created by harith on 7/5/25.
//

#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    // Declare variables for process rank, even/odd values, and their sums
    int rank, even = 0, odd = 0, even_sum, odd_sum;

    // Initialize the MPI environment
    MPI_Init(&argc, &argv);
    // Get the rank (ID) of the current process
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // If the rank is even, set 'even' to rank; otherwise, set 'odd' to rank
    if(rank % 2 == 0) even = rank;
    else odd = rank;

    // Reduce all even values to their sum at the root process (rank 0)
    MPI_Reduce(&even, &even_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    // Reduce all odd values to their sum at the root process (rank 0)
    MPI_Reduce(&odd, &odd_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if(rank == 0) {
        printf("Sum of even ranks = %d\n", even_sum);
        printf("Sum of odd ranks = %d\n", odd_sum);
    }

    // Finalize the MPI environment
    MPI_Finalize();
    return 0;
}
