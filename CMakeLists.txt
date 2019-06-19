cmake_minimum_required(VERSION 2.8.9)
project (task)

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Weverything")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wno-c++98-compat")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wc++2a-extensions")


include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(task ${SOURCES})
