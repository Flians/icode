cmake_minimum_required(VERSION 3.0.0)
project(fp VERSION 0.1.0)

message(STATUS "Build type: " ${CMAKE_BUILD_TYPE})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0 -g -ggdb")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3")
endif()

add_subdirectory(src)

add_executable(hw2 ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(hw2 PUBLIC
    fp
)

