# CMakeList.txt : CMake project for Scientific Computing, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("ScientificComputing")

include_directories(
	${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

file(GLOB all_SRCS
	${PROJECT_SOURCE_DIR}/include/*.h
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

add_executable(ScientificComputing "ScientificComputing.cpp" "ScientificComputing.h" ${all_SRCS})

link_directories()

find_package(linear_algebra)
if (LINEAR_ALGEBRA_FOUND)
  include_directories(${LINEAR_ALGEBRA_INCLUDE_DIRS})
  target_link_libraries (ScientificComputing ${LINEAR_ALGEBRA_LIBRARIES})
endif (LINEAR_ALGEBRA_FOUND)

# TODO: Add tests and install targets if needed.
