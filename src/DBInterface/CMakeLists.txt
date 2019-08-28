
set(DBINTERFACE_SRCS
    DBInterface.hpp
    DBInterface.cpp
)

# Declare the library
add_library(DBInterface_lib STATIC
    ${DBINTERFACE_SRCS}
)

target_link_options(DBInterface_lib PUBLIC -lsqlite3)

# Link dependency
# target_link_libraries(DBINTERFACE
#     SAMPLE_LIB_2
# )

# Specify here the include directories exported by this library
target_include_directories(DBInterface_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)