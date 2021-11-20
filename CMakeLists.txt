cmake_minimum_required (VERSION 3.14)

project("ScientificComputing")

include_directories(
	${PROJECT_SOURCE_DIR}/scientific_computing
)

file(GLOB all_SRCS
	${PROJECT_SOURCE_DIR}/scientific_computing/*.h
    ${PROJECT_SOURCE_DIR}/scientific_computing/*.cpp
    ${PROJECT_SOURCE_DIR}/scientific_computing/*.hpp
)

include(FetchContent)
FetchContent_Declare(
        linear_algebra
        GIT_REPOSITORY "https://github.com/dhern023/linear_algebra.git"
        GIT_TAG main
)

include(FetchContent)
FetchContent_Declare(
        numerical_solvers
        GIT_REPOSITORY "https://github.com/dhern023/numerical_solvers.git"
        GIT_TAG main
)

FetchContent_MakeAvailable(
	linear_algebra
	numerical_solvers) # add other fetched names here

add_executable(${PROJECT_NAME} "ScientificComputing.cpp" "ScientificComputing.h" ${all_SRCS})
target_link_libraries(${PROJECT_NAME}
	linear_algebra
	numerical_solvers) # add other fetched names here
target_include_directories(${PROJECT_NAME} 
	PUBLIC ${linear_algebra_SOURCE_DIR} 
	${numerical_solvers_SOURCE_DIR})