# CMakeList.txt : CMake project for Scientific Computing, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

include_directories(
	${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

file(GLOB all_SRCS
	${PROJECT_SOURCE_DIR}/include/*.h
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

# Add source to this project's executable.
add_executable (Scientific_Computing "ScientificComputing.cpp" "ScientificComputing.h" ${all_SRCS})

# TODO: Add tests and install targets if needed.
