
set(PROJECT_SRCS
    ProjectGeneral.hpp
    ProjectGeneral.cpp
)

# Declare the library
add_library(projects_lib STATIC
    ${PROJECT_SRCS}
)

# Link dependency
target_link_libraries(projects_lib
    tasks_lib
)

# Specify here the include directories exported by this library
target_include_directories(projects_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)