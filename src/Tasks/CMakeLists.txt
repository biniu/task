
set(TASK_SRCS
    TaskGeneral.hpp
    TaskGeneral.cpp
)

# Declare the library
add_library(tasks_lib STATIC
    ${TASK_SRCS}
)

# Link dependency
# target_link_libraries(DBINTERFACE
#     SAMPLE_LIB_2
# )

# Specify here the include directories exported by this library
target_include_directories(tasks_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)