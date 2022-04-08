cmake_minimum_required(VERSION 3.21)
project(leetcode_tree_graph)

set(CMAKE_CXX_STANDARD 14)
add_executable(zigzag zigzag.cpp TreeNode.h)
add_executable(inors inorder_suc.cpp ../grid/dfs_with_backtrack.cpp)
add_executable(wl word_lader.cpp)