<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/en/thumb/7/74/Universiti_Teknologi_MARA_logo.svg/250px-Universiti_Teknologi_MARA_logo.svg.png" alt="UiTM Logo" width="200"/>
</p>

# Parallel Processing Individual Assignment (CSC580)

Author: Muhammad Harith Iqbal bin Mohd Hanizun

This project contains multiple C++ programs (program1.cpp, program2.cpp, ..., program10.cpp) designed for parallel processing tasks, using MPI (Message Passing Interface).

## Project Structure

- `program1.cpp` to `program10.cpp`: Source files for different parallel processing programs.
- `CMakeLists.txt`: CMake build configuration.
- `cmake-build-debug/`: Build output directory (may vary depending on your IDE or build setup).

## Prerequisites

- **C++ Compiler** (e.g., g++, clang++)
- **CMake** (for building the project)
- **MPI Implementation** (e.g., OpenMPI or MPICH)

### Installing MPI (OpenMPI Example)

On Ubuntu/Debian:

```sh
sudo apt update
sudo apt install -y openmpi-bin libopenmpi-dev
```

## Building the Project

1. Create a build directory (if not already present):
   ```sh
   mkdir -p cmake-build-debug
   cd cmake-build-debug
   ```
2. Run CMake to configure the project:
   ```sh
   cmake ..
   ```
3. Build the programs:
   ```sh
   make
   ```
   This will generate executables (e.g., `program1`, `program2`, ..., `program10`) in the `cmake-build-debug` directory.

## Running the Programs with MPI

Use `mpirun` (or `mpiexec`) to run any of the programs. For example, to run `program1` with 4 processes:

```sh
mpirun -np 4 ./program1
```

Replace `program1` with the desired program name and adjust the number of processes (`-np 4`) as needed.

> **Note:** Always run the executables from the build directory (e.g., `cmake-build-debug`).

## Example

```sh
cd cmake-build-debug
mpirun -np 4 ./program2
```

## Troubleshooting

- Ensure MPI is installed and available in your PATH.
- If you encounter build errors, verify that CMake and your compiler are installed correctly.

---
