cmake_minimum_required(VERSION 3.21)
project(Grid)

set(CMAKE_CXX_STANDARD 14)
add_executable(grid grid_traversal.cpp ../string/anagrams_ordering.cpp)
add_executable(mr matrix_reset.cpp)
add_executable(dfs_back_track dfs_with_backtrack.cpp ../design/trie_dfs.cpp)
add_executable(countP count_paths.cpp ../dp/buy_sell/buy_sell_2.cpp)