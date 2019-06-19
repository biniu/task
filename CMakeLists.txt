cmake_minimum_required(VERSION 2.8.9)
project (task)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(task ${SOURCES})
