cmake_minimum_required(VERSION 3.10)
project(individual_ass_parallel_processing)

set(CMAKE_CXX_STANDARD 20)

find_package(MPI REQUIRED)
include_directories(${MPI_CXX_INCLUDE_PATH})

# program 1
add_executable(program1 program1.cpp)
target_link_libraries(program1 ${MPI_CXX_LIBRARIES})

# program 2
add_executable(program2 program2.cpp)
target_link_libraries(program2 ${MPI_CXX_LIBRARIES})

# program 3
add_executable(program3 program3.cpp)
target_link_libraries(program3 ${MPI_CXX_LIBRARIES})

# program 4
add_executable(program4 program4.cpp)
target_link_libraries(program4 ${MPI_CXX_LIBRARIES})

# program 5
add_executable(program5 program5.cpp)
target_link_libraries(program5 ${MPI_CXX_LIBRARIES})

# program 6
add_executable(program6 program6.cpp)
target_link_libraries(program6 ${MPI_CXX_LIBRARIES})

# program 7
add_executable(program7 program7.cpp)
target_link_libraries(program7 ${MPI_CXX_LIBRARIES})

# program 8
add_executable(program8 program8.cpp)
target_link_libraries(program8 ${MPI_CXX_LIBRARIES})

# program 9
add_executable(program9 program9.cpp)
target_link_libraries(program9 ${MPI_CXX_LIBRARIES})

# program 10
add_executable(program10 program10.cpp)
target_link_libraries(program10 ${MPI_CXX_LIBRARIES})
