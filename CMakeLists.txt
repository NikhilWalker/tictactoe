cmake_minimum_required(VERSION 3.12)

project(TicTacToe)

add_executable(game game.cpp)
target_compile_features(game PRIVATE cxx_std_11)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)