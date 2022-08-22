cmake_minimum_required(VERSION 3.23)
project(binary_search)
set(CMAKE_CXX_STANDARD 14)

add_executable( sr search_range.cpp)
add_executable(bs binary_search.cpp ../merge_intervals/min_rooms.cpp first_occurence.cpp first_occurence.h)
add_executable(bs2 binary_search2.cpp)
add_executable(bst bst.cpp)
add_executable(bs_first_oc first_occurence.cpp)