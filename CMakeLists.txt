cmake_minimum_required(VERSION 3.9)
project(queue)

set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_NAME "queue")

add_executable(${EXECUTABLE_NAME} src/main.cpp src/Simulation.cpp src/Logger.cpp)