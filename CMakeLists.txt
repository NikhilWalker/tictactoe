cmake_minimum_required(VERSION 3.12)

project(TicTacToe)

add_executable(game "src/game.cpp" "src/engine/board.h" "src/engine/decision_tree.h" "src/engine/gui.h" "src/engine/header_files.h" "src/engine/logic.h")
target_compile_features(game PRIVATE cxx_std_11)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)