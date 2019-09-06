
set(DBINTERFACE_SRCS
    DBConnection.hpp

    DBInterface.hpp
    DBInterface.cpp
)

# Declare the library
add_library(DBInterface_lib STATIC
    ${DBINTERFACE_SRCS}
)

# Link dependency
target_link_libraries(DBInterface_lib
  tasks_lib
  projects_lib
)

# Specify here the include directories exported by this library
target_include_directories(DBInterface_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)