cmake_minimum_required(VERSION 3.21)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

add_executable(stocks stocks.cpp)
add_executable(triplets triplets.cpp)
add_executable(mi merge_intervals.cpp)
add_executable(cg coin_change.cpp dp/steps.cpp calc1.cpp)
add_executable(dup duplicate.cpp)

add_executable( tree makeTree.cpp)
add_executable(pft profit.cpp)
add_executable(peak peak_element.cpp)
add_executable(TS
        task_scheduling.cpp)
add_executable(ns no_to_string.cpp)
add_executable(cacl1 calc1.cpp sliding_window/max_k_window.cpp)