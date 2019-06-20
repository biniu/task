cmake_minimum_required(VERSION 2.8.9)
project (task)

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Weverything")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wno-c++98-compat")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wc++2a-extensions")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
set(BOOST_REQUESTED_VERSION 1.61)
find_package(Boost COMPONENTS system program_options)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(task ${SOURCES})
