cmake_minimum_required (VERSION 3.11)

project("ScientificComputing")

include_directories(
	${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

file(GLOB all_SRCS
	${PROJECT_SOURCE_DIR}/include/*.h
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

include(FetchContent)
FetchContent_Declare(
        linear_algebra
        GIT_REPOSITORY "https://github.com/dhern023/linear_algebra"
        GIT_TAG main
)

FetchContent_MakeAvailable(linear_algebra) # add other fetched names here

add_executable(${PROJECT_NAME} "ScientificComputing.cpp" "ScientificComputing.h" ${all_SRCS})
target_link_libraries(${PROJECT_NAME} linear_algebra) # add other fetched names here