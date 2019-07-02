cmake_minimum_required(VERSION 3.14.5)
project (task)

# set waring flags
# SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Weverything")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wno-c++98-compat")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wc++2a-extensions")



include_directories(include)

file(GLOB SOURCES "src/*.cpp")
file(GLOB TEST_SOURCES "tests/*.cpp")

file(GLOB ALL_SOURCES "src/*.cpp" "tests/*.cpp" "include/*.hpp")

include(${CMAKE_CURRENT_SOURCE_DIR}/cmakes/cppcheck.cmake)

add_executable(task ${SOURCES})

# TODO(biniu) - change to find package
#             - and download if not installed
#             - maybe use target_link_libraries
target_link_options(task PRIVATE -lsqlite3)


# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
# if (CMAKE_VERSION VERSION_LESS 2.8.11)
include_directories("${gtest_SOURCE_DIR}/include")
include_directories("${gmock_SOURCE_DIR}/include")
# endif()

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(taskTest ${TEST_SOURCES})
target_link_libraries(taskTest gtest_main)
add_test(NAME taskTest COMMAND taskTest)
