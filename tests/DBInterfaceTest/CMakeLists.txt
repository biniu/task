
file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(DBInterfaceTest ${SRCS})

TARGET_LINK_LIBRARIES(
    DBInterfaceTest
    DBInterface_lib

    libgtest
)

# target_link_options(DBInterface_lib PRIVATE -lsqlite3)

add_test(NAME DBInterfaceTest
         COMMAND DBInterfaceTest)