cmake_minimum_required(VERSION 2.8.9)
project (task)

# set waring flags
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Weverything")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wno-c++98-compat")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wc++2a-extensions")


# TODO(biniu) - change to find package
#             - and download if not installed
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -l sqlite3")


include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(task ${SOURCES})

