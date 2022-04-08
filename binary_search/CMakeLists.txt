cmake_minimum_required(VERSION 3.21)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)
add_executable( sr search_range.cpp)
add_executable(bs binary_search.cpp ../merge_intervals/min_rooms.cpp)
add_executable(bs2 binary_search2.cpp)
add_executable(bst bst.cpp)