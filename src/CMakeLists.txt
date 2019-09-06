
# find_package(Boost REQUIRED)

set(Boost_INCLUDE_DIR /usr/include/)
set(Boost_LIBRARY_DIR /usr/lib)

find_package(Boost COMPONENTS system serialization REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

add_subdirectory(Tasks)
add_subdirectory(Projects)
add_subdirectory(DBInterface)

add_executable (main main.cpp)

target_link_libraries (main
  tasks_lib
  projects_lib
  DBInterface_lib

  ${Boost_LIBRARIES}
  )