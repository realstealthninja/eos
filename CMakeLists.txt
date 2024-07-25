cmake_minimum_required(VERSION 3.26)

project(Evolution_of_Swarming)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
add_compile_options(-Wall -Wextra -Wpedantic -O3)


add_executable(${PROJECT_NAME} src/main.cpp src/hmm.cpp src/helper.cpp src/game.cpp src/agent.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE includes/)