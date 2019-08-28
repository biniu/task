
add_subdirectory(DBInterface)
# add_subdirectory(sample_lib_2)
add_executable (main main.cpp)
target_link_libraries (main
  DBInterface_lib
  # SAMPLE_LIB_2
  )